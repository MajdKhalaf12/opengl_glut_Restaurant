#include "Scene.h"
#include "Objects.h"
#include "Lighting.h"
#include "Camera.h"

#include <stdlib.h>
#include <Windows.h>
#include <GL/glut.h>

Camera camera;

void initGL() {
    glClearColor(0.5f, 0.8f, 0.9f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glutSetCursor(GLUT_CURSOR_NONE);

    setupLighting();
}

void drawTablesAndChairs() {
    float table_positions[][2] = { {-5.0f, -5.0f}, {-5.0f, 5.0f}, {5.0f, -5.0f}, {5.0f, 5.0f} };
    for (int i = 0; i < 4; i++) {
        float tx = table_positions[i][0];
        float tz = table_positions[i][1];
        drawTable(tx, tz);

        drawChair(tx - 1.5f, tz, 90.0f);  // Front
        drawChair(tx + 1.5f, tz, -90.0f); // Back
        drawChair(tx, tz - 1.5f, 0.0f);   // Left
        drawChair(tx, tz + 1.5f, 180.0f); // Right
    }
}

void renderShadowedObjects() {
    float groundPlane[] = { 0.0f, 1.0f, 0.0f, 0.0f }; // y=0 plane
    float lightPosition[] = { 10.0f, 10.0f, 10.0f, 1.0f };
    float shadowMatrix[4][4];
    computeShadowMatrix(shadowMatrix, groundPlane, lightPosition);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glMultMatrixf((const float*)shadowMatrix);
    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // Semi-transparent black
    drawTablesAndChairs();             // Draw shadows of tables and chairs
    glPopMatrix();

    glDisable(GL_BLEND);
}

void mouseMotion(int x, int y) {
    camera.handleMouseMovement(x, y); // Update camera direction
    glutPostRedisplay(); // Redraw the scene
}

void keyboard(unsigned char key, int x, int y) {
    float speed = 0.2f; // Movement speed

    if (key == 'w' || key == 'W') {
        camera.moveForward(speed);
    }
    else if (key == 's' || key == 'S') {
        camera.moveBackward(speed);
    }
    else if (key == 'd' || key == 'D') {
        camera.moveLeft(speed);
    }
    else if (key == 'a' || key == 'A') {
        camera.moveRight(speed);
    }
    else if (key == 'q' || key == 'Q') {
        camera.moveUp(speed);
    }
    else if (key == 'e' || key == 'E') {
        camera.moveDown(speed);
    }

    glutPostRedisplay(); // Redraw the scene
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Update camera direction based on input
    camera.updateDirection();

    // Position the camera using gluLookAt
    gluLookAt(camera.posX, camera.posY, camera.posZ,
        camera.posX + camera.frontX, camera.posY + camera.frontY, camera.posZ + camera.frontZ,
        camera.upX, camera.upY, camera.upZ);

    drawSkybox();  // Draw the skybox
    drawFloor();   // Draw the floor

    // Render shadows
    glDisable(GL_LIGHTING);    // Disable lighting for shadow rendering
    glEnable(GL_BLEND);        // Enable blending for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_DEPTH_TEST);  // Disable depth testing for shadows

    renderShadowedObjects();   // Render shadows

    glEnable(GL_DEPTH_TEST);   // Re-enable depth testing
    glDisable(GL_BLEND);       // Disable blending
    glEnable(GL_LIGHTING);     // Re-enable lighting

    // Render objects
    drawWalls();
    drawTablesAndChairs();

    glutSwapBuffers();  // Swap the buffers to display the scene
}


