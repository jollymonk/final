
#include "Emitter.h"
#include "CS123Common.h"
#include "Sphere.h"
#include "camera/CamtransCamera.h"

Emitter::Emitter(double x_loc, CamtransCamera *camera, QHash<QString, QGLShaderProgram *> shader_programs,
                 GLuint skybox, GLuint cube_map)
{
    m_x_loc = x_loc;
    m_active_drops = new QList<Droplet>();
    m_num_consec_drops = 0;
    last_drop_time = 0.0;

    m_camera = camera;
    m_shader_programs = shader_programs;
    m_skybox = skybox;
    m_cube_map = cube_map;
    m_curr_stacks = settings.sphere_stacks;
    m_curr_slices = settings.sphere_slices;
    m_sphere = new Sphere(m_curr_stacks, m_curr_slices);
    m_mouse_input = false;
    m_time_since_drag = -1;
}

Emitter::~Emitter()
{
    safeDelete(m_active_drops);
    safeDelete(m_sphere);

}

void Emitter::addDrop(float time)
{
    if (last_drop_time + 4.0 > time)
        m_num_consec_drops = 0;
    else
        m_num_consec_drops++;
    last_drop_time = time;

    Droplet d;
    d.init_pos = Vector3(m_x_loc, FTN_TOP, FTN_DEPTH);
    d.curr_pos = Vector3(m_x_loc, FTN_TOP - .01, FTN_DEPTH);
    d.velocity = Vector3(0.0, -0.008, 0.0);
    d.num_drops_below = min(MAX_CONSEC_DROPS, m_num_consec_drops);
    d.squish = 1.0 - urand() * .4;
    d.squish_velocity = urand() * .01 - .005;
    m_active_drops->push_back(d);

}

void Emitter::drawParticles()
{
    float brightness, alpha;
    float close_factor;

    for (int i = 0; i < m_active_drops->size(); i++)
    {
        Vector3 pos = m_active_drops->at(i).curr_pos;
        int drops = m_active_drops->at(i).num_drops_below;

        glPushMatrix();
        glTranslatef(pos.x, pos.y, pos.z);

        close_factor = 0.8 - min(0.8, FTN_TOP - pos.y);
        brightness = 0.8 + close_factor * .5 -
                     .3 * ((MAX_CONSEC_DROPS - drops) / MAX_CONSEC_DROPS);
        alpha = 0.8 + close_factor -
                .2 * ((MAX_CONSEC_DROPS - drops) / MAX_CONSEC_DROPS);

        brightness = min(1.0f, max(0.0f, brightness));
        alpha = min(1.0f, max(0.0f, alpha));

        if (urand() - .02 < 0)
        {
            brightness = 1.0 * settings.dropSlowDown;
            alpha = 1.0 * settings.dropSlowDown;
        }

        glColor4f(brightness, brightness, brightness * .9, alpha);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f,1.0f); glVertex3f(-DROP_SIZE, -DROP_SIZE, 0.0);
        glTexCoord2f(1.0f,0.0f); glVertex3f( DROP_SIZE, -DROP_SIZE, 0.0);
        glTexCoord2f(0.0f,0.0f); glVertex3f( DROP_SIZE, DROP_SIZE, 0.0);
        glTexCoord2f(0.0f,1.0f); glVertex3f(-DROP_SIZE, DROP_SIZE, 0.0);
        glEnd();


        glPopMatrix();
    }
}

void Emitter::drawDroplets()
{
    float range = 0.0, radius = 5.0;
    if (settings.cameraZ < 3.0)
    {
        range = (FTN_WIDTH / 2);
        radius = range * (settings.cameraZ / 3.0) + 0.1;
    }

    if ((float) fabs(m_x_loc) < radius)
    {

    //check if we need to make a more detailed sphere
    if ((m_curr_stacks != settings.sphere_stacks) || (m_curr_stacks != settings.sphere_slices))
    {
        m_curr_stacks = settings.sphere_stacks;
        m_curr_slices = settings.sphere_slices;
        safeDelete(m_sphere);
        m_sphere = new Sphere(m_curr_stacks, m_curr_slices);
    }


    for (int i = 0; i < m_active_drops->size(); i++)
    {
        Vector3 pos = m_active_drops->at(i).curr_pos;

        if (fabs(pos.y) < radius - 0.1)
        {

        glPushMatrix();
        glTranslatef(pos.x, pos.y, pos.z);

        glScalef(DROP_SIZE * m_active_drops->at(i).squish, DROP_SIZE, DROP_SIZE * m_active_drops->at(i).squish);

        m_shader_programs["refract"]->bind();
        m_shader_programs["refract"]->setUniformValue("CubeMap", GL_TEXTURE0);
        m_sphere->draw();
        m_shader_programs["refract"]->release();

//                    m_shader_programs["reflect"]->bind();
//                    m_shader_programs["reflect"]->setUniformValue("CubeMap", GL_TEXTURE0);
//                    m_sphere->draw();
//                    m_shader_programs["reflect"]->release();

        glPopMatrix();
        }
    }
    }
}

/**
  Updates the position, velocity, squish of every droplet
 **/
void Emitter::updateDrops()
{
    m_mouse_input = false;
    if (m_time_since_drag >= 0)
    {
        m_time_since_drag--;
        m_mouse_input = true;
    }

    //"real time"
    double pos_inc;
    Vector3 click_to_point;
    double dist, dist_perc, x_click_force, y_click_force;

    for (int i = 0; i < m_active_drops->size(); i++)
    {
        //update mouse input
        if (m_mouse_input == true && (fabs(m_x_loc - p_mouse_click.x) < CLICK_RADIUS))
        {
            click_to_point = m_active_drops->at(i).curr_pos - p_mouse_click;
            dist = click_to_point.getMagnitude();

            if (dist < CLICK_RADIUS)
            {
                click_to_point.y += 0.001;
                click_to_point = click_to_point.getNormalized();
                dist_perc = ((CLICK_RADIUS - dist) / CLICK_RADIUS);
                dist_perc *= min(((dist_perc * 5.0) / ((dist/ CLICK_RADIUS))), 0.005);
                click_to_point = click_to_point * dist_perc;
                if (click_to_point.y < 0 )
                    click_to_point *= dist_perc;

                x_click_force = click_to_point.x * 0.05;
                y_click_force = click_to_point.y;


                m_active_drops->at(i).velocity.x += x_click_force;
                m_active_drops->at(i).velocity.y += y_click_force;
                m_active_drops->at(i).velocity.y = min(m_active_drops->at(i).velocity.y, 0.001);
            }
        }

        //update drop position and velocity
        pos_inc = m_active_drops->at(i).velocity.y + (2.0 * urand() - 1.0) * Y_VARIATION;
        m_active_drops->at(i).curr_pos.y += pos_inc * settings.dropSlowDown;
        m_active_drops->at(i).curr_pos.y = min(m_active_drops->at(i).curr_pos.y, FTN_TOP);
        m_active_drops->at(i).curr_pos.x += m_active_drops->at(i).velocity.x;
        m_active_drops->at(i).velocity.y -= ACCELERATION;
        m_active_drops->at(i).squish += m_active_drops->at(i).squish_velocity * settings.dropSlowDown;

        //update drop squish
        if (m_active_drops->at(i).squish > .8)
            m_active_drops->at(i).squish_velocity -= .0001;
        else if (m_active_drops->at(i).squish < .6)
            m_active_drops->at(i).squish_velocity += .0001;
    }
    for (int i = 0; i < m_active_drops->size(); i++)
    {
        if (m_active_drops->at(i).curr_pos.y < (double) FTN_BOTTOM)
            m_active_drops->removeAt(i);
    }
}

void Emitter::setTexture(GLuint tex_id)
{
    m_tex_id = tex_id;
}

void Emitter::notifyMouseEvent(int x, int y)
{
    m_mouse_input = true;
    m_time_since_drag = 1;
    p_mouse_click = getFountainCoord(x, y);
}

void Emitter::notifySizeChanged(int width, int height) {
    m_width = width;
    m_height = height;
}

float Emitter::dist(float x1, float y1, float x2, float y2) {
   float x_dist = x2 - x1;
   float y_dist = y2 - y1;
   float dist = sqrt(x_dist * x_dist + y_dist * y_dist);
   return fabs(dist);
}

Vector3 Emitter::getFountainCoord(int x, int y) {
    float film_x, film_y, film_z = -1.0;
    Vector4 p_film, p_world, v_dir;
    film_y = -1.0 * ((2.0 * (REAL) y)/ (REAL) m_height) + 1.0;
    film_x = ((2.0 * (REAL) x)/ (REAL) m_width) - 1.0;
    p_film = Vector4(film_x, film_y, film_z, 1.0);
    Vector4 eye = m_camera->getPosition();
    p_world = m_camera->getFilmtoWorldMatrix() * p_film;
    v_dir = eye - p_world;
    v_dir = v_dir.getNormalized();
    float dist = fabs(FTN_DEPTH - eye.z) / v_dir.z;
    Vector3 ftn_point = Vector3(eye.x - dist * v_dir.x, eye.y - dist * v_dir.y, eye.z - dist * v_dir.z);
    return ftn_point;
}
