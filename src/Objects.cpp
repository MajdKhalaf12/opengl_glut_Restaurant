#include "Objects.h"
#include "Textures.h"
#include "Lighting.h"
#include <stdlib.h>
#include <Windows.h>
#include <GL/glut.h>

#include <iostream>

// Global texture IDs
GLuint floorTexture;
GLuint chairTexture;
GLuint wallTexture;
GLuint painting;

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

    glDisable(GL_LIGHTING); // Disable lighting for the skybox

    // Apply night mode effect to the skybox
    if (isNightMode) {
        glColor3f(0.1f, 0.1f, 0.3f);  // Darker tint for the night sky
    }
    else {
        glColor3f(1.0f, 1.0f, 1.0f);  // Regular color for day sky
    }

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
    wallTexture = loadTexture("C:/Users/Majd/Desktop/Computer Science/programming/opengl/opengl_legacy/src/chair.jpg");
    painting = loadTexture("C:/Users/Majd/Desktop/Computer Science/programming/opengl/opengl_legacy/src/mona-lisa.jpg"); 
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
    glTranslatef(0.0f, 0.05f, 0.0f); // Center the seat at the correct height
    glBegin(GL_QUADS);

    // Top face with texture
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.05f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.05f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.05f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.05f, -0.5f);

    // Other faces without texture (set to a solid color)
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    // Bottom face
    glVertex3f(-0.5f, -0.05f, 0.5f);
    glVertex3f(0.5f, -0.05f, 0.5f);
    glVertex3f(0.5f, -0.05f, -0.5f);
    glVertex3f(-0.5f, -0.05f, -0.5f);

    // Front face
    glVertex3f(-0.5f, -0.05f, 0.5f);
    glVertex3f(0.5f, -0.05f, 0.5f);
    glVertex3f(0.5f, 0.05f, 0.5f);
    glVertex3f(-0.5f, 0.05f, 0.5f);

    // Back face
    glVertex3f(-0.5f, -0.05f, -0.5f);
    glVertex3f(0.5f, -0.05f, -0.5f);
    glVertex3f(0.5f, 0.05f, -0.5f);
    glVertex3f(-0.5f, 0.05f, -0.5f);

    // Left face
    glVertex3f(-0.5f, -0.05f, 0.5f);
    glVertex3f(-0.5f, -0.05f, -0.5f);
    glVertex3f(-0.5f, 0.05f, -0.5f);
    glVertex3f(-0.5f, 0.05f, 0.5f);

    // Right face
    glVertex3f(0.5f, -0.05f, 0.5f);
    glVertex3f(0.5f, -0.05f, -0.5f);
    glVertex3f(0.5f, 0.05f, -0.5f);
    glVertex3f(0.5f, 0.05f, 0.5f);

    glEnd();
    glPopMatrix();


    // Backrest with texture on front and back faces
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, -0.45f); // Center the backrest
    glBegin(GL_QUADS);

    // Front face with texture
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.4f, 0.05f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.4f, 0.05f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.4f, 0.05f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.4f, 0.05f);

    // Back face with texture
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.4f, -0.05f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.4f, -0.05f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.4f, -0.05f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.4f, -0.05f);

    // Other faces without texture (solid color)
    glColor3f(0.5f, 0.5f, 0.5f);
    // Left face
    glVertex3f(-0.5f, 0.4f, 0.05f);
    glVertex3f(-0.5f, 0.4f, -0.05f);
    glVertex3f(-0.5f, -0.4f, -0.05f);
    glVertex3f(-0.5f, -0.4f, 0.05f);

    // Right face
    glVertex3f(0.5f, 0.4f, 0.05f);
    glVertex3f(0.5f, 0.4f, -0.05f);
    glVertex3f(0.5f, -0.4f, -0.05f);
    glVertex3f(0.5f, -0.4f, 0.05f);

    // Top face
    glVertex3f(-0.5f, 0.4f, 0.05f);
    glVertex3f(0.5f, 0.4f, 0.05f);
    glVertex3f(0.5f, 0.4f, -0.05f);
    glVertex3f(-0.5f, 0.4f, -0.05f);

    // Bottom face
    glVertex3f(-0.5f, -0.4f, 0.05f);
    glVertex3f(0.5f, -0.4f, 0.05f);
    glVertex3f(0.5f, -0.4f, -0.05f);
    glVertex3f(-0.5f, -0.4f, -0.05f);

    glEnd();
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

void drawPainting(float x, float y, float z, float width, float height, GLuint texture) {
    if (texture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    glColor3f(1.0f, 1.0f, 1.0f); // White to allow the texture to show
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x - width / 2, y - height / 2, z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width / 2, y - height / 2, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width / 2, y + height / 2, z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x - width / 2, y + height / 2, z);
    glEnd();

    if (texture) {
        glDisable(GL_TEXTURE_2D);
    }
}


void drawWalls() {
    // Wall dimensions
    float wallHeight = 5.0f;
    float wallWidth = 20.0f; // Wall spans from -10 to 10 in both directions
    float windowWidth = 4.0f;
    float windowHeight = 2.0f;
    float windowYPosition = 1.5f; // Bottom of the window starts at this height
    float crossThickness = 0.1f;  // Thickness of the window cross
    float paintingWidth = 2.0f;  // Width of the painting
    float paintingHeight = 3.0f; // Height of the painting
    float paintingYPosition = 2.5f; // Center of the painting height



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
        else if (i==2) {
            drawPainting(0.0f, paintingYPosition, 0.01f, paintingWidth, paintingHeight, painting);
        }
        else {
            drawPainting(0.0f, paintingYPosition, -0.01f, paintingWidth, paintingHeight, painting);
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


    // Enable texture for the table (assuming tableTexture is already loaded)
    if (chairTexture) { // Assuming you have a texture for the table similar to chairTexture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, chairTexture);
    }

    glColor3f(1.0f, 1.0f, 1.0f); // White to allow texture color to show
    glNormal3f(0.0f, 1.0f, 0.0f); // Normal pointing upwards (top face)

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

void drawChandelier(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z); // Position chandelier at (x, y, z)

    // Central body (smaller sphere for the base)
    glColor3f(0.9f, 0.7f, 0.2f);  // Gold color
    glutSolidSphere(0.4f, 32, 32);  // Reduced size sphere for the base

    // Add the thin cylindrical base below the sphere to connect to the ceiling
    glPushMatrix();
    glTranslatef(0.0f, -0.4f, 0.0f);  // Position it right below the sphere
    glColor3f(0.8f, 0.6f, 0.2f);  // Slightly darker gold for the stem
    glScalef(0.1f, 0.4f, 0.1f);  // Thinner stem with reduced size
    glutSolidCube(1.0f);  // Small cube for the stem
    glPopMatrix();

    // Curved chandelier arms (8 arms for realism, reduced size)
    int numArms = 8;
    float armLength = 1.8f;  // Shorter arms for a smaller chandelier
    float armAngle = 360.0f / numArms;
    glPushMatrix();

    for (int i = 0; i < numArms; i++) {
        glPushMatrix();
        glRotatef(i * armAngle, 0.0f, 1.0f, 0.0f);  // Rotate each arm around the center

        // Curved arm design (smaller, thinner cylinders)
        glPushMatrix();
        glColor3f(0.7f, 0.7f, 0.7f);  // Metallic gray for the arm
        glTranslatef(armLength / 3.0f, 0.0f, 0.0f);  // Position for the curve
        glScalef(0.08f, 0.08f, 1.2f);  // Thinner, smaller part of the arm
        glutSolidCube(1.0f);  // First part of the arm
        glPopMatrix();

        glPushMatrix();
        glTranslatef(armLength, 0.0f, 0.0f);  // Move to the end of the arm
        glScalef(0.08f, 0.08f, 1.2f);  // Thinner part, smaller size
        glutSolidCube(1.0f);  // Second part of the arm
        glPopMatrix();

        // Light bulb (smaller size with metallic base)
        glTranslatef(armLength + 0.6f, 0.0f, 0.0f);  // Position the bulb at the end of the arm
        glColor3f(1.0f, 1.0f, 1.0f);  // White for the light bulb
        glutSolidSphere(0.3f, 16, 16);  // Smaller light bulb

        // Add a metallic base around the light bulb
        glColor3f(0.7f, 0.5f, 0.3f);  // Darker metallic color for the base
        glTranslatef(0.0f, -0.3f, 0.0f);  // Move slightly down to position the base
        glScalef(1.1f, 0.15f, 1.1f);  // Flatten it for a base appearance
        glutSolidSphere(0.3f, 8, 8);  // The base of the light bulb
        glPopMatrix();
    }
    glPopMatrix();

    // Add hanging crystals beneath each arm (smaller size)
    float crystalLength = 0.8f;  // Smaller length for crystals
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);  // Crystal color
    for (int i = 0; i < numArms; i++) {
        glPushMatrix();
        glRotatef(i * armAngle, 0.0f, 1.0f, 0.0f);  // Rotate around the center

        // Position the crystals below each arm
        glTranslatef(armLength + 0.6f, -0.4f, 0.0f);  // Slightly below the arm
        glutSolidSphere(0.08f, 8, 8);  // Smaller, delicate crystal

        glTranslatef(0.0f, -crystalLength, 0.0f);  // Move further down for multiple crystals
        glutSolidSphere(0.08f, 8, 8);  // Second crystal

        glTranslatef(0.0f, -crystalLength, 0.0f);  // Move further down
        glutSolidSphere(0.08f, 8, 8);  // Third crystal
        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();  // End chandelier drawing
}
