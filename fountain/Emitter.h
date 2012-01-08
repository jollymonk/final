#ifndef EMITTER_H
#define EMITTER_H

#include <QList>
#include "CS123Algebra.h"
#include "CS123Matrix.h"
#include "CS123Common.h"
#include <QtOpenGL>
#include "Settings.h"

class Sphere;

using namespace std;

struct Droplet
{
    mutable Vector3 velocity;
    mutable Vector3 init_pos;
    mutable Vector3 curr_pos;
    mutable int num_drops_below;
    mutable float squish;
    mutable float squish_velocity;
};

class Emitter
{
public:
    Emitter(double x_loc, QHash<QString, QGLShaderProgram *> shader_programs, GLuint skybox, GLuint cube_map);
    ~Emitter();

    //updates the drops, passing in the change in velocity (for slowing time sim)
    void updateDrops();
    void addDrop(float time);
    void drawParticles();
    void drawDroplets();
    void setTexture(GLuint tex_id);
    void notifyMouseEvent(int x, int y);
    static float dist(int x1, int y1, int x2, int y2);

protected:

    double m_x_loc;
    QList<Droplet> *m_active_drops;
    GLuint m_tex_id;
    int m_num_consec_drops;
    float last_drop_time;
    Sphere *m_sphere;
    int m_curr_stacks;
    int m_curr_slices;

    //shaders
    QHash<QString, QGLShaderProgram *> m_shader_programs; // hash map of all shader programs
    GLuint m_skybox; // skybox call list ID
    GLuint m_cube_map; // cubeMap texture ID
    int m_time_since_drag;   //time since last mouse event, true if > 0
    bool m_mouse_input; //bool of whether to include mouse input
    int m_mouse_x;
    int m_mouse_y;
};

#endif // EMITTER_H
