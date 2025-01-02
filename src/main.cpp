//#include <gl/glut.h>
//
//float angle = 0.0f; // Rotation angle for the cube
//
//// Function to initialize the OpenGL environment
//void initOpenGL() {
//    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
//}
//
//// Function to handle window resizing
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h); // Set the viewport to the new window size
//    glMatrixMode(GL_PROJECTION); // Switch to projection matrix
//    glLoadIdentity(); // Reset the projection matrix
//    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0); // Set perspective view
//    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix
//}
//
//// Function to draw a cube
//void drawCube() {
//    glBegin(GL_QUADS); // Start drawing quads (4-sided polygons)
//
//    // Front face
//    glColor3f(1.0f, 0.0f, 0.0f); // Red
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//
//    // Back face
//    glColor3f(0.0f, 1.0f, 0.0f); // Green
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    // Left face
//    glColor3f(0.0f, 0.0f, 1.0f); // Blue
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//
//    // Right face
//    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//    glVertex3f(1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//
//    // Top face
//    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//
//    // Bottom face
//    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//
//    glEnd(); // End drawing quads
//}
//
//// Function to update the display and handle rotation
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
//
//    glLoadIdentity(); // Reset the modelview matrix
//    glTranslatef(0.0f, 0.0f, -6.0f); // Move the cube back to view
//
//    glRotatef(angle, 1.0f, 1.0f, 0.0f); // Rotate the cube
//
//    drawCube(); // Call the function to draw the cube
//
//    glutSwapBuffers(); // Swap the front and back buffers to display the scene
//}
//
//// Function to handle animation
//void update(int value) {
//    angle += 2.0f; // Increment the angle to rotate the cube
//    if (angle > 360) {
//        angle -= 360; // Keep the angle within a 360 degree range
//    }
//
//    glutPostRedisplay(); // Mark the window as needing a redraw
//    glutTimerFunc(16, update, 0); // Set up the next update (roughly 60fps)
//}
//
//// Main function to initialize GLUT and OpenGL
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // Initialize GLUT
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set the display mode
//    glutInitWindowSize(800, 600); // Set the window size
//    glutCreateWindow("Rotating Cube"); // Create the window with a title
//
//    initOpenGL(); // Initialize OpenGL settings
//    glutDisplayFunc(display); // Register the display function
//    glutReshapeFunc(reshape); // Register the reshape function
//    glutTimerFunc(25, update, 0); // Start the animation update loop
//
//    glutMainLoop(); // Enter the GLUT event processing loop
//    return 0;
//}
//
//



//#include <cstdlib> // Must be included before GLUT headers
//#include <cmath>
//#include <cstdio>
//
//// Define M_PI if it's not defined
//
//
//// Define GLUT_DISABLE_ATEXIT_HACK to prevent FreeGLUT from redefining 'exit'
//#define GLUT_DISABLE_ATEXIT_HACK
//#include <gl/glut.h> // Corrected to <GL/glut.h> for portability
//
//// Window dimensions
//const int WIDTH = 800;
//const int HEIGHT = 600;
//
//// Camera parameters
//float cameraPosX = 0.0f;
//float cameraPosY = 1.8f; // Typical eye height
//float cameraPosZ = 5.0f;
//
//float cameraFrontX = 0.0f;
//float cameraFrontY = 0.0f;
//float cameraFrontZ = -1.0f;
//
//float cameraUpX = 0.0f;
//float cameraUpY = 1.0f;
//float cameraUpZ = 0.0f;
//
//// Camera orientation
//float yaw = -90.0f;   // Yaw is initialized to -90.0 degrees to look towards negative Z
//float pitch = 0.0f;    // Pitch is initialized to 0 degrees
//
//// Mouse control variables
//bool firstMouse = true;
//float lastMouseX = WIDTH / 2.0f;
//float lastMouseY = HEIGHT / 2.0f;
//float sensitivity = 0.1f;
//
//// Movement control variables
//bool keys[256];
//float deltaTime = 0.0f; // Time between current frame and last frame
//float lastFrame = 0.0f;
//
//// Function Prototypes
//void initGL();
//void display();
//void reshape(int width, int height);
//void keyboardDown(unsigned char key, int x, int y);
//void keyboardUp(unsigned char key, int x, int y);
//void specialKeys(int key, int x, int y);
//void mouseMovement(int x, int y);
//void idle();
//void drawFloor();
//void drawWalls();
//void drawTable(float x, float z);
//void drawChair(float x, float z, float angle);
//void setupLighting();
//
//// Initialize OpenGL settings
//void initGL() {
//    glClearColor(0.5f, 0.8f, 0.9f, 1.0f); // Sky blue background
//    glEnable(GL_DEPTH_TEST);              // Enable depth testing for 3D
//    glEnable(GL_LIGHTING);                // Enable lighting
//    glEnable(GL_LIGHT0);                  // Enable light #0
//    glEnable(GL_COLOR_MATERIAL);          // Enable color tracking
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    setupLighting();
//
//    // Enable smooth shading
//    glShadeModel(GL_SMOOTH);
//
//    // Hide and lock the cursor to the window center
//    glutSetCursor(GLUT_CURSOR_NONE);
//    glutWarpPointer(WIDTH / 2, HEIGHT / 2);
//}
//
//// Setup basic lighting
//void setupLighting() {
//    GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
//    GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//    GLfloat position[] = { 10.0f, 10.0f, 10.0f, 1.0f };
//
//    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//    glLightfv(GL_LIGHT0, GL_POSITION, position);
//}
//
//// Display callback
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    // Calculate the direction vector
//    float frontX = cosf((yaw * M_PI) / 180.0f) * cosf((pitch * M_PI) / 180.0f);
//    float frontY = sinf((pitch * M_PI) / 180.0f);
//    float frontZ = sinf((yaw * M_PI) / 180.0f) * cosf((pitch * M_PI) / 180.0f);
//
//    cameraFrontX = frontX;
//    cameraFrontY = frontY;
//    cameraFrontZ = frontZ;
//
//    // Normalize the front vector
//    float length = sqrtf(cameraFrontX * cameraFrontX + cameraFrontY * cameraFrontY + cameraFrontZ * cameraFrontZ);
//    cameraFrontX /= length;
//    cameraFrontY /= length;
//    cameraFrontZ /= length;
//
//    // Calculate the look-at point
//    float lookAtX = cameraPosX + cameraFrontX;
//    float lookAtY = cameraPosY + cameraFrontY;
//    float lookAtZ = cameraPosZ + cameraFrontZ;
//
//    // Set the camera
//    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,  // Eye position
//        lookAtX, lookAtY, lookAtZ,           // Look-at point
//        cameraUpX, cameraUpY, cameraUpZ);    // Up vector
//
//    // Draw scene components
//    drawFloor();
//    drawWalls();
//
//    // Draw multiple tables and chairs
//    float table_positions[][2] = {
//        { -5.0f, -5.0f },
//        { -5.0f,  5.0f },
//        {  5.0f, -5.0f },
//        {  5.0f,  5.0f }
//    };
//
//    for (int i = 0; i < 4; i++) {
//        float tx = table_positions[i][0];
//        float tz = table_positions[i][1];
//        drawTable(tx, tz);
//        // Draw 4 chairs around each table
//        drawChair(tx - 1.5f, tz, 90.0f);     // Front
//        drawChair(tx + 1.5f, tz, -90.0f);   // Back
//        drawChair(tx, tz - 1.5f, 0.0f);    // Left
//        drawChair(tx, tz + 1.5f, 180.0f);   // Right
//    }
//
//    glutSwapBuffers();
//}
//
//// Reshape callback
//void reshape(int width, int height) {
//    if (height == 0) height = 1;                // Prevent division by zero
//    float aspect = static_cast<float>(width) / static_cast<float>(height);
//
//    glViewport(0, 0, width, height);
//
//    // Set the projection matrix
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, aspect, 0.1, 100.0); // Near plane adjusted to 0.1 for better precision
//
//    // Return to modelview matrix mode
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// Keyboard press callback
//void keyboardDown(unsigned char key, int x, int y) {
//    keys[key] = true;
//
//    // Exit on ESC
//    if (key == 27) {
//        exit(0);
//    }
//}
//
//// Keyboard release callback
//void keyboardUp(unsigned char key, int x, int y) {
//    keys[key] = false;
//}
//
//// Mouse movement callback
//void mouseMovement(int x, int y) {
//    if (firstMouse) {
//        lastMouseX = (float)x;
//        lastMouseY = (float)y;
//        firstMouse = false;
//    }
//
//    float xoffset = x - lastMouseX;
//    float yoffset = lastMouseY - y; // Reversed since y-coordinates range from bottom to top
//    lastMouseX = (float)x;
//    lastMouseY = (float)y;
//
//    xoffset *= sensitivity;
//    yoffset *= sensitivity;
//
//    yaw += xoffset;
//    pitch += yoffset;
//
//    // Constrain the pitch angle to prevent screen flipping
//    if (pitch > 89.0f)
//        pitch = 89.0f;
//    if (pitch < -89.0f)
//        pitch = -89.0f;
//
//    glutPostRedisplay();
//}
//
//// Special keys callback (optional for additional controls)
//void specialKeys(int key, int x, int y) {
//    // Can be used for additional controls like sprinting, crouching, etc.
//}
//
//// Idle callback for continuous updates
//void idle() {
//    // Calculate deltaTime
//    float currentFrame = glutGet(GLUT_ELAPSED_TIME) / 1000.0f; // Time in seconds
//    deltaTime = currentFrame - lastFrame;
//    lastFrame = currentFrame;
//
//    float cameraSpeed = 5.0f * deltaTime; // Adjust accordingly
//
//    if (keys['w'] || keys['W']) {
//        cameraPosX += cameraFrontX * cameraSpeed;
//        cameraPosY += cameraFrontY * cameraSpeed;
//        cameraPosZ += cameraFrontZ * cameraSpeed;
//    }
//    if (keys['s'] || keys['S']) {
//        cameraPosX -= cameraFrontX * cameraSpeed;
//        cameraPosY -= cameraFrontY * cameraSpeed;
//        cameraPosZ -= cameraFrontZ * cameraSpeed;
//    }
//    if (keys['a'] || keys['A']) {
//        // Calculate right vector
//        float rightX = cameraFrontY * cameraUpZ - cameraFrontZ * cameraUpY;
//        float rightY = cameraFrontZ * cameraUpX - cameraFrontX * cameraUpZ;
//        float rightZ = cameraFrontX * cameraUpY - cameraFrontY * cameraUpX;
//
//        // Normalize right vector
//        float length = sqrtf(rightX * rightX + rightY * rightY + rightZ * rightZ);
//        rightX /= length;
//        rightY /= length;
//        rightZ /= length;
//
//        cameraPosX -= rightX * cameraSpeed;
//        cameraPosY -= rightY * cameraSpeed;
//        cameraPosZ -= rightZ * cameraSpeed;
//    }
//    if (keys['d'] || keys['D']) {
//        // Calculate right vector
//        float rightX = cameraFrontY * cameraUpZ - cameraFrontZ * cameraUpY;
//        float rightY = cameraFrontZ * cameraUpX - cameraFrontX * cameraUpZ;
//        float rightZ = cameraFrontX * cameraUpY - cameraFrontY * cameraUpX;
//
//        // Normalize right vector
//        float length = sqrtf(rightX * rightX + rightY * rightY + rightZ * rightZ);
//        rightX /= length;
//        rightY /= length;
//        rightZ /= length;
//
//        cameraPosX += rightX * cameraSpeed;
//        cameraPosY += rightY * cameraSpeed;
//        cameraPosZ += rightZ * cameraSpeed;
//    }
//
//    // Optionally, add movement for space (up) and shift (down)
//    if (keys['e']) { // Space key for moving up
//        cameraPosY += cameraSpeed;
//    }
//    if (keys['q']) { // 'L' key for moving down (using 'l' to avoid conflict with other controls)
//        cameraPosY -= cameraSpeed;
//    }
//
//    glutPostRedisplay();
//}
//
//
//int main(int argc, char** argv) {
//    // Initialize GLUT
//    glutInit(&argc, argv);
//
//    // Set display mode: Double buffer, RGB color, Depth buffer
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//    // Set window size
//    glutInitWindowSize(WIDTH, HEIGHT);
//
//    // Create the window with title
//    glutCreateWindow("3D Restaurant Scene with First-Person Navigation");
//
//    // Initialize rendering
//    initGL();
//
//    // Register callbacks
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboardDown);
//    glutKeyboardUpFunc(keyboardUp);
//    glutPassiveMotionFunc(mouseMovement); // Capture mouse movement
//    glutSpecialFunc(specialKeys);         // Register special keys callback
//    glutIdleFunc(idle);                   // Register idle callback
//
//    // Enter the GLUT event loop
//    glutMainLoop();
//
//    return 0;
//}
//
//
//
//#include <cmath>
//#define GLUT_DISABLE_ATEXIT_HACK
//#include <GL/glut.h> 
//
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb/stb_image.h>
//
//
//GLuint textureID;
//
//void loadTexture(const char* filename) {
//    int width, height, channels; // Variables to store image dimensions and channels
//    stbi_set_flip_vertically_on_load(1);
//    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0); // Load the image
//
//    if (!image) {
//        printf("Failed to load texture\n"); // Error handling if image fails to load
//        exit(1); // Exit the program if texture loading fails
//    }
//
//    glGenTextures(1, &textureID); // Generate a texture ID
//    glBindTexture(GL_TEXTURE_2D, textureID); // Bind the texture for operations
//
//    glTexImage2D(
//        GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
//        channels == 4 ? GL_RGBA : GL_RGB, // Handle RGB or RGBA formats
//        GL_UNSIGNED_BYTE, image // Pass the image data to OpenGL
//    );
//
//    // Set texture parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Wrap horizontally
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Wrap vertically
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Minification filter
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Magnification filter
//
//    stbi_image_free(image); // Free memory allocated for the image
//}
//
//// Render function (called each frame)
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
//    glEnable(GL_TEXTURE_2D); 
//    glBindTexture(GL_TEXTURE_2D, textureID);
//
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-10.0f, -10.0f);
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(10.0f, -10.0f);
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(10.0f, 10.0f);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-10.0f, 10.0f);
//    glEnd();
//    glDisable(GL_TEXTURE_2D); 
//
//    glutSwapBuffers();
//}
//
//// Reshape function (called when the window is resized)
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);                     // Set the viewport to the entire window
//    glMatrixMode(GL_PROJECTION);                // Switch to projection matrix
//    glLoadIdentity();                           // Reset the projection matrix
//
//    float aspect = (float)w / (float)h;         // Calculate aspect ratio
//    if (w >= h) {
//        glOrtho(-15.0 * aspect, 15.0 * aspect, -15.0, 15.0, -1.0, 1.0);
//    }
//    else {
//        glOrtho(-15.0, 15.0, -15.0 / aspect, 15.0 / aspect, -1.0, 1.0);
//    }
//
//    glMatrixMode(GL_MODELVIEW);                 // Switch back to model-view matrix
//}
//
//// Main function
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);                        // Initialize GLUT
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Double buffer and RGB mode
//    glutInitWindowSize(800, 600);                 // Set window size
//    glutCreateWindow("Simple OpenGL GLUT");       // Create window with title
//
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);         // Set background color
//
//   loadTexture("C:/Users/Majd/Desktop/Computer Science/programming/opengl/University project/OpenGL/res/textures/japan/front.jpg"); // Replace "texture.jpg" with the path to your texture file
//    
//    glutDisplayFunc(display);                     // Set display callback
//    glutReshapeFunc(reshape);                     // Set reshape callback
//    glutMainLoop();                               // Start the main loop
//
//    return 0;
//}


#include "Objects.h"
#include "Lighting.h"
#include "Textures.h"
#include "Scene.h"

#define GLUT_DISABLE_ATEXIT_HACK
#include <stdlib.h>
#include <GL/freeglut.h> 

void reshape(int w, int h);
void initScene();

// Initialize scene with objects
void initScene() {
    initializeSkyboxTextures();
    initializeTextures(); // Load textures
   
    initGL();             // Setup OpenGL properties 
    
}


// Window reshape callback
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

}

// Main function
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Restaurant Scene");

    // Initialize the scene
    initScene();

    // Register callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mouseMotion);

    // Enter the main loop
    glutMainLoop();

    return 0;
}
