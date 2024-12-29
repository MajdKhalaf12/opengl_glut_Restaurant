#include "Lighting.h"
#include <GL/glut.h>

// Shadow matrix for projecting shadows
void computeShadowMatrix(GLfloat shadowMatrix[4][4], const GLfloat groundPlane[4], const GLfloat lightPos[4]) {
    GLfloat dot = groundPlane[0] * lightPos[0] +
        groundPlane[1] * lightPos[1] +
        groundPlane[2] * lightPos[2] +
        groundPlane[3] * lightPos[3];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shadowMatrix[i][j] = dot;
            shadowMatrix[i][j] -= lightPos[i] * groundPlane[j];
        }
    }
}


// Setup lighting
void setupLighting() {
    GLfloat lightPos[] = { 10.0f, 10.0f, 10.0f, 1.0f };
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
}
