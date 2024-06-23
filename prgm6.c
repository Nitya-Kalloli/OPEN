6.Develop a program to demonstrate Animation effects on simple objects.
#include <GL/glut.h>
#include <math.h> // Include math.h for M_PI constant
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// Global variables for object properties and animation
float rectX = -1.5f; // Initial x-position of the rectangle
float circleX = 1.5f; // Initial x-position of the circle
float angle = 0.0f; // Initial angle for rotating the circle
// Function to draw a rectangle
void drawRectangle() {
 glBegin(GL_POLYGON);
 glVertex2f(rectX, -0.5);
 glVertex2f(rectX + 1.0, -0.5);
 glVertex2f(rectX + 1.0, 0.5);
 glVertex2f(rectX, 0.5);
 glEnd();
}
// Function to draw a circle
void drawCircle() {
 glBegin(GL_POLYGON);
 for (int i = 0; i < 360; i++) {
 float theta = i * M_PI / 180.0;
 float x = circleX + 0.5 * cos(theta);
 float y = 0.0 + 0.5 * sin(theta);
 glVertex2f(x, y);
 }
 glEnd();
}
// Display function
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 
 glColor3f(1.0, 0.0, 0.0); // Red color for rectangle
 drawRectangle();
 glColor3f(0.0, 0.0, 1.0); // Blue color for circle
 glPushMatrix();
 glTranslatef(circleX, 0.0, 0.0);
 glRotatef(angle, 0.0, 0.0, 1.0);
 drawCircle();
 glPopMatrix();
 glutSwapBuffers();
}
// Update function for animation
void update(int value) {
 // Move the rectangle to the right
 rectX += 0.01f;
 if (rectX > 1.5)
 rectX = -1.5f; // Reset to the initial position if it goes out of the window
 // Move the circle to the left
 circleX -= 0.01f;
 if (circleX < -1.5)
 circleX = 1.5f; // Reset to the initial position if it goes out of the window
 // Rotate the circle
 angle += 1.0f;
 if (angle > 360)
 angle -= 360;
 glutPostRedisplay();
 glutTimerFunc(16, update, 0); // Update every 16 milliseconds (about 60 frames per second)
}
// Initialize OpenGL settings
void init() {
 glClearColor(1.0, 1.0, 1.0, 1.0); // White background
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-2.0, 2.0, -1.0, 1.0); // Set coordinate system
 glMatrixMode(GL_MODELVIEW);
}
// Main function
int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(800, 400);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Animation Effects on Simple Objects");
 init();
 glutDisplayFunc(display);
 glutTimerFunc(0, update, 0); // Start the animation
 glutMainLoop();
 return 0;
}
Compile:gcc p6.c -o p6 -lGL -lGLU -lglut -lm -std=c99
In this program:
• A red rectangle and a blue circle move across the screen from left to right and right to 
left, respectively.
• The circle also rotates continuously as it moves.
• The animation is achieved by updating the positions of the objects and the rotation 
angle in the update function, which is called periodically using glutTimerFunc