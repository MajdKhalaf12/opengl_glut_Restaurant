#pragma once

#ifndef CAMERA_H
#define CAMERA_H



#include <stdlib.h>
#include <GL/freeglut.h>

struct Camera {
    float posX, posY, posZ;
    float frontX, frontY, frontZ;
    float upX, upY, upZ;
    float yaw, pitch;
    float sensitivity;
    bool firstMouse;
    float lastMouseX, lastMouseY;

    Camera();
    void updateDirection();
    void handleMouseMovement(int x, int y);
    void moveForward(float speed);
    void moveBackward(float speed);
    void moveLeft(float speed);
    void moveRight(float speed);
    void moveUp(float speed);
    void moveDown(float speed);
};

#endif
