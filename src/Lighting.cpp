#include "Lighting.h"
#include <GL/glut.h>

void setupLighting(bool isNightMode) {
    GLfloat lightPos[] = { 10.0f, 10.0f, 10.0f, 1.0f };

    // Default (day mode) lighting
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Add chandelier light in the middle of the scene
    GLfloat chandelierPos[] = { 0.0f, 10.0f, 0.0f, 1.0f };  // Position chandelier at (0, 10, 0)

    // Default chandelier lighting
    GLfloat chandelierAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat chandelierDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat chandelierSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    if (isNightMode) {
        // Night mode lighting (dimmed and cooler)
        lightAmbient[0] = 0.1f; // Lower ambient light intensity
        lightAmbient[1] = 0.1f;
        lightAmbient[2] = 0.3f; // Slightly bluish hue for a cooler effect

        lightDiffuse[0] = 0.3f; // Dimmed diffuse light
        lightDiffuse[1] = 0.3f;
        lightDiffuse[2] = 0.6f; // Blueish color

        lightSpecular[0] = 0.5f; // Less intense specular light
        lightSpecular[1] = 0.5f;
        lightSpecular[2] = 0.7f; // Slightly blue specular

        // Adjust chandelier for night mode (e.g., warmer color, dimmer)
        chandelierAmbient[0] = 0.1f;
        chandelierAmbient[1] = 0.1f;
        chandelierAmbient[2] = 0.2f; // Dim and warm for night

        chandelierDiffuse[0] = 0.8f; // Slightly dimmer and warmer
        chandelierDiffuse[1] = 0.6f;
        chandelierDiffuse[2] = 0.3f; // Warm amber color for chandelier

        chandelierSpecular[0] = 0.7f; // Slightly dimmer specular reflection
        chandelierSpecular[1] = 0.7f;
        chandelierSpecular[2] = 0.5f; // Warm reflection
    }

    // Set lighting for main scene light (light0)
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // Set lighting for chandelier (light1)
    glLightfv(GL_LIGHT1, GL_POSITION, chandelierPos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, chandelierAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, chandelierDiffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, chandelierSpecular);

    // Enable the light sources
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}
