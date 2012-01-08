#include "Canvas3D.h"

#include <Settings.h>
#include <typeinfo>
#include <Camera.h>
#include <OrbitingCamera.h>
#include <OpenGLScene.h>

#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

#include <QFile>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QGLShader>
#include <iostream>
#include <QFileDialog>
#include <QGLFramebufferObject>
#include <QGLShaderProgram>
#include <QMouseEvent>
#include <QTime>
#include <QWheelEvent>
#include "lib/glm.h"
#include "shape/Sphere.h"

Canvas3D::Canvas3D(QWidget *parent) //: SupportCanvas3D(parent)
    : QGLWidget(parent), m_timer(this), m_fps(60.0f), m_increment(0)
{
    // Set up the camera
    m_camera.eye.x = 0.0f, m_camera.eye.y = 0.0f, m_camera.eye.z = 5.0f;
        m_camera.center.x = 0.0f, m_camera.center.y = 0.0f, m_camera.center.z = 0.0f;
        m_camera.up.x = 0.0f, m_camera.up.y = 1.0f, m_camera.up.z = 0.0f;
        m_camera.fovy = 45.0f, m_camera.near = 0.02f, m_camera.far = 1000.0f;
    // Set up 60 FPS draw loop
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(tick()));

    // Start the timer for updating the screen
    m_timer.start(1000.0f / m_fps);
}

Canvas3D::~Canvas3D()
{
    safeDelete(m_fan_pix);
    safeDelete(m_checkered_pix);
    safeDelete(m_zebra_pix);
}


void Canvas3D::initializeGL()
{
    // Track the camera settings so we can generate deltas
//    m_oldPosX = settings.cameraPosX;
//    m_oldPosY = settings.cameraPosY;
//    m_oldPosZ = settings.cameraPosZ;
//    m_oldRotU = settings.cameraRotU;
//    m_oldRotV = settings.cameraRotV;
//    m_oldRotN = settings.cameraRotN;

    //Enable back-face culling, meaning only the front side of every face is rendered
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Specify that the front face is represented by vertices in counterclockwise order (this is the default)
    glFrontFace(GL_CCW);

    // Enable color materials with ambient and diffuse lighting terms
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Set up texture settings
    glDisable(GL_DITHER);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);

    initializeResources();

    m_emitters = new Emitter*[NUM_EMITTERS];
    double width_inc = ((double) FTN_WIDTH) / ((double) NUM_EMITTERS);
    double x_pos = FTN_LEFT;

    for (int i = 0; i < NUM_EMITTERS; i++)
    {
        Emitter *e = new Emitter(x_pos, m_shader_programs, m_skybox, m_cube_map);
        m_emitters[i] = e;
        x_pos += width_inc;
    }

    m_image = NULL;
    m_curr_pix = NULL;
    m_fan = new QImage();
    loadImage(m_fan, "../final/images/fan.jpg");
    m_fan_pix = (BGRA*) m_fan->constBits();
    m_zebra = new QImage();
    loadImage(m_zebra, "../final/images/zebra.jpg");
    m_zebra_pix = (BGRA*) m_zebra->constBits();
    m_checkered = new QImage();
    loadImage(m_checkered, "../final/images/check.jpg");
    m_checkered_pix = (BGRA*) m_checkered->constBits();

    m_img_height = 0;
    m_img_width = 0;
    m_img_scaled_height = 0;
    m_img_scale = 0.0;
    m_curr_height = -1;

    m_concrete_tex_id = loadTexture("../final/images/concrete.jpg");
    m_concrete_back_tex_id = loadTexture("../final/images/concrete_composite_back_wall.jpg");
    m_concrete_left_tex_id = loadTexture("../final/images/concrete_composite_left_wall.jpg");
    m_concrete_right_tex_id = loadTexture("../final/images/concrete_composite_right_wall.jpg");
    m_concrete_floor_tex_id = loadTexture("../final/images/concrete_composite_floor.jpg");
    m_concrete_ceil_tex_id = loadTexture("../final/images/concrete_composite_ceil.jpg");
    m_lightstrip_tex_id = loadTexture("../final/images/light_strip.jpg");
    m_particle_tex_id = loadTexture("../final/images/particle2.bmp");

    for (int i  = 0; i < NUM_EMITTERS; i++)
        m_emitters[i]->setTexture(m_particle_tex_id);

    // Load the initial settings
    if (settings.cameraZ < DROPLET_THRESHHOLD)
        settings.draw_type = DRAW_DROPLETS;
    else
        settings.draw_type = DRAW_PARTICLES;

    m_curr_pattern = settings.fountain_pattern;
    m_curr_draw_type = settings.draw_type;

    updateSettings();
    updateCamera();
}

void Canvas3D::initializeResources()
{
    cout << "Using OpenGL Version " << glGetString(GL_VERSION) << endl << endl;
    // Ideally we would now check to make sure all the OGL functions we use are supported
    // by the video card.  But that's a pain to do so we're not going to.
    cout << "--- Loading Resources ---" << endl;

    m_skybox = ResourceLoader::loadSkybox();
    cout << "Loaded skybox..." << endl;

    loadCubeMap();
    cout << "Loaded cube map..." << endl;

    createShaderPrograms();
    cout << "Loaded shader programs..." << endl;

    createFramebufferObjects(width(), height());
    cout << "Loaded framebuffer objects..." << endl;

    cout << " --- Finish Loading Resources ---" << endl;
}

/**
  Load a cube map for the skybox
 **/
void Canvas3D::loadCubeMap()
{
    QList<QFile *> fileList;

    fileList.append(new QFile("../final/images/ftn_box/posx.jpg"));
    fileList.append(new QFile("../final/images/ftn_box/negx.jpg"));
    fileList.append(new QFile("../final/images/ftn_box/posy.jpg"));
    fileList.append(new QFile("../final/images/ftn_box/negy.jpg"));
    fileList.append(new QFile("../final/images/ftn_box/posz.jpg"));
    fileList.append(new QFile("../final/images/ftn_box/negz.jpg"));
    m_cube_map = ResourceLoader::loadCubeMap(fileList);
}

/**
  Create shader programs.
 **/
void Canvas3D::createShaderPrograms()
{
    const QGLContext *ctx = context();
    m_shader_programs["reflect"] = ResourceLoader::newShaderProgram(ctx, "../final/shaders/reflect.vert",
                                                                   "../final/shaders/reflect.frag");
    m_shader_programs["refract"] = ResourceLoader::newShaderProgram(ctx, "../final/shaders/refract.vert",
                                                                   "../final/shaders/refract.frag");
    m_shader_programs["brightpass"] = ResourceLoader::newFragShaderProgram(ctx, "../final/shaders/brightpass.frag");
    m_shader_programs["blur"] = ResourceLoader::newFragShaderProgram(ctx, "../final/shaders/blur.frag");
}

/**
  Allocate framebuffer objects.

  @param width: the viewport width
  @param height: the viewport height
 **/
void Canvas3D::createFramebufferObjects(int width, int height)
{
    // Allocate the main framebuffer object for rendering the scene to
    // This needs a depth attachment
    m_framebufferObjects["fbo_0"] = new QGLFramebufferObject(width, height, QGLFramebufferObject::Depth,
                                                             GL_TEXTURE_2D, GL_RGB16F_ARB);
    m_framebufferObjects["fbo_0"]->format().setSamples(16);
    // Allocate the secondary framebuffer obejcts for rendering textures to (post process effects)
    // These do not require depth attachments
    m_framebufferObjects["fbo_1"] = new QGLFramebufferObject(width, height, QGLFramebufferObject::NoAttachment,
                                                             GL_TEXTURE_2D, GL_RGB16F_ARB);
    // TODO: Create another framebuffer here.  Look up two lines to see how to do this... =.=
}

GLuint Canvas3D::loadTexture(const QString &path)
{
    QFile file(path);

    QImage image, texture;
    if(!file.exists()) return -1;
    image.load(file.fileName());
    texture = QGLWidget::convertToGLFormat(image);

    //Put your code here
    GLuint tex_id;

    glGenTextures(1, &tex_id);
    glBindTexture(GL_TEXTURE_2D, tex_id);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, texture.width(), texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    return tex_id; /* return something meaningful */
}

bool Canvas3D::loadImage(QImage *image, const QString &file)
{
    QImage *temp = new QImage();
    if (!temp->load(file))
    {
        cout << "Failed to load " << file.toStdString() << endl;
        return false;
    }

    // make sure the image is RGB (not monochrome, for example)
    if (temp->format() != QImage::Format_RGB32)
    {
        QImage *old = temp;
        temp = new QImage(old->convertToFormat(QImage::Format_RGB32));
        delete old;
    }

    assert(temp->height() > 0);
    assert(temp->width() > 0);

    int t_height = temp->height();
    int t_width = temp->width();

    if (image)
        delete image;
    image = new QImage(temp->width(), temp->height(), QImage::Format_RGB32 /* this corresponds to the BGRA struct */);

    memset(image->bits(), 0, t_width * t_height * sizeof(BGRA));
    memcpy(image->bits(), temp->bits(), temp->numBytes());

    delete temp;

    assert(image);
    assert(image->height() > 0);
    assert(image->width() > 0);

    cout << "Successfully loaded " << file.toStdString() << endl;
    return true;
}

/**
  Called when the settings are updated through the UI.
  This is already filled in for you.
**/
void Canvas3D::updateSettings()
{
    if (m_curr_pattern != settings.fountain_pattern)
    {
        m_curr_pattern = settings.fountain_pattern;
        if (settings.fountain_pattern == PATTERN_FAN)
        {
            if (!m_fan || m_fan->isNull())
            {
                cout << "Checkered image null, using continuous" << endl;
                m_curr_pattern = PATTERN_CONTINUOUS;
                settings.fountain_pattern = PATTERN_CONTINUOUS;
                m_image = NULL;
            }
            else
            {
                m_image = m_fan;
                m_curr_pix = &m_fan_pix;
            }
        }
        else if (settings.fountain_pattern == PATTERN_CHECKERED)
        {
            if (!m_checkered || m_checkered->isNull())
            {
                cout << "Checkered image null, using continuous" << endl;
                m_curr_pattern = PATTERN_CONTINUOUS;
                settings.fountain_pattern = PATTERN_CONTINUOUS;
                m_image = NULL;
            }
            else
            {
                m_image = m_checkered;
                m_curr_pix = &m_checkered_pix;
            }
        }
        else if (settings.fountain_pattern == PATTERN_ZEBRA)
        {
            if (!m_zebra || m_zebra->isNull())
            {
                cout << "Checkered image null, using continuous" << endl;
                m_curr_pattern = PATTERN_CONTINUOUS;
                settings.fountain_pattern = PATTERN_CONTINUOUS;
                m_image = NULL;
            }
            else
            {
                m_image = m_zebra;
                m_curr_pix = &m_zebra_pix;
            }
        }
        else
            m_image = NULL;

        //if a pattern is set, set the image vars
        if (m_image)
        {
            m_img_height = m_image->height();
            m_img_width = m_image->width();
            assert(m_image->height() > 0);
            assert(m_image->width() > 0);
            m_img_scale = ((double) m_image->width() / (double) NUM_EMITTERS);
            m_img_scaled_height = (int) m_img_scale * m_image->height();
            m_curr_height = m_img_height - 1;
        }
        //pattern continuous OR striped
        else
        {
            m_img_height = 0;
            m_img_width = 0;
            m_img_scale = 0;
            m_img_scaled_height = 0;
            m_curr_height = 0;
        }
    }
}


void Canvas3D::paintGL()
{
    // Get the time in seconds
    //float time = m_increment++ / (float) m_fps;
    m_increment++;

    // Clear the color and depth buffers to the current glClearColor
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    paintScene();

    int index, col;
    int time_inc = (int) m_increment % DROP_FREQ;

    if (time_inc  == 0)
    {
        if (settings.fountain_pattern != PATTERN_CONTINUOUS && (m_image != NULL))
        {
            const BGRA* pix = (BGRA*) m_image->constBits();
            //const BGRA* pix = (*m_curr_pix);
            for (int i = 0; i < NUM_EMITTERS; i++)
            {
                if (m_curr_height > 0)
                {
                    col = (int) (i * m_img_scale);
                    index = ((int) m_curr_height) * m_img_width + col;
                    assert(col <= m_img_width);
                    assert(index <= m_img_height * m_img_width);
                    int color = (int) pix[index].b + (int) pix[index].g + (int) pix[index].r;
                    if (color < 90)
                    {
                        m_emitters[i]->addDrop(m_increment);
                    }
                }
            }
            // 0.4 is a random constant which I found worked well to make images scale nicely
            m_curr_height -=  DROP_FREQ * m_img_scale * 4.0;
            if (m_curr_height < 0)
                m_curr_height += m_img_height;

        }

        //make continuous flow, add drops to all emitters
        else if (settings.fountain_pattern == PATTERN_STRIPED)
        {
            int stripes = 2 * NUM_STRIPES - 1;
            if (NUM_STRIPES < 2)
                stripes = 1;
            int increment = (int) ((float) NUM_EMITTERS / (float) stripes);
            int strip_on = 0;
            for (int i = 0; i < stripes; i++)
            {
                //turn stripes on and off
                if (strip_on % 2 == 0)
                {
                    for (int j = i * increment; j < (i + 1) * increment; j++)
                    {
                        j = min(j, NUM_EMITTERS);
                        m_emitters[j]->addDrop(m_increment);
                    }
                }
                strip_on++;
            }
        }
        else
        {
            for (int i = 0; i < NUM_EMITTERS; i++)
                m_emitters[i]->addDrop(m_increment);
        }
    }



    //drop droplets
    if (settings.cameraZ < DROPLET_THRESHHOLD)
    {
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_CUBE_MAP);
        glBindTexture(GL_TEXTURE_CUBE_MAP, m_cube_map);
        glEnable(GL_CULL_FACE);

        // Render with the refraction shader bound
        glActiveTexture(GL_TEXTURE0);

        for (int i = 0; i < NUM_EMITTERS; i++)
        {

            Emitter *e = m_emitters[i];
            e->updateDrops();
            e->drawDroplets();
        }

        glEnable(GL_TEXTURE_2D);
        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_TEXTURE_CUBE_MAP);
    }

    //draw particles
    else
    {
        glBindTexture(GL_TEXTURE_2D, m_particle_tex_id);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glDepthMask(false);

        for (int i = 0; i < NUM_EMITTERS; i++)
        {

            Emitter *e = m_emitters[i];
            e->updateDrops();
            e->drawParticles();
        }

        glDepthMask(true);
    }

    //paints the front floor panel so droplets don't go in front of water trough
    paintFrontFloor();

}

/**
  Specifies to Qt what to do when the widget needs to be updated.
  We only want to repaint the onscreen objects.
**/
void Canvas3D::tick()
{
    update();
}

void Canvas3D::resizeGL(int width, int height)
{
    // Set the viewport to fill the screen
    glViewport(0, 0, width, height);
    // Update the camera
    updateCamera();
}

void Canvas3D::settingsChanged() {


    // Call superclass (this repaints the scene for you)
    //SupportCanvas3D::settingsChanged();
}

void Canvas3D::paintScene()
{
    //define scene
    float x_start = -2.5;
    float y_start = -1.5;
    float z_start = 0.0;

    float width = 5.0;
    float height = 3.0;
    float depth = 2.0;

    float trough_width = 0.8; // how far the trough starts from the x sides
    float trough_depth = 1.0;

    float x_end = x_start + width;
    float y_end = y_start + height;
    float z_end = z_start + depth;

    float light_width = 3.2;
    float z_light_depth = .2;

    float z_light_start = 1.0;
    float x_light_start = -1.0 * light_width / 2.0;
    float x_light_end = light_width / 2.0;
    float y_light = 1.48;

    float z_light_end = z_light_start + z_light_depth;

    glBindTexture(GL_TEXTURE_2D, m_concrete_back_tex_id);

    glBegin( GL_QUADS );
    //define back wall
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_start);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_start);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_end, y_end, z_start);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_start, y_end, z_start);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_concrete_ceil_tex_id);

    glBegin( GL_QUADS );
    //define top wall
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_start, y_end, z_start);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start, y_end, z_start);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_end, y_end, z_end);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end, y_end, z_end);
    glEnd();

    /**************
    *     FLOOR
    ***************/

    glBindTexture(GL_TEXTURE_2D, m_concrete_floor_tex_id);

    glBegin( GL_QUADS );
    //define back trough wall
    glColor3f(0.5, 0.5, 0.5);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_start + trough_width, y_start - trough_depth, z_end / 4.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_end - trough_width, y_start - trough_depth, z_end / 4.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_end - trough_width, y_start, z_end / 4.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_start + trough_width, y_start, z_end / 4.0);
    glEnd();

    glBegin( GL_QUADS );
    //define left trough wall
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_start + trough_width, y_start - trough_depth, z_end / 2.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start + trough_width, y_start - trough_depth, z_end / 4.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_start + trough_width, y_start, z_end / 4.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_start + trough_width, y_start, z_end / 2.0);
    glEnd();

    glBegin( GL_QUADS );
    //define right trough wall
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_end - trough_width, y_start - trough_depth, z_end / 4.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_end - trough_width, y_start - trough_depth, z_end / 2.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_end - trough_width, y_start, z_end / 2.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end - trough_width, y_start, z_end / 4.0);
    glEnd();

    glBegin( GL_QUADS );
    //define back floor panel
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_start);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_start);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_start, y_start, z_end / 4.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end, y_start, z_end / 4.0);
    glEnd();

    glBegin( GL_QUADS );
    //define side panel left
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_start + trough_width, y_start, z_end / 4.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_end / 4.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_start, y_start, z_end / 2.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_start + trough_width, y_start, z_end / 2.0);
    glEnd();

    glBegin( GL_QUADS );
    //define side panel right
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_end / 4.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_end - trough_width, y_start, z_end / 4.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_end - trough_width, y_start, z_end / 2.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end, y_start, z_end / 2.0);
    glEnd();

    /**************
    *  END FLOOR
    ***************/

    glBindTexture(GL_TEXTURE_2D, m_concrete_right_tex_id);

    glBegin( GL_QUADS );
    //define right wall
    //glColor3f(0.0, 0.0, 0.75);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_start);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_end);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_end, y_end, z_end);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end, y_end, z_start);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_concrete_left_tex_id);

    glBegin( GL_QUADS );
    //define left wall
    //glColor3f(0.0, 0.75, 0.0);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_end);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_start);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_start, y_end, z_start);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_start, y_end, z_end);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_lightstrip_tex_id);

    glBegin( GL_QUADS );
    //define light strip
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_light_start, y_light, z_light_start);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_light_end, y_light, z_light_start);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_light_end, y_light, z_light_end);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_light_start, y_light, z_light_end);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_concrete_floor_tex_id);

    glBegin( GL_QUADS );
    //define front floor panel
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_end / 2.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_end / 2.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_start, y_start, z_end);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end, y_start, z_end);
    glEnd();
}

void Canvas3D::paintFrontFloor()
{

    float x_start = -2.5;
    float y_start = -1.5;
    float z_start = 0.0;

    float width = 5.0;
    float depth = 2.0;

    float x_end = x_start + width;
    float z_end = z_start + depth;

    glBindTexture(GL_TEXTURE_2D, m_concrete_floor_tex_id);

    glDisable (GL_BLEND);
    glBegin( GL_QUADS );
    //define front floor panel
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x_end, y_start, z_end / 2.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x_start, y_start, z_end / 2.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x_start, y_start, z_end);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x_end, y_start, z_end);
    glEnd();
    glEnable(GL_BLEND);

}

/**
  Update the camera's specifications.
  You need to fill in this method.
  It gets called in resizeGL which get called automatically on intialization
  and whenever the window is resized.
**/
void Canvas3D::updateCamera()
{
    if (settings.cameraZ < DROPLET_THRESHHOLD)
        settings.draw_type = DRAW_DROPLETS;
    else
        settings.draw_type = DRAW_PARTICLES;

    float w = width();
    float h = height();
    float aspectRatio = 1.0f * w / h;
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(m_camera.fovy, aspectRatio, m_camera.near, m_camera.far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(m_camera.eye.x, m_camera.eye.y, settings.cameraZ,
              m_camera.center.x, m_camera.center.y, m_camera.center.z,
              m_camera.up.x, m_camera.up.y, m_camera.up.z);
}

void Canvas3D::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //mouseDown(event->x(), event->y());
        m_draggingLeft = true;
        update();
        cout << "mouse pressed " << endl;
        mouseDragged(event->x(), event->y());
    }
    else if(event->button() == Qt::RightButton)
    {
        m_draggingRight = true;
        update();
        cout << "mouse pressed " << endl;
        mouseDragged(event->x(), event->y());
    }
}

void Canvas3D::mouseMoveEvent(QMouseEvent *event)
{
    // m_draggingLeft and m_draggingRight are not mutually exclusive
    if (m_draggingLeft)
    {
        mouseDragged(event->x(), event->y());
        update();
    }
    if (m_draggingRight)
    {
        update();
    }
}


void Canvas3D::mouseDragged(int x, int y)
{
    //m_brush->paintOnce(x, y, this);
    cout << "mouse dragged " << endl;
    for (int i = 0; i < NUM_EMITTERS; i++)
    {
         m_emitters[i]->notifyMouseEvent(x, y);
    }
}

