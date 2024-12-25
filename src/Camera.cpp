#include "Camera.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Camera::Camera()
    : posX(0.0f), posY(1.8f), posZ(5.0f),
    frontX(0.0f), frontY(0.0f), frontZ(-1.0f),
    upX(0.0f), upY(1.0f), upZ(0.0f),
    yaw(-90.0f), pitch(0.0f), sensitivity(0.1f),
    firstMouse(true), lastMouseX(400.0f), lastMouseY(300.0f) {
}

void Camera::updateDirection() {
    float radYaw = yaw * M_PI / 180.0f;
    float radPitch = pitch * M_PI / 180.0f;

    frontX = cos(radYaw) * cos(radPitch);
    frontY = sin(radPitch);
    frontZ = sin(radYaw) * cos(radPitch);

    float length = sqrt(frontX * frontX + frontY * frontY + frontZ * frontZ);
    frontX /= length; frontY /= length; frontZ /= length;
}

void Camera::handleMouseMovement(int x, int y) {
    if (firstMouse) {
        lastMouseX = x;
        lastMouseY = y;
        firstMouse = false;
    }

    float xoffset = x - lastMouseX;
    float yoffset = lastMouseY - y;
    lastMouseX = x;
    lastMouseY = y;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateDirection();
}

void Camera::moveForward(float speed) {
    posX += frontX * speed;
    posY += frontY * speed;
    posZ += frontZ * speed;
}

void Camera::moveBackward(float speed) {
    posX -= frontX * speed;
    posY -= frontY * speed;
    posZ -= frontZ * speed;
}

void Camera::moveLeft(float speed) {
    float rightX = upY * frontZ - upZ * frontY;
    float rightY = upZ * frontX - upX * frontZ;
    float rightZ = upX * frontY - upY * frontX;

    float length = sqrt(rightX * rightX + rightY * rightY + rightZ * rightZ);
    rightX /= length; rightY /= length; rightZ /= length;

    posX -= rightX * speed;
    posY -= rightY * speed;
    posZ -= rightZ * speed;
}

void Camera::moveRight(float speed) {
    float rightX = upY * frontZ - upZ * frontY;
    float rightY = upZ * frontX - upX * frontZ;
    float rightZ = upX * frontY - upY * frontX;

    float length = sqrt(rightX * rightX + rightY * rightY + rightZ * rightZ);
    rightX /= length; rightY /= length; rightZ /= length;

    posX += rightX * speed;
    posY += rightY * speed;
    posZ += rightZ * speed;
}

void Camera::moveUp(float speed) {
    posY += speed;
}

void Camera::moveDown(float speed) {
    posY -= speed;
}
