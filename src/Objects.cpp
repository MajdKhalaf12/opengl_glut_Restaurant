#include "Objects.h"
#include "Textures.h"
#include <stdlib.h>
#include <Windows.h>
#include <GL/glut.h>

#include <iostream>

// Global texture IDs
GLuint floorTexture;
GLuint chairTexture;
GLuint wallTexture;

GLuint skyboxTextures[6]; // 0 = front, 1 = back, 2 = left, 3 = right, 4 = top, 5 = bottom

void initializeSkyboxTextures() {
    const char* texturePaths[6] = {
        "C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/front.bmp",
        "C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/back.jpg",
        "C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/left.jpg",
        "C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/right.jpg",
        "C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/top.jpg",
        "C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/bottom.jpg"
    };

    for (int i = 0; i < 6; ++i) {
        skyboxTextures[i] = loadTexture(texturePaths[i]);
        if (skyboxTextures[i] == 0) {
            std::cerr << "Error: Failed to load texture for skybox face " << i
                << " from path: " << texturePaths[i] << std::endl;
        }
    }
}

// Draw skybox
void drawSkybox() {

    float size = 50.0f;

    glPushMatrix();
    glDisable(GL_LIGHTING); // Disable lighting for the skybox

    for (int i = 0; i < 6; ++i) {
        glBindTexture(GL_TEXTURE_2D, skyboxTextures[i]);
        glEnable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        switch (i) {
        case 0: // Front
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, -size, -size);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(size, -size, -size);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(size, size, -size);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, -size);
            break;
        case 1: // Back
            glTexCoord2f(0.0f, 1.0f); glVertex3f(size, -size, size);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -size, size);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, size, size);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(size, size, size);
            break;
        case 2: // Left
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, -size, size);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -size, -size);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, size, -size);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, size);
            break;
        case 3: // Right
            glTexCoord2f(0.0f, 1.0f); glVertex3f(size, -size, -size);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(size, -size, size);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(size, size, size);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(size, size, -size);
            break;

        case 4: // Top
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, -size);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(size, size, -size);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, size);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, size);
            break;
        case 5: // Bottom
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, size);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, size);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(size, -size, -size);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, -size, -size);
            break;
        }
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }

    glEnable(GL_LIGHTING);
    glPopMatrix();
}

// Initialize textures (call this in your setup)
void initializeTextures() {
    floorTexture = loadTexture("C:/Users/Majd/Desktop/Computer Science/programming/opengl/opengl_legacy/src/floor.jpg");
    chairTexture = loadTexture("C:/Users/Majd/Desktop/Computer Science/programming/opengl/opengl_legacy/src/chair.jpg");
    wallTexture = loadTexture("C:/Users/Majd/Desktop/Computer Science/programming/opengl/opengl_legacy/src/chair.jpg"); // Wall texture
}

void drawFloor() {
    if (floorTexture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, floorTexture);
    }

    glColor3f(1.0f, 1.0f, 1.0f); // White to allow texture color to show
    glNormal3f(0.0f, 1.0f, 0.0f);

    float repeat = 5.0;

    glBegin(GL_QUADS);

    //floor
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f, -10.0f);
    glTexCoord2f(0.0f, repeat); glVertex3f(-10.0f, 0.0f, 10.0f);
    glTexCoord2f(repeat, repeat); glVertex3f(10.0f, 0.0f, 10.0f);
    glTexCoord2f(repeat, 0.0f); glVertex3f(10.0f, 0.0f, -10.0f);

    //ceiling
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 5.0f, -10.0f);
    glTexCoord2f(0.0f, repeat); glVertex3f(-10.0f, 5.0f, 10.0f);
    glTexCoord2f(repeat, repeat); glVertex3f(10.0f, 5.0f, 10.0f);
    glTexCoord2f(repeat, 0.0f); glVertex3f(10.0f, 5.0f, -10.0f);
    glEnd();

    if (floorTexture) {
        glDisable(GL_TEXTURE_2D);
    }
}

void drawChair(float x, float z, float angle) {
    glPushMatrix();
    glTranslatef(x, 0.5f, z);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    if (chairTexture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, chairTexture);
    }

    // Seat
    glColor3f(1.0f, 1.0f, 1.0f); // White for texture
    glPushMatrix();
    glScalef(1.0f, 0.1f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Backrest
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, -0.45f);
    glScalef(1.0f, 0.8f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Chair legs
    float legHeight = 0.5f;
    float legOffset = 0.45f;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glTranslatef(i * legOffset, -legHeight / 2.0f, j * legOffset);
            glScalef(0.1f, legHeight, 0.1f);
            glutSolidCube(1.0f);
            glPopMatrix();
        }
    }

    if (chairTexture) {
        glDisable(GL_TEXTURE_2D);
    }

    glPopMatrix();
}

void drawWalls() {
    // Wall dimensions
    float wallHeight = 5.0f;
    float wallWidth = 20.0f; // Wall spans from -10 to 10 in both directions
    float windowWidth = 4.0f;
    float windowHeight = 2.0f;
    float windowYPosition = 1.5f; // Bottom of the window starts at this height
    float crossThickness = 0.1f;  // Thickness of the window cross

    // Normals for each wall
    float wallNormals[4][3] = {
        {0.0f, 0.0f, 1.0f},  // Back
        {0.0f, 0.0f, -1.0f}, // Front
        {1.0f, 0.0f, 0.0f},  // Left
        {-1.0f, 0.0f, 0.0f}  // Right
    };

    // Wall positions and orientations
    float wallOffsets[4][3] = {
        {0.0f, 0.0f, -10.0f}, // Back wall
        {0.0f, 0.0f, 10.0f},  // Front wall
        {-10.0f, 0.0f, 0.0f}, // Left wall
        {10.0f, 0.0f, 0.0f}   // Right wall
    };

    float wallRotations[4] = { 0.0f, 0.0f, 90.0f, 90.0f };

    // Repeat value for tiling the texture
    float repeat = 2.0f; // Adjust this value as needed for your desired tiling effect

    for (int i = 0; i < 4; i++) {
        glPushMatrix();

        // Position and rotate walls
        glTranslatef(wallOffsets[i][0], wallOffsets[i][1], wallOffsets[i][2]);
        glRotatef(wallRotations[i], 0.0f, 1.0f, 0.0f);
        glNormal3f(wallNormals[i][0], wallNormals[i][1], wallNormals[i][2]);

        if (wallTexture) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, wallTexture); // Bind the wall texture
        }

        glBegin(GL_QUADS);

        // Apply repeating texture coordinates for tiling
        if (i == 1 || i == 0) { // Back (i == 0) and Front (i == 1) have windows
            // Bottom part of the wall (below the window)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidth / 2, 0.0f, 0.0f);
            glTexCoord2f(2.0f, 0.0f); glVertex3f(-wallWidth / 2, windowYPosition, 0.0f);
            glTexCoord2f(2.0f, 2.0f); glVertex3f(wallWidth / 2, windowYPosition, 0.0f);
            glTexCoord2f(0.0f, 2.0f); glVertex3f(wallWidth / 2, 0.0f, 0.0f);

            // Left part of the wall (to the left of the window)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidth / 2, windowYPosition, 0.0f);
            glTexCoord2f(repeat, 0.0f); glVertex3f(-wallWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(repeat, repeat); glVertex3f(-windowWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(0.0f, repeat); glVertex3f(-windowWidth / 2, windowYPosition, 0.0f);

            // Right part of the wall (to the right of the window)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(windowWidth / 2, windowYPosition, 0.0f);
            glTexCoord2f(repeat, 0.0f); glVertex3f(windowWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(repeat, repeat); glVertex3f(wallWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(0.0f, repeat); glVertex3f(wallWidth / 2, windowYPosition, 0.0f);

            // Top part of the wall (above the window)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-windowWidth / 2, windowYPosition + windowHeight, 0.0f);
            glTexCoord2f(repeat, 0.0f); glVertex3f(-windowWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(repeat, repeat); glVertex3f(windowWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(0.0f, repeat); glVertex3f(windowWidth / 2, windowYPosition + windowHeight, 0.0f);
        }
        else {
            // Normal wall without window (left and right walls)
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidth / 2, 0.0f, 0.0f);
            glTexCoord2f(repeat, 0.0f); glVertex3f(-wallWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(repeat, repeat); glVertex3f(wallWidth / 2, wallHeight, 0.0f);
            glTexCoord2f(0.0f, repeat); glVertex3f(wallWidth / 2, 0.0f, 0.0f);
        }

        glEnd();

        // Only add the window cross on the front and back walls
        if (i == 1 || i == 0) {
            glColor3f(0.5f, 0.5f, 0.5f); // Darker gray for the cross
            glBegin(GL_QUADS);

            // Vertical bar of the cross
            glVertex3f(-crossThickness / 2, windowYPosition, 0.01f);
            glVertex3f(crossThickness / 2, windowYPosition, 0.01f);
            glVertex3f(crossThickness / 2, windowYPosition + windowHeight, 0.01f);
            glVertex3f(-crossThickness / 2, windowYPosition + windowHeight, 0.01f);

            // Horizontal bar of the cross
            glVertex3f(-windowWidth / 2, windowYPosition + windowHeight / 2 - crossThickness / 2, 0.01f);
            glVertex3f(windowWidth / 2, windowYPosition + windowHeight / 2 - crossThickness / 2, 0.01f);
            glVertex3f(windowWidth / 2, windowYPosition + windowHeight / 2 + crossThickness / 2, 0.01f);
            glVertex3f(-windowWidth / 2, windowYPosition + windowHeight / 2 + crossThickness / 2, 0.01f);

            glEnd();
        }

        if (wallTexture) {
            glDisable(GL_TEXTURE_2D); // Disable the wall texture after drawing the walls
        }

        glPopMatrix();
    }
}


void drawTable(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 1.0f, z);

    // Tabletop
    glColor3f(0.7f, 0.5f, 0.3f); // Wooden color
    glPushMatrix();
    glScalef(2.0f, 0.1f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Table legs
    float legHeight = 1.0f;
    float legOffset = 0.9f;
    glColor3f(0.5f, 0.3f, 0.1f); // Darker wood for legs
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glTranslatef(i * legOffset, -legHeight / 2.0f, j * legOffset);
            glScalef(0.1f, legHeight, 0.1f);
            glutSolidCube(1.0f);
            glPopMatrix();
        }
    }

    glPopMatrix();
}
