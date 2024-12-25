#include "Lighting.h"

void setupLighting() {
    // Define ambient, diffuse, and specular lighting properties
    GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    //GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat position[] = { 10.0f, 10.0f, 10.0f, 1.0f };

    // Set light 0 properties
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}