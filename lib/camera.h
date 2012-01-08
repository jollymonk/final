#ifndef CAMERA_H
#define CAMERA_H

#include "CS123Algebra.h"
#include "CS123Matrix.h"

/**
    A basic camera
*/
struct LabCamera {
    Vector3 eye, center, up;
    Vector4 look;
    float fovy, near, far;
    Vector4 u, v, w;
};

#endif // CAMERA_H
