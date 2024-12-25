#include "Lighting.h"
#include <GL/glut.h>

// Shadow matrix for projecting shadows
void computeShadowMatrix(float shadowMat[4][4], const float groundplane[4], const float lightpos[4]) {
    float dot = groundplane[0] * lightpos[0] +
        groundplane[1] * lightpos[1] +
        groundplane[2] * lightpos[2] +
        groundplane[3] * lightpos[3];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shadowMat[i][j] = dot - lightpos[i] * groundplane[j];
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
