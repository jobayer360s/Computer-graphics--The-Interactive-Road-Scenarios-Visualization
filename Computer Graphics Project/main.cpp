#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>>
# define PI           3.14159265358979323846
#include<mmsystem.h>



//FOR SCENARIO 2

GLfloat jbcloudposition = 0.0f;
GLfloat jbcloudposition2 = 0.0f;
GLfloat jbsunposition = 0.0f;
GLfloat busposition = 0.0f;
GLfloat jbspeed = 0.007f;
GLfloat jbspeed2 = 0.003f;
GLfloat jbsunspeedY = 0.003f;

void jbMovement(int value) {

   if(jbcloudposition > 1.0)
        jbcloudposition = -1.0f;

    jbcloudposition += jbspeed;
    jbcloudposition2 += jbspeed2;

	glutPostRedisplay();


if(jbsunposition < -1.2)
        jbsunposition = 1.1f;

    jbsunposition -= jbsunspeedY;


	glutPostRedisplay();

if(busposition < -1.2)
        busposition = 1.1f;

    busposition -= jbsunspeedY;


	glutPostRedisplay();


	glutTimerFunc(100, jbMovement, 0);
}
void drawSun(float xPos, float yPos) {
    int i;
    GLfloat x = 0.0f, y = 0.0f;
    GLfloat radius = 0.06f;  // Reduced radius for smaller sun
    int triangleAmount = 300;
    GLfloat twicePi = 2.0f * PI;

    // Draw the sun's body (circle)
    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);  // Move sun to the specified position

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow color for the sun
    glVertex2f(x, y);  // Center of the sun
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();

}





void drawTreeJb(float xPos, float yPos) {
    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);


    glBegin(GL_QUADS);
    glColor3f(0.545f, 0.271f, 0.075f);
    glVertex2f(-0.00625f, -0.2f);
    glVertex2f(0.00625f, -0.2f);
    glVertex2f(0.00625f, 0.1f);
    glVertex2f(-0.00625f, 0.1f);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.8f, 0.0f);
    GLfloat radius = 0.05f;
    int triangleAmount = 100;


    glVertex2f(0.0f, 0.1f);
    for (int i = 0; i <= triangleAmount; i++) {
        GLfloat angle = i * 2.0f * PI / triangleAmount;
        glVertex2f(0.0f + (radius * cos(angle)), 0.1f + (radius * sin(angle)));
    }
    glEnd();

    glPopMatrix();
}

    void treeJb2(float x, float y) {
    int triangleAmount = 100; // Number of triangles used to draw the circle
    float twicePi = 2.0f * M_PI;

    glPushMatrix(); // Save the current transformation state
    glTranslatef(x, y, 0.0f); // Set position using x and y

    // Draw trunk (scaled down)
    glColor3f(0.55f, 0.27f, 0.07f); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(-0.0125f, -0.1f);
    glVertex2f(-0.0125f, 0.0f);
    glVertex2f(0.0125f, 0.0f);
    glVertex2f(0.0125f, -0.1f);
    glEnd();

    // Draw green parts (circles, scaled down)
    glColor3f(0.0f, 0.8f, 0.0f); // Green color

    // Bottom green part
    float radius = 0.0375f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.025f); // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            0.0f + (radius * cos(i * twicePi / triangleAmount)),
            0.025f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Middle green part
    radius = 0.03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.075f); // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            0.0f + (radius * cos(i * twicePi / triangleAmount)),
            0.075f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Top green part
    radius = 0.025f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.1125f); // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            0.0f + (radius * cos(i * twicePi / triangleAmount)),
            0.1125f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix(); // Restore the previous transformation state
}


void lampPost(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_POLYGON); // Lamp Post
    glColor3f(0.44f, 0.474f, 0.494f);
    glVertex2f(-0.795f, 0.85f);
    glVertex2f(-0.845f, 0.85f);
    glVertex2f(-0.845f, 0.86f);
    glVertex2f(-0.95f, 0.86f);
    glVertex2f(-0.95f, 0.83f);
    glVertex2f(-0.845f, 0.83f);
    glVertex2f(-0.845f, 0.84f);
    glVertex2f(-0.79f, 0.84f);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.78f, 0.02f);
    glVertex2f(-0.785f, 0.84f);
    glVertex2f(-0.7f, 0.84f);
    glVertex2f(-0.7f, 0.83f);
    glVertex2f(-0.61f, 0.83f);
    glVertex2f(-0.61f, 0.86f);
    glVertex2f(-0.7f, 0.86f);
    glVertex2f(-0.7f, 0.85f);
    glVertex2f(-0.785f, 0.85f);
    glVertex2f(-0.785f, 0.89f);
    glVertex2f(-0.795f, 0.89f);
    glEnd();




    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.845f, 0.80f);
    glVertex2f(-0.95f, 0.80f);
    glVertex2f(-0.95f, 0.830f);
    glVertex2f(-0.845f, 0.830f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.61f, 0.80f);
    glVertex2f(-0.71f, 0.80f);
    glVertex2f(-0.71f, 0.830f);
    glVertex2f(-0.61f, 0.830f);
    glEnd();
glPopMatrix();
}




void busLight(float x , float y)
{

int i;


	GLfloat radius =.025f;
	int triangleAmount = 100; //# of lines used to draw circle


	GLfloat twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();




}
void busLookingGlass(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.509804f, 0.270588f, 0.223529f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, -0.2f);
    glEnd();
    glPopMatrix();
}










void wheel(float x , float y){

int i;


	GLfloat radius =.05f;
	int triangleAmount = 1000;


	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();




}

void drawBus(float x, float y){



glPushMatrix();
glLoadIdentity();
glScalef(0.30,0.30,1);
glTranslatef(x,y,1);


//front glass
 glBegin(GL_QUADS);
 glColor3f(0.34902f, 0.337255f, 0.337255f);
 glVertex2f(0.4f,-0.2f);
 glVertex2f(0.8f,-0.2f);
 glVertex2f(0.8f,-0.5f);
 glVertex2f(0.4f,-0.5f);
 glEnd();

 //roff
  glBegin(GL_POLYGON);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.8f,-0.2f);
 glVertex2f(0.0f,0.2f);
 glVertex2f(-0.1f,0.15f);
 glVertex2f(-0.1f,0.0f);
 glVertex2f(0.4f,-0.2f);
 glEnd();

//side window
 glBegin(GL_QUADS);
 glColor3f(0.258824f, 0.25098f, 0.25098f);
 glVertex2f(0.4f,-0.2f);
 glVertex2f(0.4f,-0.5f);
 glVertex2f(-0.1f,-0.2f);
 glVertex2f(-0.1f,0.05f);

 glEnd();

 //wheel-1
wheel(0.32f,-0.65f);
 //wheel-2
wheel(0.0f,-0.45f);

//wheel-3
wheel(0.7f,-0.7f);

 //side Body
 glBegin(GL_QUADS);
 glColor3f(0.690196f, 0.278431f, 0.247059f);
 glVertex2f(0.4f,-0.5f);
 glVertex2f(0.4f,-0.7f);
 glVertex2f(-0.1f,-0.4f);
 glVertex2f(-0.1f,-0.2f);


 glEnd();

 //front engine place
glBegin(GL_QUADS);
 glColor3f(0.921569f, 0.27451f, 0.231373f);
 glVertex2f(0.4f,-0.5f);
 glVertex2f(0.8f,-0.5f);
  glVertex2f(0.8f,-0.7f);
 glVertex2f(0.4f,-0.7f);
 glEnd();

 busLight(0.45f,-0.6f);
 busLight(0.75f,-0.6f);

 //busLookingGlass(0.8f,-0.2f);
 //busLookingGlass(0.4f,-0.2f);





glPopMatrix();

}

//SCENARIO 3


GLfloat ABcloudposition = 0.0f;
GLfloat ABcloudposition2 = 0.2f;
GLfloat ABboatposition = 1.0f;
GLfloat ABcarposition = 0.0f;
GLfloat ABspeed = 0.007f;
GLfloat ABspeed2 = 0.003f;
GLfloat ABscale =0.7f;
void Cloud(float xPos, float yPos, float scale) {
    int i;
    GLfloat x = 0.0f, y = 0.0f;
    GLfloat radius = 0.1f * scale; // Scale the radius
    int triangleAmount = 300;
    GLfloat twicePi = 2.0f * PI;

    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);

    // Cloud component 1
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Cloud component 2
    glPushMatrix();
    glTranslatef(0.15f * scale, 0.0f, 0.0f); // Scale the translation
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    // Cloud component 3
    glPushMatrix();
    glTranslatef(0.11f * scale, 0.1f * scale, 0.0f); // Scale the translation
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
};



void ABMovement(int value) {

   if(ABcloudposition > 3.0)
   {
       ABcloudposition = -1.0f;


   }

    ABcloudposition += ABspeed;
    ABcloudposition2 += ABspeed2;



if(ABcarposition > 0.15)
   {
       ABcarposition = -1.0f;


   }

    ABcarposition += ABspeed;
if(ABboatposition < -0.6)
   {
       ABboatposition = 1.0f;

   }

    ABboatposition -= 0.01;
	glutPostRedisplay();
	glutTimerFunc(100, ABMovement, 0);
}


void boat() {
    glPushMatrix();

    // Apply transformations to adjust position, scale, and move right
    glTranslatef(0.5f, 0.3f, 0.0f); // Move the ship to the right
    glScalef(0.05f, 0.05f, 1.0f); // Scale down the ship to make it smaller

    // Hull (Curved & Detailed)
    glColor3f(0.6f, 0.3f, 0.1f); // Brown color for the hull
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.2f);  // Left side (far)
    glVertex2f(0.8f, -0.2f);   // Right side (near)
    glVertex2f(0.6f, -0.4f);
    glVertex2f(-0.6f, -0.4f);
    glEnd();





    // Deck
    glColor3f(0.9f, 0.9f, 0.9f); // Light gray color for the deck
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(-0.5f, -0.2f);
    glEnd();

    // Bridge (Control Room)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray color for bridge
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.3f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();

    // Windows on Deck
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for windows
    glBegin(GL_QUADS);
    for (float i = -0.4f; i <= 0.4f; i += 0.2f) {
        glVertex2f(i, 0.05f);
        glVertex2f(i + 0.1f, 0.05f);
        glVertex2f(i + 0.1f, -0.05f);
        glVertex2f(i, -0.05f);
    }
    glEnd();

    // Chimneys
    glColor3f(0.8f, 0.0f, 0.0f); // Red color for chimneys
    for (float i = -0.15f; i <= 0.15f; i += 0.3f) {
        glBegin(GL_QUADS);
        glVertex2f(i - 0.05f, 0.4f);
        glVertex2f(i + 0.05f, 0.4f);
        glVertex2f(i + 0.05f, 0.3f);
        glVertex2f(i - 0.05f, 0.3f);
        glEnd();
    }

    glPopMatrix();
};


void boat2() {
    glPushMatrix();

    // Apply transformations to adjust position, scale, and move right
    glTranslatef(0.5f, 0.3f, 0.0f); // Move the ship to the right
    glScalef(0.05f, 0.05f, 1.0f); // Scale down the ship to make it smaller

    // Hull (Curved & Detailed)
    glColor3f(0.6f, 0.3f, 0.6f); // Brown color for the hull
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.2f);  // Left side (far)
    glVertex2f(0.8f, -0.2f);   // Right side (near)
    glVertex2f(0.6f, -0.4f);
    glVertex2f(-0.6f, -0.4f);
    glEnd();





    // Deck
    glColor3f(0.9f, 0.9f, 0.9f); // Light gray color for the deck
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(-0.5f, -0.2f);
    glEnd();

    // Bridge (Control Room)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray color for bridge
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.3f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();

    // Windows on Deck
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for windows
    glBegin(GL_QUADS);
    for (float i = -0.4f; i <= 0.4f; i += 0.2f) {
        glVertex2f(i, 0.05f);
        glVertex2f(i + 0.1f, 0.05f);
        glVertex2f(i + 0.1f, -0.05f);
        glVertex2f(i, -0.05f);
    }
    glEnd();

    // Chimneys
    glColor3f(0.8f, 0.0f, 0.0f); // Red color for chimneys
    for (float i = -0.15f; i <= 0.15f; i += 0.3f) {
        glBegin(GL_QUADS);
        glVertex2f(i - 0.05f, 0.4f);
        glVertex2f(i + 0.05f, 0.4f);
        glVertex2f(i + 0.05f, 0.3f);
        glVertex2f(i - 0.05f, 0.3f);
        glEnd();
    }

    glPopMatrix();
};




void car(){

    glPushMatrix();
	glScalef(0.4,1,1);
	glTranslatef(-1.3f, -0.60f, 0.0f);
    GLfloat xc=-0.95f; GLfloat yc=0.5f; GLfloat radiusc =.07f;
	int triangleAmountc = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePic = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xc, yc); // center of circle
		for(int i = 0; i <= triangleAmountc;i++) {
			glVertex2f( xc + (radiusc * cos(i *  twicePic / triangleAmountc)),
                        yc + (radiusc * sin(i * twicePic / triangleAmountc)) );
		}
	glEnd();
	glPopMatrix();
// black window
 glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.8f, -0.2f );
    glVertex2f(-0.3f, 0.1f );
    glVertex2f(-0.35f, 0.2f);
    glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.55f, 0.32f, 0.65f);
    glVertex2f(-0.77f, 0.2f );
    glVertex2f(-0.54f, 0.1f);
    glVertex2f(-0.4f, 0.18f);
    glVertex2f(-0.55f, 0.25f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.309f, 0.65f);
    glVertex2f(-0.45f, 0.22f);
    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.25f, 0.18f );
    glVertex2f(-0.45f, 0.22f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.39f, 0.65f);
    glVertex2f(-0.55f, 0.25f );
    glVertex2f(-0.4f, 0.18f);
    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.45f, 0.22f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.49f, 0.65f);
    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.25f, 0.18f );
    glVertex2f(-0.25f, 0.08f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.368f, 0.57f);
    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.93f, -0.02f );
    glVertex2f(-0.93f, -0.15f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.309f, 0.6235f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.93f, -0.02f );
    glVertex2f(-0.85f, 0.05f );
    glVertex2f(-0.61f, -0.09f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.309f, 0.65f);
    glVertex2f(-0.61f, -0.09f);
    glVertex2f(-0.85f, 0.05f );
    glVertex2f(-0.77f, 0.2f );
    glVertex2f(-0.54f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.63f, -0.07f);
    glVertex2f(-0.83f, 0.05f );
    glVertex2f(-0.78f, 0.157f );
    glVertex2f(-0.58f, 0.07f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.75f, -0.27f);
    glVertex2f(-0.75f, -0.17f);
    glVertex2f(-0.89f, -0.078f );
    glVertex2f(-0.89f, -0.155f );
    glEnd();

    glBegin(GL_QUADS);// front back light
    glColor3f(1.0f, 0.368f, 0.57f);
    glVertex2f(-0.71f, -0.22f);
    glVertex2f(-0.71f, -0.18f);
    glVertex2f(-0.74f, -0.16f );
    glVertex2f(-0.74f, -0.2f );
    glEnd();

    glBegin(GL_QUADS);// front left light
    glColor3f(1.0f, 0.368f, 0.57f);
    glVertex2f(-0.9f, -0.12f);
    glVertex2f(-0.9f, -0.08f);
    glVertex2f(-0.92f, -0.05f );
    glVertex2f(-0.92f, -0.09f );
    glEnd();


    glPushMatrix();
    glScalef(0.5,1,1);
	glTranslatef(-0.23f, -0.75f, 0.5f);
    GLfloat xa=-0.95f; GLfloat ya=0.5f; GLfloat radiusa =.08f;
	int triangleAmounta = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePia = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xa, ya); // center of circle
		for(int i = 0; i <= triangleAmounta;i++) {
			glVertex2f( xa + (radiusa * cos(i *  twicePia / triangleAmounta)),
                        ya + (radiusa * sin(i * twicePia / triangleAmounta)) );
		}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.3,1,1);
	glTranslatef(-0.1f, -0.49f, 0.5f);
    GLfloat xb=-0.95f; GLfloat yb=0.5f; GLfloat radiusb =.06f;
	int triangleAmountb = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePib = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb); // center of circle
		for(int i = 0; i <= triangleAmountb;i++) {
			glVertex2f( xb + (radiusa * cos(i *  twicePib / triangleAmountb)),
                        yb + (radiusb * sin(i * twicePib / triangleAmountb)) );
		}
	glEnd();
	glPopMatrix();

};

void car2(){

    glPushMatrix();
	glScalef(0.4,1,1);
	glTranslatef(-1.1f, -0.69f, 0.5f);
    GLfloat xc=-0.95f; GLfloat yc=0.5f; GLfloat radiusc =.07f;
	int triangleAmountc = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePic = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xc, yc); // center of circle
		for(int i = 0; i <= triangleAmountc;i++) {
			glVertex2f( xc + (radiusc * cos(i *  twicePic / triangleAmountc)),
                        yc + (radiusc * sin(i * twicePic / triangleAmountc)) );
		}
	glEnd();
	glPopMatrix();
// black window
 glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.8f, -0.2f );
    glVertex2f(-0.3f, 0.1f );
    glVertex2f(-0.35f, 0.2f);
    glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.95f, 0.32f, 0.35f);
    glVertex2f(-0.77f, 0.2f );
    glVertex2f(-0.54f, 0.1f);
    glVertex2f(-0.4f, 0.18f);
    glVertex2f(-0.55f, 0.25f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.33f, 0.45f);
    glVertex2f(-0.45f, 0.22f);
    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.25f, 0.18f );
    glVertex2f(-0.45f, 0.22f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.33f, 0.45f);
    glVertex2f(-0.55f, 0.25f );
    glVertex2f(-0.4f, 0.18f);
    glVertex2f(-0.3f, 0.1f);
    glVertex2f(-0.45f, 0.22f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.97f, 0.52f, 0.25f);
    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.25f, 0.18f );
    glVertex2f(-0.25f, 0.08f );
    glEnd();

    glBegin(GL_QUADS);// front view
    glColor3f(0.95f, 0.33f, 0.45f);
    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.93f, -0.02f );
    glVertex2f(-0.93f, -0.15f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.33f, 0.45f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.93f, -0.02f );
    glVertex2f(-0.85f, 0.05f );
    glVertex2f(-0.61f, -0.09f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.99f, 0.3f, 0.55f);
    glVertex2f(-0.61f, -0.09f);
    glVertex2f(-0.85f, 0.05f );
    glVertex2f(-0.77f, 0.2f );
    glVertex2f(-0.54f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.63f, -0.07f);
    glVertex2f(-0.83f, 0.05f );
    glVertex2f(-0.77f, 0.177f );
    glVertex2f(-0.56f, 0.09f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.75f, -0.27f);
    glVertex2f(-0.75f, -0.17f);
    glVertex2f(-0.89f, -0.078f );
    glVertex2f(-0.89f, -0.155f );
    glEnd();

    glBegin(GL_QUADS);// front back light
    glColor3f(1.0f, 0.368f, 0.57f);
    glVertex2f(-0.71f, -0.22f);
    glVertex2f(-0.71f, -0.18f);
    glVertex2f(-0.74f, -0.16f );
    glVertex2f(-0.74f, -0.2f );
    glEnd();

    glBegin(GL_QUADS);// front left light
    glColor3f(1.0f, 0.368f, 0.57f);
    glVertex2f(-0.9f, -0.12f);
    glVertex2f(-0.9f, -0.08f);
    glVertex2f(-0.92f, -0.05f );
    glVertex2f(-0.92f, -0.09f );
    glEnd();

    glBegin(GL_QUADS);// front white look
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-0.69f, -0.36f);
    glVertex2f(-0.69f, -0.32f);
    glVertex2f(-0.94f, -0.11f );
    glVertex2f(-0.94f, -0.14f );
    glEnd();


    glPushMatrix();
    glScalef(0.5,1,1);
	glTranslatef(-0.23f, -0.75f, 0.5f);
    GLfloat xa=-0.95f; GLfloat ya=0.5f; GLfloat radiusa =.08f;
	int triangleAmounta = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePia = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xa, ya); // center of circle
		for(int i = 0; i <= triangleAmounta;i++) {
			glVertex2f( xa + (radiusa * cos(i *  twicePia / triangleAmounta)),
                        ya + (radiusa * sin(i * twicePia / triangleAmounta)) );
		}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.3,1,1);
	glTranslatef(-0.1f, -0.49f, 0.5f);
    GLfloat xb=-0.95f; GLfloat yb=0.5f; GLfloat radiusb =.06f;
	int triangleAmountb = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePib = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xb, yb); // center of circle
		for(int i = 0; i <= triangleAmountb;i++) {
			glVertex2f( xb + (radiusa * cos(i *  twicePib / triangleAmountb)),
                        yb + (radiusb * sin(i * twicePib / triangleAmountb)) );
		}
	glEnd();
	glPopMatrix();

};

void block(){ //River block


    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.816f);
    glVertex2f(-0.55f,-1.0f);
    glVertex2f(-0.37f,-1.03f);
    glVertex2f(-0.29f,-0.87f);
    glVertex2f(-0.45f,-0.84f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.894f, 0.894f, 0.7058f);
    glVertex2f(-0.55f,-1.0f);
    glVertex2f(-0.55f,-0.95f);
    glVertex2f(-0.52f,-0.96f);
    glVertex2f(-0.52f,-1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.894f, 0.894f, 0.7058f);
    glVertex2f(-0.37f,-1.03f);
    glVertex2f(-0.37f,-0.98f);
    glVertex2f(-0.4f,-0.97f);
    glVertex2f(-0.4f,-1.02f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.894f, 0.894f, 0.7058f);
    glVertex2f(-0.32f,-0.88f);
    glVertex2f(-0.32f,-0.82f);
    glVertex2f(-0.29f,-0.83f);
    glVertex2f(-0.29f,-0.87f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.894f, 0.894f, 0.7058f);
    glVertex2f(-0.42f,-0.85f);
    glVertex2f(-0.42f,-0.80f);
    glVertex2f(-0.45f,-0.79f);
    glVertex2f(-0.45f,-0.85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.45f,-0.95f);
    glVertex2f(-0.43f,-0.905f);
    glVertex2f(-0.38f,-0.91f);
    glVertex2f(-0.4f,-0.95f);
    glEnd();
    glPopMatrix();
};

void drawBlock(){
 glPushMatrix();
    glScalef(0.08,0.08,1);
    glTranslatef(0.7f,4.5f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15,0.15,1);
    glTranslatef(0.53f,2.7f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.25,0.25,1);
    glTranslatef(0.43f,1.85f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.35,0.35,1);
    glTranslatef(0.35f,1.43f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.48,0.48,1);
    glTranslatef(0.31f,1.14f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.54,0.54,1);
    glTranslatef(0.24f,0.96f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.66,0.66,1);
    glTranslatef(0.195f,0.8f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(0.12f,0.64f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.75,0.75,1);
    glTranslatef(0.059f,0.5f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(0.005f,0.36f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.88,0.88,1);
    glTranslatef(-0.035f,0.25f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.95,0.95,1);
    glTranslatef(-0.08f,0.13f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15f,0.0f,0.0f);
    block();
    glPopMatrix();
};

void drawBlock2(){


    glPushMatrix();
    glScalef(0.07,0.07,1);
    glTranslatef(-1.55f,5.73f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.11,0.11,1);
    glTranslatef(-0.79f,3.75f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15,0.15,1);
    glTranslatef(-0.5f,2.78f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.25,0.25,1);
    glTranslatef(-0.13f,1.89f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.35,0.35,1);
    glTranslatef(0.012f,1.47f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.48,0.48,1);
    glTranslatef(0.089f,1.16f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.54,0.54,1);
    glTranslatef(0.065f,0.97f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.66,0.66,1);
    glTranslatef(0.069f,0.81f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(0.015f,0.65f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.75,0.75,1);
    glTranslatef(-0.01f,0.51f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(-0.055f,0.37f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.88,0.88,1);
    glTranslatef(-0.075f,0.25f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.95,0.95,1);
    glTranslatef(-0.1f,0.13f,0.0f);
    block();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.16f,0.0f,0.0f);
    block();
    glPopMatrix();
};


void lampPost(){

    glBegin(GL_POLYGON);// Lamp Post
    glColor3f(0.95f, 0.953f, 0.949f);
    glVertex2f(-0.795f,0.85f);
    glVertex2f(-0.845f,0.85f);
    glVertex2f(-0.845f,0.86f);
    glVertex2f(-0.95f,0.86f);
    glVertex2f(-0.95f,0.83f);
    glVertex2f(-0.845f,0.83f);
    glVertex2f(-0.845f,0.84f);
    glVertex2f(-0.79f,0.84f);
    glVertex2f(-0.8f,0.0f);
    glVertex2f(-0.78f,0.02f);
    glVertex2f(-0.785f,0.84f);
    glVertex2f(-0.7f,0.84f);
    glVertex2f(-0.7f,0.83f);
    glVertex2f(-0.61f,0.83f);
    glVertex2f(-0.61f,0.86f);
    glVertex2f(-0.7f,0.86f);
    glVertex2f(-0.7f,0.85f);
    glVertex2f(-0.785f,0.85f);
    glVertex2f(-0.785f,0.89f);
    glVertex2f(-0.795f,0.89f);
    glEnd();
};



void tree1(){

glBegin(GL_POLYGON); // polygon of 1st tree
    glColor3f(0.8f, 0.5f, 0.45f);
    glVertex2f(-0.92f, 0.45f);
    glVertex2f(-0.89f, 0.55f);
    glVertex2f(-0.87f, 0.55f);
    glVertex2f(-0.9f, 0.45f);
    glVertex2f(-0.9f, 0.3f);
    glVertex2f(-0.94f, 0.3f);
    glVertex2f(-0.94f, 0.45f);
    glVertex2f(-0.97f, 0.55f);
    glVertex2f(-0.95f, 0.55f);
    glEnd();


glPushMatrix();
	glTranslatef(-0.06f, -0.01f, 0.0f);
	GLfloat x11=-0.9f; GLfloat y11=0.5f; GLfloat radius11 =.04f;
	int triangleAmount11 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glColor3f(0.75f, 0.45f, 0.4f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11); // center of circle
		for(int i = 0; i <= triangleAmount11;i++) {
			glVertex2f( x11 + (radius11 * cos(i *  twicePi11 / triangleAmount11)),
                        y11 + (radius11 * sin(i * twicePi11 / triangleAmount11)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


	GLfloat x=-0.95f; GLfloat y=0.5f; GLfloat radius =.04f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.863f, 0.514f, 0.458f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



    glPushMatrix();
	glTranslatef(+0.06f, 0.0f, 0.0f);
	GLfloat x1=-0.95f; GLfloat y1=0.5f; GLfloat radius1 =.03f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x1 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i * twicePi1 / triangleAmount1)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


    glPushMatrix();
	glTranslatef(-0.025f, 0.03f, 0.0f);
	GLfloat x2=-0.95f; GLfloat y2=0.5f; GLfloat radius2 =.05f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x2 + (radius2 * cos(i *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i * twicePi2 / triangleAmount2)) );
		}
	glEnd();
    glLoadIdentity();
    glPopMatrix();



    glPushMatrix();
	glTranslatef(0.07f, 0.05f, 0.0f);
	GLfloat x3=-0.95f; GLfloat y3=0.5f; GLfloat radius3 =.055f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x3 + (radius3 * cos(i *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i * twicePi3 / triangleAmount3)) );
		}
	glEnd();
    glLoadIdentity();
    glPopMatrix();


glPushMatrix();
	 glTranslatef(-0.08f, 0.06f, 0.0f);
	GLfloat x4=-0.9f; GLfloat y4=0.5f; GLfloat radius4 =.055f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x4 + (radius4 * cos(i *  twicePi4 / triangleAmount4)),
                        y4 + (radius4 * sin(i * twicePi4 / triangleAmount4)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();



    glPushMatrix();
    glTranslatef(-0.082f, 0.1f, 0.0f);
	GLfloat x5=-0.9f; GLfloat y5=0.5f; GLfloat radius5 =.055f;
	int triangleAmount5 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(0.85f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x5 + (radius5 * cos(i *  twicePi5 / triangleAmount5)),
                        y5 + (radius5 * sin(i * twicePi5 / triangleAmount5)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();



	 glPushMatrix();
	 glTranslatef(0.02f, 0.1f, 0.0f);
	GLfloat x6=-0.9f; GLfloat y6=0.5f; GLfloat radius6 =.05f;
	int triangleAmount6 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x6 + (radius6 * cos(i *  twicePi6 / triangleAmount6)),
                        y6 + (radius6 * sin(i * twicePi6 / triangleAmount6)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(-0.05f, 0.13f, 0.0f);
	GLfloat x7 =-0.9f; GLfloat y7=0.5f; GLfloat radius7 =.06f;
	int triangleAmount7 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x7 + (radius7 * cos(i *  twicePi7 / triangleAmount7)),
                        y7 + (radius7 * sin(i * twicePi7 / triangleAmount7)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


	 glPushMatrix();


	 glTranslatef(-0.01f, 0.13f, 0.0f);
	GLfloat x8 =-0.9f; GLfloat y8=0.5f; GLfloat radius8 =.06f;
	int triangleAmount8 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x8 + (radius8 * cos(i *  twicePi8 / triangleAmount8)),
                        y8 + (radius8 * sin(i * twicePi8 / triangleAmount8)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();

glPushMatrix();
	glTranslatef(-0.05f, 0.18f, 0.0f);
	GLfloat x9 =-0.9f; GLfloat y9=0.5f; GLfloat radius9 =.03f;
	int triangleAmount9 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x9 + (radius9 * cos(i *  twicePi9 / triangleAmount9)),
                        y9 + (radius9 * sin(i * twicePi9 / triangleAmount9)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();


    glPushMatrix();
	glTranslatef(-0.015f, 0.18f, 0.0f);
	GLfloat x10 =-0.9f; GLfloat y10=0.5f; GLfloat radius10 =.03f;
	int triangleAmount10 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x10 + (radius10 * cos(i *  twicePi10 / triangleAmount10)),
                        y10 + (radius10 * sin(i * twicePi10 / triangleAmount10)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.03f, 0.2f, 0.0f);
	GLfloat x111 =-0.9f; GLfloat y111=0.5f; GLfloat radius111 =.025f;
	int triangleAmount111 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi111 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x111, y111); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x111 + (radius111 * cos(i *  twicePi111 / triangleAmount111)),
                        y111 + (radius111 * sin(i * twicePi111 / triangleAmount111)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();/**/


};

//SCENARIO 3 END FUNCTION AND VARIABLE















//FOR SCENARIO 4
GLfloat cloudposition = 0.0f;
GLfloat cloudposition2 = 0.0f;
GLfloat carposition = -1.0f;
GLfloat car2position = 0.0f;
GLfloat carScale = 0.9f;
GLfloat car2Scale = 0.1f;
GLfloat sunposition = 0.0f;
GLfloat speed = 0.005f;
GLfloat speedd = 0.01f;
GLfloat speed2 = 0.002f;
GLfloat CArspeed = 0.005f;
GLfloat sunspeedY = 0.003f;
bool isPaused = false;
bool isSoundPlaying = false;


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		  speed = 0.3f;
	}
	if (button == GLUT_RIGHT_BUTTON)
	{

		speed = 0.005f;
	}
	glutPostRedisplay();
}
void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
speed = 0.3f;
//CArspeed=0.03f;
break;
case GLUT_KEY_DOWN:
    speed = 0.005f;
break;
case GLUT_KEY_END:
isPaused = !isPaused; // Toggle pause state
 if (isSoundPlaying) {
       PlaySound(NULL, 0, 0); // Stop sound
          isSoundPlaying = false;
    } else {
         PlaySound("sound.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP); // Start sound
             isSoundPlaying = true;
   }

break;
case GLUT_KEY_RIGHT:
break;
}
glutPostRedisplay();
}
void sound()
{
    isSoundPlaying=true;
    PlaySound("sound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void Movement(int value) {
if (!isPaused) {
   if(cloudposition > 1.2)
        cloudposition = -1.0f;

    cloudposition += speed;
    cloudposition2 += speed2;

	glutPostRedisplay();



if(sunposition > 1.0)
        sunposition = -0.5f;

    sunposition += sunspeedY;

}

	glutPostRedisplay();

	glutTimerFunc(100, Movement, 0);

}
void CarMovement(int value) {
if (!isPaused) {
   if(carposition >0.135)
   {
       carposition = -1.0f;
       carScale=1.0;
   }


    carposition += speed+0.008;
    carScale-=CArspeed+0.003;
}
	glutPostRedisplay();

	glutTimerFunc(100, CarMovement, 0);
}

void Car2Movement(int value) {
if (!isPaused) {
   if(car2position <-1.5)
   {
       car2position = -0.1f;
       car2Scale=0.1;
   }
    car2position -= speed;
    car2Scale+=CArspeed;
}
	glutPostRedisplay();
	glutTimerFunc(90, Car2Movement, 0);
}

void sun(GLfloat x,GLfloat y,GLfloat r)
{

    int i;

	GLfloat radius =r;
	int triangleAmount = 10000; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(1.0f, 0.4f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
}
void tree2(float x, float y) {
    int triangleAmount = 1000; // Number of triangles used to draw the circle
    float twicePi = 2.0f * M_PI;

    glPushMatrix(); // Save the current transformation state
    glTranslatef(x, y, 0.0f); // Set position using x and y

    // Draw trunk (scaled down)
    glColor3f(0.55f, 0.27f, 0.07f); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(-0.0125f, -0.1f);
    glVertex2f(-0.0125f, 0.0f);
    glVertex2f(0.0125f, 0.0f);
    glVertex2f(0.0125f, -0.1f);
    glEnd();

    // Draw green parts (circles, scaled down)
    glColor3f(0.0f, 0.8f, 0.0f); // Green color

    // Bottom green part
    float radius = 0.0375f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.025f); // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            0.0f + (radius * cos(i * twicePi / triangleAmount)),
            0.025f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Middle green part
    radius = 0.03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.075f); // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            0.0f + (radius * cos(i * twicePi / triangleAmount)),
            0.075f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Top green part
    radius = 0.025f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.1125f); // Center of the circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            0.0f + (radius * cos(i * twicePi / triangleAmount)),
            0.1125f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix(); // Restore the previous transformation state
}

void tree(){

glBegin(GL_POLYGON); // polygon of 1st tree
    glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green


    glVertex2f(-0.92f, 0.45f);
    glVertex2f(-0.89f, 0.55f);
    glVertex2f(-0.87f, 0.55f);
    glVertex2f(-0.9f, 0.45f);
    glVertex2f(-0.9f, 0.3f);
    glVertex2f(-0.94f, 0.3f);
    glVertex2f(-0.94f, 0.45f);
    glVertex2f(-0.97f, 0.55f);
    glVertex2f(-0.95f, 0.55f);
    glEnd();


glPushMatrix();
	glTranslatef(-0.06f, -0.01f, 0.0f);
	GLfloat x11=-0.9f; GLfloat y11=0.5f; GLfloat radius11 =.04f;
	int triangleAmount11 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11); // center of circle
		for(int i = 0; i <= triangleAmount11;i++) {
			glVertex2f( x11 + (radius11 * cos(i *  twicePi11 / triangleAmount11)),
                        y11 + (radius11 * sin(i * twicePi11 / triangleAmount11)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


	GLfloat x=-0.95f; GLfloat y=0.5f; GLfloat radius =.04f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();


    glPushMatrix();
	glTranslatef(+0.06f, 0.0f, 0.0f);
	GLfloat x1=-0.95f; GLfloat y1=0.5f; GLfloat radius1 =.03f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x1 + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i * twicePi1 / triangleAmount1)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


    glPushMatrix();
	glTranslatef(-0.025f, 0.03f, 0.0f);
	GLfloat x2=-0.95f; GLfloat y2=0.5f; GLfloat radius2 =.05f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x2 + (radius2 * cos(i *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i * twicePi2 / triangleAmount2)) );
		}
	glEnd();
    glLoadIdentity();
    glPopMatrix();


    glPushMatrix();
	glTranslatef(0.07f, 0.05f, 0.0f);
	GLfloat x3=-0.95f; GLfloat y3=0.5f; GLfloat radius3 =.055f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x3 + (radius3 * cos(i *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i * twicePi3 / triangleAmount3)) );
		}
	glEnd();
    glLoadIdentity();
    glPopMatrix();


glPushMatrix();
	 glTranslatef(-0.08f, 0.06f, 0.0f);
	GLfloat x4=-0.9f; GLfloat y4=0.5f; GLfloat radius4 =.055f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x4 + (radius4 * cos(i *  twicePi4 / triangleAmount4)),
                        y4 + (radius4 * sin(i * twicePi4 / triangleAmount4)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.082f, 0.1f, 0.0f);
	GLfloat x5=-0.9f; GLfloat y5=0.5f; GLfloat radius5 =.055f;
	int triangleAmount5 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x5 + (radius5 * cos(i *  twicePi5 / triangleAmount5)),
                        y5 + (radius5 * sin(i * twicePi5 / triangleAmount5)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


	 glPushMatrix();
	 glTranslatef(0.02f, 0.1f, 0.0f);
	GLfloat x6=-0.9f; GLfloat y6=0.5f; GLfloat radius6 =.05f;
	int triangleAmount6 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x6 + (radius6 * cos(i *  twicePi6 / triangleAmount6)),
                        y6 + (radius6 * sin(i * twicePi6 / triangleAmount6)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(-0.05f, 0.13f, 0.0f);
	GLfloat x7 =-0.9f; GLfloat y7=0.5f; GLfloat radius7 =.06f;
	int triangleAmount7 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glColor3f(0.2f, 0.8f, 0.2f);  // A bright, natural leaf green

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x7 + (radius7 * cos(i *  twicePi7 / triangleAmount7)),
                        y7 + (radius7 * sin(i * twicePi7 / triangleAmount7)) );
		}
	glEnd();
	 glLoadIdentity();
	 glPopMatrix();


	 glPushMatrix();


	 glTranslatef(-0.01f, 0.13f, 0.0f);
	GLfloat x8 =-0.9f; GLfloat y8=0.5f; GLfloat radius8 =.06f;
	int triangleAmount8 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x8 + (radius8 * cos(i *  twicePi8 / triangleAmount8)),
                        y8 + (radius8 * sin(i * twicePi8 / triangleAmount8)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();

glPushMatrix();
	glTranslatef(-0.05f, 0.18f, 0.0f);
	GLfloat x9 =-0.9f; GLfloat y9=0.5f; GLfloat radius9 =.03f;
	int triangleAmount9 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x9 + (radius9 * cos(i *  twicePi9 / triangleAmount9)),
                        y9 + (radius9 * sin(i * twicePi9 / triangleAmount9)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();


    glPushMatrix();
	glTranslatef(-0.015f, 0.18f, 0.0f);
	GLfloat x10 =-0.9f; GLfloat y10=0.5f; GLfloat radius10 =.03f;
	int triangleAmount10 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x10 + (radius10 * cos(i *  twicePi10 / triangleAmount10)),
                        y10 + (radius10 * sin(i * twicePi10 / triangleAmount10)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.03f, 0.2f, 0.0f);
	GLfloat x111 =-0.9f; GLfloat y111=0.5f; GLfloat radius111 =.025f;
	int triangleAmount111 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi111 = 2.0f * PI;

	glColor3f(0.86f, 0.51f, 0.45f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x111, y111); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( x111 + (radius111 * cos(i *  twicePi111 / triangleAmount111)),
                        y111 + (radius111 * sin(i * twicePi111 / triangleAmount111)) );
		}
	glEnd();
	 glLoadIdentity();
	glPopMatrix();/**/


};
void drawCar() {
    glPushMatrix(); // Save the current transformation matrix

    // Draw the car body
    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);  // Red color for the car body
        glVertex3f(-0.5f, 0.0f, 0.2f);    // Bottom left of the car
        glVertex3f(0.5f, 0.0f, 0.2f);     // Bottom right of the car
        glVertex3f(0.5f, 0.3f, 0.2f);     // Top right of the car
        glVertex3f(-0.5f, 0.3f, 0.2f);    // Top left of the car
    glEnd();

    // Draw the car roof
    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.0f, 0.0f);  // Same color for roof
        glVertex3f(-0.3f, 0.3f, 0.2f);    // Bottom left of the roof
        glVertex3f(0.3f, 0.3f, 0.2f);     // Bottom right of the roof
        glVertex3f(0.2f, 0.5f, 0.2f);     // Top right of the roof
        glVertex3f(-0.2f, 0.5f, 0.2f);    // Top left of the roof
    glEnd();

    // Draw the wheels
    float wheel_radius = 0.1f; // Radius of the wheels
    int num_segments = 50;     // Smoothness of the circles

    // Left wheel
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color for wheels
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(-0.4f, 0.0f, 0.1f); // Center of the left wheel
        for (int i = 0; i <= num_segments; i++) {
            float angle = 2.0f * 3.1415926f * i / num_segments;
            float x = wheel_radius * cos(angle);
            float y = wheel_radius * sin(angle);
            glVertex3f(-0.4f + x, y, 0.1f);
        }
    glEnd();

    // Right wheel
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.4f, 0.0f, 0.1f); // Center of the right wheel
        for (int i = 0; i <= num_segments; i++) {
            float angle = 2.0f * 3.1415926f * i / num_segments;
            float x = wheel_radius * cos(angle);
            float y = wheel_radius * sin(angle);
            glVertex3f(0.4f + x, y, 0.1f);
        }
    glEnd();

    glPopMatrix(); // Restore the transformation matrix
}
void drawCloud(float xPos, float yPos, float scale) {
    int i;
    GLfloat x = 0.0f, y = 0.0f;
    GLfloat radius = 0.1f * scale; // Scale the radius
    int triangleAmount = 300;
    GLfloat twicePi = 2.0f * PI;

    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);

    // Cloud component 1
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Cloud component 2
    glPushMatrix();
    glTranslatef(0.15f * scale, 0.0f, 0.0f); // Scale the translation
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    // Cloud component 3
    glPushMatrix();
    glTranslatef(0.11f * scale, 0.1f * scale, 0.0f); // Scale the translation
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}
//FOR SCENARIO 4












// Global variable to track the current scenario
int currentScenario = 1;

// Function prototypes for different scenarios
void scenario1();
void scenario2();
void scenario3();
void scenario4();
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void AddText(char *string,float x,float y, float z)
{


glColor3f(0.0,1.0,0.0);
char *c;
renderBitmapString(x, y, z, GLUT_BITMAP_TIMES_ROMAN_24, c=string);

}















// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen

    // Render the current scenario
    if (currentScenario == 1) {
        scenario1();
    } else if (currentScenario == 2) {
        scenario2();
    } else if (currentScenario == 3) {
        scenario3();
    }else if (currentScenario == 4) {
        scenario4();
    }

    glutSwapBuffers(); // Swap buffers for smooth rendering
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') {
        // Change to the next scenario
        currentScenario++;
        if (currentScenario > 4) {
            currentScenario = 1; // Loop back to the first scenario
        }
        glutPostRedisplay(); // Request a redisplay to update the screen
    }

     if (key == 'b' || key == 'B') {
        // Change to the next scenario
        currentScenario--;
        if (currentScenario < 1) {
            currentScenario = 4; // Loop back to the first scenario
        }
        glutPostRedisplay(); // Request a redisplay to update the screen
    }
}

// Scenario 1 rendering
void scenario1() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glColor3f(0.0,0.0,1.0);
renderBitmapString(-0.4, 0.6, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "American International University- Bangladesh");

glColor3f(0.0,0.0,0.50);
renderBitmapString(-0.4, 0.5, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "FACULTY OF SCIENCE & TECHNOLOGY");

glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.3, 0.4, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Department Of Computer Science");

glColor3f(1.0,0.20,0.0);
renderBitmapString(-0.25, 0.3, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Section-(E)     Group-(04) ");

glColor3f(0.0,0.0,1.0);
renderBitmapString(-0.3,0.2, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " CSE-4118:Computer Graphics ");

glColor3f(0.0,0.0,1.0);
renderBitmapString(-0.12,-0.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " Submitted to : " );

glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.2,-0.1, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "MAHFUJUR RAHMAN ");

glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.2,-0.370, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " Student information : ");

glColor3f(0.0,0.0,0.40);
renderBitmapString(-0.65,-0.470, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " SL                                         NAME                                                     ID ");


glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.65,-0.570, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " 10                              Saidur Rahman Labib                                  22-46654-1 ");


glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.65,-0.670, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " 26                                      Abu Sifat                                              22-48299-3 ");


glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.65,-0.770, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " 41                               Gazi Kurbanul Islam                                  22-49972-3");


glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.65,-0.870, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " 42                                Md.Jobayer Shaikh                                    23-50647-1");


glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.12f, -0.01f);    // x, y
	glVertex2f(-0.12f, -0.01f);    // x, y
	glEnd();



glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.5f);    // x, y
	glVertex2f(-0.7f, -0.5f);    // x, y
	glEnd();


glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.4f);    // x, y
	glVertex2f(-0.7f, -0.4f);    // x, y
	glEnd();


glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.6f);    // x, y
	glVertex2f(-0.7f, -0.6f);    // x, y
	glEnd();


glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.7f);    // x, y
	glVertex2f(-0.7f, -0.7f);    // x, y
	glEnd();


glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.8f);    // x, y
	glVertex2f(-0.7f, -0.8f);    // x, y
	glEnd();



glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.9f);    // x, y
	glVertex2f(-0.7f, -0.9f);    // x, y
	glEnd();


glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(-0.7f, -0.4f);    // x, y
	glVertex2f(-0.7f, -0.9f);    // x, y
	glEnd();


	glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.7f, -0.4f);    // x, y
	glVertex2f(0.7f, -0.9f);    // x, y
	glEnd();



glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(0.3f, -0.4f);    // x, y
	glVertex2f(0.3f, -0.9f);    // x, y
	glEnd();



glLineWidth(2);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.1f, 0.0f, 1.0f); // Red
	glVertex2f(-0.5f, -0.4f);    // x, y
	glVertex2f(-0.5f, -0.9f);    // x, y
	glEnd();
}




// Scenario 2 rendering
void scenario2() {
     glClearColor(0.012f,0.565f,0.77f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0f,jbsunposition,0.0f);
     drawSun(0.0f,1.0f);
     glPopMatrix();
     glLoadIdentity();


     glTranslatef(jbcloudposition,0.0f,0.0f);
       drawCloud(-0.8f, 0.8f,0.5f);
   drawCloud(-0.4f, 0.75f, 0.7f);
   drawCloud(0.5f, 0.8f,0.3f);

   drawCloud(-0.9f, 0.3f,0.3f);
   drawCloud(-0.7f, 0.4f, 0.3f);
   drawCloud(0.9f, 0.3f,0.3f);
   drawCloud(0.7f, 0.4f, 0.3f);
    glTranslatef(jbcloudposition2,0.0f,0.0f);
    drawCloud(-0.41f,0.87,0.5f);
glLoadIdentity();


//left sides tree
  drawTreeJb(-0.95f, -0.49f);
  drawTreeJb(-0.86f, -0.47f);
  drawTreeJb(-0.78f, -0.45f);
  drawTreeJb(-0.70f, -0.45f);


//right side tree
  drawTreeJb(0.95f, -0.49f);
  drawTreeJb(0.86f, -0.47f);
  drawTreeJb(0.78f, -0.45f);
  drawTreeJb(0.70f, -0.45f);


  // middle parts tree of back side
  treeJb2(-0.2f,-0.48f);
  treeJb2(-0.05f,-0.45f);
  treeJb2(0.2f,-0.48f);

    //outside rod lamposts
    glPushMatrix();
    glTranslatef(-0.1,-0.1f,0);
    glScalef(0.5f,0.5f,1);
	lampPost(-0.3f, -0.99f);
	lampPost(-0.4f, -0.89f);
	lampPost(-0.5f, -0.79f);
	//glLoadIdentity();
    glTranslatef(1.0,-0.1f,0);
	lampPost(0.7f, -0.99f);
	lampPost(0.8f, -0.89f);
	lampPost(0.9f, -0.79f);


	glPopMatrix();


	// drawing roads

	glBegin(GL_POLYGON);
	glColor3f(0.2745f,0.2745f,0.2745f);
	glVertex2f(-0.3f,-0.4f);
    glVertex2f(-1.0f,-0.7f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(1.0f,-0.7f);
    glVertex2f(0.3f,-0.4f);
	glEnd();

    //drawing middle part of two roads
    glBegin(GL_QUADS);
    glColor3f(0.396f,0.588f,0.639f);
    glVertex2f(0,-0.4f);
    glVertex2f(0.25,-1.0f);
    glVertex2f(-0.3f,-1.0f);
    glVertex2f(-0.1f,-0.4f);
    glEnd();

    glPushMatrix();
    treeJb2(-0.03f,-0.69f);
    treeJb2(-0.1f,-0.84f);
    treeJb2(0.03f,-0.84);
    treeJb2(-0.03f,-0.84f);
    treeJb2(0.03f,-0.99f);
    treeJb2(-0.03f,-0.99f);
    treeJb2(-0.09f,-0.99f);
    treeJb2(-0.1f,-0.99f);
    treeJb2(-0.16f,-0.99f);
    treeJb2(0.09f,-0.99f);

    glPopMatrix();


    //steel of middle

   //left
   glBegin(GL_QUADS);
   glColor3f(0.639f,0.639f,0.639f);
   glVertex2f(-0.3f,-1.0f);
   glVertex2f(-0.099f,-0.4f);
   glVertex2f(-0.049f,-0.4f);
   glVertex2f(-0.21f,-1.00f);
   glEnd();


   //right
   glBegin(GL_QUADS);
   glColor3f(0.639f,0.639f,0.639f);
   glVertex2f(0.25f,-1.0f);
   glVertex2f(-0.00f,-0.4f);
   glVertex2f(-0.038f,-0.4f);
   glVertex2f(0.16f,-1.00f);
   glEnd();


    //drawing road mark1

    glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex2f(-0.2f,-0.4f);
	glVertex2f(-1.0f,-1.0f);
	glEnd();

    //drawing road mark 2

    glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex2f(-1.0f,-0.77f);
	glVertex2f(-0.280f,-0.420f);
	glEnd();

	//drawing road mark 3

    glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex2f(-0.11f,-0.4f);
	glVertex2f(-0.32f,-1.0f);
	glEnd();

	//drawing road mark4

    glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex2f(0.01f,-0.41f);
	glVertex2f(0.28f,-1.0f);
	glEnd();

	//drawing road mark 5
	glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex2f(0.1f,-0.41f);
	glVertex2f(1.0f,-1.0f);
	glEnd();

	//drawing road mark6
    glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex2f(0.3f,-0.41f);
	glVertex2f(1.0f,-0.78f);
	glEnd();


    //drawing sides of two roads

    //left side
    glBegin(GL_QUADS);
    glColor3f(0.639f,0.639f,0.639f);
    glVertex2f(-0.3f,-0.3f);
    glVertex2f(-0.3f,-0.4f);
    glVertex2f(-1.0f,-0.76f);
    glVertex2f(-1.0f,-0.5f);
    glEnd();


     glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(-0.8f,-0.45f);
    glVertex2f(-0.8f,-0.65f);
    glVertex2f(-0.9f,-0.70f);
    glVertex2f(-0.9f,-0.475f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.82f,-0.455f);
    glVertex2f(-0.82f,-0.66f);
    glVertex2f(-0.81f,-0.66f);
    glVertex2f(-0.81f,-0.455f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.85f,-0.455f);
    glVertex2f(-0.85f,-0.67f);
    glVertex2f(-0.84f,-0.675f);
    glVertex2f(-0.84f,-0.455f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.87f,-0.460f);
    glVertex2f(-0.87f,-0.69f);
    glVertex2f(-0.88f,-0.69f);
    glVertex2f(-0.88f,-0.460f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(-0.6f,-0.39f);
    glVertex2f(-0.6f,-0.55f);
    glVertex2f(-0.7f,-0.60f);
    glVertex2f(-0.7f,-0.42f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.62f,-0.395f);
    glVertex2f(-0.62f,-0.57f);
    glVertex2f(-0.63f,-0.57f);
    glVertex2f(-0.63f,-0.40f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.66f,-0.40f);
    glVertex2f(-0.66f,-0.58f);
    glVertex2f(-0.65f,-0.58f);
    glVertex2f(-0.65f,-0.40f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.68f,-0.415f);
    glVertex2f(-0.68f,-0.595f);
    glVertex2f(-0.69f,-0.595f);
    glVertex2f(-0.69f,-0.415f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(-0.5f,-0.35f);
    glVertex2f(-0.5f,-0.50f);
    glVertex2f(-0.4f,-0.45f);
    glVertex2f(-0.4f,-0.325f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.425f,-0.327f);
    glVertex2f(-0.425f,-0.465f);
    glVertex2f(-0.415f,-0.465f);
    glVertex2f(-0.415f,-0.325f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.44f,-0.33f);
    glVertex2f(-0.44f,-0.472f);
    glVertex2f(-0.45f,-0.472f);
    glVertex2f(-0.45f,-0.33f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.48f,-0.34f);
    glVertex2f(-0.48f,-0.485f);
    glVertex2f(-0.47f,-0.485f);
    glVertex2f(-0.47f,-0.345f);
    glEnd();



    //Right side
    glBegin(GL_QUADS);
    glColor3f(0.639f,0.639f,0.639f);
    glVertex2f(0.3f,-0.3f);
    glVertex2f(0.3f,-0.4f);
    glVertex2f(1.0f,-0.76f);
    glVertex2f(1.0f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.8f,-0.45f);
    glVertex2f(0.8f,-0.65f);
    glVertex2f(0.9f,-0.70f);
    glVertex2f(0.9f,-0.475f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.82f,-0.455f);
    glVertex2f(0.82f,-0.66f);
    glVertex2f(0.81f,-0.66f);
    glVertex2f(0.81f,-0.455f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.85f,-0.455f);
    glVertex2f(0.85f,-0.67f);
    glVertex2f(0.84f,-0.675f);
    glVertex2f(0.84f,-0.455f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.87f,-0.460f);
    glVertex2f(0.87f,-0.69f);
    glVertex2f(0.88f,-0.69f);
    glVertex2f(0.88f,-0.460f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.6f,-0.39f);
    glVertex2f(0.6f,-0.55f);
    glVertex2f(0.7f,-0.60f);
    glVertex2f(0.7f,-0.42f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.62f,-0.395f);
    glVertex2f(0.62f,-0.57f);
    glVertex2f(0.63f,-0.57f);
    glVertex2f(0.63f,-0.40f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.66f,-0.40f);
    glVertex2f(0.66f,-0.58f);
    glVertex2f(0.65f,-0.58f);
    glVertex2f(0.65f,-0.40f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.68f,-0.415f);
    glVertex2f(0.68f,-0.595f);
    glVertex2f(0.69f,-0.595f);
    glVertex2f(0.69f,-0.415f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.5f,-0.35f);
    glVertex2f(0.5f,-0.50f);
    glVertex2f(0.4f,-0.45f);
    glVertex2f(0.4f,-0.325f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.425f,-0.327f);
    glVertex2f(0.425f,-0.465f);
    glVertex2f(0.415f,-0.465f);
    glVertex2f(0.415f,-0.325f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.44f,-0.33f);
    glVertex2f(0.44f,-0.472f);
    glVertex2f(0.45f,-0.472f);
    glVertex2f(0.45f,-0.33f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.48f,-0.34f);
    glVertex2f(0.48f,-0.485f);
    glVertex2f(0.47f,-0.485f);
    glVertex2f(0.47f,-0.345f);
    glEnd();



  //drawing traffic lightsleft

   // Traffic light-1
  glBegin(GL_QUADS);
  glColor3f(0.44f, 0.474f, 0.494f);
  glVertex2f(-0.9f, -0.5f);
  glVertex2f(-0.88f, -0.5f);
  glVertex2f(-0.878f, 0.65f);
  glVertex2f(-0.89f, 0.65f);
  glEnd();


  glBegin(GL_QUADS);
    glColor3f(0.44f, 0.474f, 0.494f);
  glVertex2f(-0.878f, 0.65f);
  glVertex2f(-0.7f, 0.67f);
  glVertex2f(-0.7f, 0.63f);
  glVertex2f(-0.878f, 0.65f);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.929412f, 0.882353f, 0.772549f);
  glVertex2f(-0.8f, 0.65f);
  glVertex2f(-0.8f, 0.62f);
  glVertex2f(-0.7f, 0.62f);
  glVertex2f(-0.7f, 0.65f);
  glEnd();

//Traffic light-2
glPushMatrix();
glLoadIdentity(); // Reset the model-view matrix
glTranslatef(-0.35f, -0.17f, 0); // Translate to a new position
glScalef(0.3f, 0.5f, 1);     // Scale uniformly
glBegin(GL_QUADS);
glColor3f(0.44f, 0.474f, 0.494f);
glVertex2f(-0.9f, -0.5f);
glVertex2f(-0.88f, -0.5f);
glVertex2f(-0.878f, 0.65f);
glVertex2f(-0.89f, 0.65f);
glEnd();

glBegin(GL_QUADS);
glVertex2f(-0.878f, 0.65f);
glVertex2f(-0.7f, 0.67f);
glVertex2f(-0.7f, 0.63f);
glVertex2f(-0.878f, 0.65f);
glEnd();
 glBegin(GL_QUADS);
  glColor3f(0.929412f, 0.882353f, 0.772549f);
  glVertex2f(-0.8f, 0.65f);
  glVertex2f(-0.8f, 0.62f);
  glVertex2f(-0.7f, 0.62f);
  glVertex2f(-0.7f, 0.65f);
  glEnd();

glPopMatrix();



   //traffic light 3
glPushMatrix();
glLoadIdentity();
glTranslatef(-0.1f, -0.15f, 0);
glScalef(0.3f, 0.4f, 1);
glBegin(GL_QUADS);
glColor3f(0.44f, 0.474f, 0.494f);
glVertex2f(-0.9f, -0.5f);
glVertex2f(-0.88f, -0.5f);
glVertex2f(-0.878f, 0.65f);
glVertex2f(-0.89f, 0.65f);
glEnd();

glBegin(GL_QUADS);
glVertex2f(-0.878f, 0.65f);
glVertex2f(-0.7f, 0.67f);
glVertex2f(-0.7f, 0.63f);
glVertex2f(-0.878f, 0.65f);
glEnd();

 glBegin(GL_QUADS);
  glColor3f(0.929412f, 0.882353f, 0.772549f);
  glVertex2f(-0.8f, 0.65f);
  glVertex2f(-0.8f, 0.62f);
  glVertex2f(-0.7f, 0.62f);
  glVertex2f(-0.7f, 0.65f);
  glEnd();

glPopMatrix();




    //drawing traffic lightsRight

    //traffic light-1
    glBegin(GL_QUADS);
    glColor3f(0.44f,0.474f,0.494f);
    glVertex2f(0.9f,-0.5f);
    glVertex2f(0.88f,-0.5f);
    glVertex2f(0.878f,0.65f);
    glVertex2f(0.89f,0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.878f,0.65f);
    glVertex2f(0.7f,0.67f);
    glVertex2f(0.7f,0.63f);
    glVertex2f(0.878f,0.65f);
    glEnd();
    glPushMatrix();

     glBegin(GL_QUADS);
  glColor3f(0.929412f, 0.882353f, 0.772549f);
  glVertex2f(0.8f, 0.65f);
  glVertex2f(0.8f, 0.62f);
  glVertex2f(0.7f, 0.62f);
  glVertex2f(0.7f, 0.65f);
  glEnd();

  // Traffic light-2
glPushMatrix();
glLoadIdentity();
glTranslatef(0.35f, -0.13f, 0);
glScalef(0.3f, 0.5f, 1);
glBegin(GL_QUADS);
glColor3f(0.44f, 0.474f, 0.494f);
glVertex2f(0.9f, -0.5f);
glVertex2f(0.88f, -0.5f);
glVertex2f(0.878f, 0.65f);
glVertex2f(0.89f, 0.65f);
glEnd();

glBegin(GL_QUADS);
glVertex2f(0.878f, 0.65f);
glVertex2f(0.7f, 0.67f);
glVertex2f(0.7f, 0.63f);
glVertex2f(0.878f, 0.65f);
glEnd();

 glBegin(GL_QUADS);
  glColor3f(0.929412f, 0.882353f, 0.772549f);
  glVertex2f(0.8f, 0.65f);
  glVertex2f(0.8f, 0.62f);
  glVertex2f(0.7f, 0.62f);
  glVertex2f(0.7f, 0.65f);
  glEnd();

glPopMatrix();

//traffic light 3
glPushMatrix();
glLoadIdentity();
glTranslatef(0.15f, -0.13f, 0);
glScalef(0.3f, 0.4f, 1);
glBegin(GL_QUADS);
glColor3f(0.44f, 0.474f, 0.494f);
glVertex2f(0.9f, -0.5f);
glVertex2f(0.88f, -0.5f);
glVertex2f(0.878f, 0.65f);
glVertex2f(0.89f, 0.65f);
glEnd();

glBegin(GL_QUADS);
glVertex2f(0.878f, 0.65f);
glVertex2f(0.7f, 0.67f);
glVertex2f(0.7f, 0.63f);
glVertex2f(0.878f, 0.65f);
glEnd();
 glBegin(GL_QUADS);
  glColor3f(0.929412f, 0.882353f, 0.772549f);
  glVertex2f(0.8f, 0.65f);
  glVertex2f(0.8f, 0.62f);
  glVertex2f(0.7f, 0.62f);
  glVertex2f(0.7f, 0.65f);
  glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,busposition,0.0f);
drawBus(0.1f,-0.9f);
glPopMatrix();

}





// Scenario 3 rendering
void scenario3() {

	glPushMatrix();
    glTranslatef(ABcloudposition,0.0f,0.0f);
    Cloud(-1.0f,0.8f,0.2f);
    Cloud(-0.8f,0.75f,0.2f);
    Cloud(-0.9f,0.9f,0.3f);
    Cloud(-0.21f,0.77,0.4f);
    glTranslatef(ABcloudposition2,0.0f,0.0f);
    Cloud(-0.41f,0.87,0.5f);
    glLoadIdentity();
    glPopMatrix();


    glBegin(GL_QUADS); // Set background of sea
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(-1.0f, 0.3f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();




    tree1();


    glPushMatrix();
     glScalef(0.9,0.86,1);
	 glTranslatef(+0.2f, -0.0f, 0.0f);
     tree1();
     glLoadIdentity();
     glPopMatrix();


     glPushMatrix();
     glScalef(0.6,0.6,1);
     glTranslatef(+0.2f, 0.2f, 0.0f);
     tree1();
     glLoadIdentity();
     glPopMatrix();


     glPushMatrix();
     glScalef(0.4,0.4,1);
     glTranslatef(+0.3f, 0.4f, 0.0f);
     tree1();
     glLoadIdentity();
     glPopMatrix();


     glPushMatrix();
     glScalef(0.2,0.2,1);
     glTranslatef(+0.2f, 0.7f, 0.0f);
     tree1();
     glLoadIdentity();
     glPopMatrix();


    glBegin(GL_QUADS); // Set background of road
    glColor3f(0.635f, 0.635f, 0.611f);
    glVertex2f(-1.0f, 0.3f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glEnd();


    glBegin(GL_TRIANGLES); // Set background of right side road left  white border
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.12f);
    glVertex2f(-1.0f, -0.13f);
    glVertex2f(-0.1f, 0.3f);
    glEnd();

    glBegin(GL_QUADS); // next 4 ->Set background of right side road middle border
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.35f);
    glVertex2f(-1.0f, -0.38f);
    glVertex2f(-0.76f, -0.202);
    glVertex2f(-0.768f, -0.189);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.7f, -0.14f);
    glVertex2f(-0.69f, -0.15f);
    glVertex2f(-0.455f, 0.012f);
    glVertex2f(-0.461f, 0.019f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.69f, -0.15f);
    glVertex2f(-0.455f, 0.012f);
    glVertex2f(-0.461f, 0.019f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.42f, 0.049f);
    glVertex2f(-0.41f, 0.045f);
    glVertex2f(-0.24f, 0.165f);
    glVertex2f(-0.245f, 0.17f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.213f, 0.19f);
    glVertex2f(-0.04f, 0.3f);
    glVertex2f(-0.21f, 0.183f);
    glEnd();

    glBegin(GL_TRIANGLES); // Set background of left side road left  white border
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, 0.29f);
    glVertex2f(-1.0f, 0.28f);
    glVertex2f(-0.27f, 0.3f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.7f,0.2f,-0.0f);
    glScalef(0.3,0.3,0.3);
    car2();
    glPopMatrix();



    // lamp post
    lampPost();

     glPushMatrix();
     glScalef(0.65,0.65,1);
     glTranslatef(+0.27f, 0.33f, 0.0f);
     lampPost();
     glLoadIdentity();
     glPopMatrix();


     glPushMatrix();
     glScalef(0.4,0.4,1);
     glTranslatef(+0.5f, 0.72f, 0.0f);
     lampPost();
     glLoadIdentity();
     glPopMatrix();





    glBegin(GL_TRIANGLES); // Set background of middle border of road
    glColor3f(0.99f, 0.92f, 0.69f);
    glVertex2f(-1.0f, 0.032f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.1f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); // Set background of right side road right white border
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(-0.01f, 0.3f);
    glEnd();

//CAR 1 CALLING
     glPushMatrix();
     glTranslatef(ABcarposition,ABcarposition , 0.0f);
     glTranslatef(-0.09f, 0.1f, 0.0f);
     glScalef(0.7,0.8,1);
     glScalef(ABscale,ABscale,0.0);
     car();
     glPopMatrix();

    glBegin(GL_QUADS); // Next 3 are the set background of right border of right side road
    glColor3f(0.88f, 0.92f, 0.74f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.95f, -1.0f);
    glVertex2f(0.0f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.94f, 0.93f, 0.82f);
    glVertex2f(-0.95f, -1.0f);
    glVertex2f(-0.85f, -1.0f);
    glVertex2f(0.0f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.74f, 0.73f, 0.72f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.85f, -1.0f);
    glVertex2f(-0.45f, -1.0f);
    glVertex2f(0.01f, 0.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.74f, 0.73f, 0.72f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.85f, -1.0f);
    glVertex2f(-0.45f, -1.0f);
    glVertex2f(0.03f, 0.3f);
    glEnd();

   drawBlock();


   glPushMatrix();
   glTranslatef(0.18f,-0.05f,0.0f);
   drawBlock2();
   glPopMatrix();
boat();
glPushMatrix();
glTranslatef(ABboatposition,0.0f,0.0f);

   glTranslatef(0.1f, -0.25f,1.0f);
   glScalef(1.5f,1.8f,1.0f);
   boat2();




glPopMatrix();
}
// Scenario 3 END




//Scenario 4
void scenario4() {

    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // R, G, B, Alpha (fully opaque)
    glClear(GL_COLOR_BUFFER_BIT);           // Clear the color buffer (background)

//SUN
     glPushMatrix();
    glTranslatef(0.0f,sunposition,0.0f);
    sun(0.06f,0.1f,0.08f);
    glPopMatrix();
//SUN
    // Draw the central road divider (black triangle)
    glBegin(GL_TRIANGLES);
        glColor3f(0.30f, 0.30f, 0.30f);    // Black color
        glVertex2f(0.0f, 0.0f);         // Top point
        glVertex2f(-0.02f, -1.0f);      // Bottom-left point
        glVertex2f(0.02f, -1.0f);       // Bottom-right point
    glEnd();

    // Draw the left yellow road edge
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f);    // Yellow color
        glVertex2f(0.0f, 0.0f);         // Top point
        glVertex2f(-0.02f, -1.0f);      // Bottom-right point
        glVertex2f(-0.045f, -1.0f);     // Bottom-left point
    glEnd();

    // Draw the right yellow road edge
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f);    // Yellow color
        glVertex2f(0.0f, 0.0f);         // Top point                    1111111111111111111111111111
        glVertex2f(0.02f, -1.0f);       // Bottom-left point
        glVertex2f(0.045f, -1.0f);      // Bottom-right point
    glEnd();

    // Draw the left side of the road
    glBegin(GL_QUADS);
        glColor3f(0.30f, 0.30f, 0.30f);    // Black color
        glVertex2f(0.0f, 0.0f);         // Top-right point
        glVertex2f(-0.1f, 0.0f);        // Top-left point
        glVertex2f(-1.0f, -1.0f);       // Bottom-left point
        glVertex2f(-0.045f, -1.0f);     // Bottom-right point
    glEnd();

    // Draw the all black right side of the road
    glBegin(GL_QUADS);
        glColor3f(0.30f, 0.30f, 0.30f);    // Black color
        glVertex2f(0.0f, 0.0f);         // Top-left point
        glVertex2f(0.1f, 0.0f);         // Top-right point              1111111111111111111111111111111
        glVertex2f(1.0f, -1.0f);        // Bottom-right point
        glVertex2f(0.045f, -1.0f);      // Bottom-left point
    glEnd();

    // Draw left white road stripe (triangular dash)
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);    // White color
        glVertex2f(-0.05f, 0.0f);       // Top point
        glVertex2f(-0.52f, -1.0f);      // Bottom-left point
        glVertex2f(-0.54f, -1.0f);      // Bottom-right point
    glEnd();
     // Draw right white road stripe (triangular dash)
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);    // White color
        glVertex2f(0.05f, 0.0f);        // Top point
        glVertex2f(0.52f, -1.0f);       // Bottom-left point
        glVertex2f(0.54f, -1.0f);       // Bottom-right point                   //11111111111111111
    glEnd();

    //Footpath left side
    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.77f, 0.53f); // RGB: 222, 184, 135
        glVertex2f(-0.1f, 0.0f);        // Top-left point
        glVertex2f(-0.12f, 0.0f);         // Top-right point
        glVertex2f(-1.0f, -0.75f);        // Bottom-right point
        glVertex2f(-1.0f, -1.0f);      // Bottom-left point
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.80f, 0.60f, 0.50f); // RGB: 222, 184, 135
        glVertex2f(-0.1f, 0.0f);        // Top-left point
        glVertex2f(-0.11f, 0.0f);         // Top-right point
        glVertex2f(-1.0f, -0.95f);        // Bottom-right point
        glVertex2f(-1.0f, -1.0f);      // Bottom-left point
    glEnd();


    //First Building left side
    glBegin(GL_QUADS);
    glColor3f(0.498f, 0.592f, 0.635f);
        glVertex2f(-0.66f, 0.900f);
        glVertex2f(-0.66f, -0.465f);
        glVertex2f(-1.0f, -0.75f);
        glVertex2f(-1.0f, .900f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(-0.66f,- 0.200f);
        glVertex2f(-0.66f, -0.430f);
        glVertex2f(-1.0f, -0.65f);
        glVertex2f(-1.0f,- 0.200f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.81f, 0.92f);
      glVertex2f(-0.66f, 0.850f);
        glVertex2f(-0.66f, 0.700f);
        glVertex2f(-1.0f, 0.700f);
        glVertex2f(-1.0f, 0.850f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.0f, 0.81f, 0.92f);
        glVertex2f(-0.66f, 0.650f);
        glVertex2f(-0.66f, 0.500f);
        glVertex2f(-1.0f, 0.500f);
        glVertex2f(-1.0f, 0.650f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0f, 0.81f, 0.92f);
        glVertex2f(-0.66f, 0.450f);
        glVertex2f(-0.66f, 0.300f);
        glVertex2f(-1.0f, 0.300f);
        glVertex2f(-1.0f, 0.450f);
    glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.81f, 0.92f);
        glVertex2f(-0.66f, 0.250f);
        glVertex2f(-0.66f, 0.100f);
        glVertex2f(-1.0f, 0.100f);
        glVertex2f(-1.0f, 0.250f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.81f, 0.92f);
        glVertex2f(-0.66f, 0.050f);
        glVertex2f(-0.66f, -0.100f);
        glVertex2f(-1.0f, -0.100f);
        glVertex2f(-1.0f, 0.050f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(-0.66f, -0.200f);
        glVertex2f(-0.66f,- 0.300f);
        glVertex2f(-1.0f, -0.300f);
        glVertex2f(-1.0f, -0.200f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.498f, 0.592f, 0.635f);
        glVertex2f(-0.93f, 0.900f);
        glVertex2f(-0.93f, -0.67f);
        glVertex2f(-0.95f, -0.69f);
        glVertex2f(-0.95f, 0.900f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.498f, 0.592f, 0.635f);
        glVertex2f(-0.75f, 0.900f);
        glVertex2f(-0.75f, -0.53f);
        glVertex2f(-0.77f, -0.55f);
        glVertex2f(-0.77f, 0.900f);
    glEnd();



//2nd

glBegin(GL_QUADS);
    glColor3f(0.408f, 0.502f, 0.605f);
        glVertex2f(-0.60f, 0.900f);
        glVertex2f(-0.60f, -0.410f);
        glVertex2f(-0.66f, -0.465f);
        glVertex2f(-0.66f, 0.900f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.629f, 0.900f);
        glVertex2f(-0.629f, -0.430f);
        glVertex2f(-0.631f, -0.440f);
        glVertex2f(-0.631f, 0.900f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.850f);
        glVertex2f(-0.60f, 0.848f);
        glVertex2f(-0.66f, 0.848f);
        glVertex2f(-0.66f, 0.850f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.750f);
        glVertex2f(-0.60f, 0.748f);
        glVertex2f(-0.66f, 0.748f);
        glVertex2f(-0.66f, 0.750f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.650f);
        glVertex2f(-0.60f, 0.648f);
        glVertex2f(-0.66f, 0.648f);
        glVertex2f(-0.66f, 0.650f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.550f);
        glVertex2f(-0.60f, 0.548f);
        glVertex2f(-0.66f, 0.548f);
        glVertex2f(-0.66f, 0.550f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.450f);
        glVertex2f(-0.60f, 0.448f);
        glVertex2f(-0.66f, 0.448f);
        glVertex2f(-0.66f, 0.450f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.350f);
        glVertex2f(-0.60f, 0.348f);
        glVertex2f(-0.66f, 0.348f);
        glVertex2f(-0.66f, 0.350f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.250f);
        glVertex2f(-0.60f, 0.248f);
        glVertex2f(-0.66f, 0.248f);
        glVertex2f(-0.66f, 0.250f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.150f);
        glVertex2f(-0.60f, 0.148f);
        glVertex2f(-0.66f, 0.148f);
        glVertex2f(-0.66f, 0.150f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.050f);
        glVertex2f(-0.60f, 0.048f);
        glVertex2f(-0.66f, 0.048f);
        glVertex2f(-0.66f, 0.050f);
    glEnd();


 //3th
    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(-0.60f, 0.900f);
        glVertex2f(-0.60f, -0.410f);
        glVertex2f(-0.35f, -0.200f);
        glVertex2f(-0.35f, 0.900f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.81f, .92f);
        glVertex2f(-0.42f, 0.880f);
        glVertex2f(-0.42f, -0.250f);
        glVertex2f(-0.36f, -0.210f);
        glVertex2f(-0.36f, 0.880f);
    glEnd();


    glBegin(GL_QUADS);
  glColor3f(0.73f, 0.81f, 0.62f);
        glVertex2f(-0.393f, 0.880f);
        glVertex2f(-0.393f, -0.250f);
        glVertex2f(-0.387f, -0.210f);
        glVertex2f(-0.387f, 0.880f);
    glEnd();


glBegin(GL_QUADS);
  glColor3f(0.0f, 0.81f, 0.92f);
        glVertex2f(-0.46f, 0.880f);
        glVertex2f(-0.46f, -0.240f);
        glVertex2f(-0.52f, -0.210f);
        glVertex2f(-0.52f, 0.880f);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.73f, 0.81f, 0.62f);
        glVertex2f(-0.487f, 0.880f);
        glVertex2f(-0.487f, -0.240f);
        glVertex2f(-0.493f, -0.210f);
        glVertex2f(-0.493f, 0.880f);
    glEnd();




//4th
glBegin(GL_QUADS);
    glColor3f(0.00f, 0.70f, 0.80f);
        glVertex2f(-0.60f, .900f);
        glVertex2f(-0.60f, -0.410f);
        glVertex2f(-0.40f, -0.240f);
        glVertex2f(-0.40f, 0.700f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.555f, 0.850f);
        glVertex2f(-0.555f, -0.360f);
        glVertex2f(-0.557f, -0.360f);
        glVertex2f(-0.557f, 0.850f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.455f, 0.750f);
        glVertex2f(-0.455f, -0.280f);
        glVertex2f(-0.457f, -0.280f);
        glVertex2f(-0.457f, 0.750f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.505f, .800f);
        glVertex2f(-0.505f, -0.320f);
        glVertex2f(-0.507f, -0.320f);
        glVertex2f(-0.507f, 0.800f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.415f, .710f);
        glVertex2f(-0.415f, -0.2500f);
        glVertex2f(-0.417f, -0.250f);
        glVertex2f(-0.417f, 0.710f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, .700f);
        glVertex2f(-0.60f, 0.702f);
        glVertex2f(-0.40f, 0.590f);
        glVertex2f(-0.40f, 0.592f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.500f);
        glVertex2f(-0.60f, 0.502f);
        glVertex2f(-0.40f, 0.390f);
        glVertex2f(-0.40f, 0.392f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.300f);
        glVertex2f(-0.60f, 0.302f);
        glVertex2f(-0.40f, 0.190f);
        glVertex2f(-0.40f, 0.192f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, 0.050f);
        glVertex2f(-0.60f, 0.052f);
        glVertex2f(-0.40f, -0.000f);
        glVertex2f(-0.40f, -0.002f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.308f, 0.502f, 0.790f);
        glVertex2f(-0.60f, -0.200f);
        glVertex2f(-0.60f, -0.202f);
        glVertex2f(-0.40f, -0.190f);
        glVertex2f(-0.40f, -0.192f);
    glEnd();



//5th
    glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.800f);
        glVertex2f(-0.25f, -0.110f);
        glVertex2f(-0.35f, -0.200f);
        glVertex2f(-0.35f, 0.900f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.80f, 0.90f);
        glVertex2f(-0.27f, 0.770f);
        glVertex2f(-0.27f, -0.105f);
        glVertex2f(-0.33f, -0.150f);
        glVertex2f(-0.33f, 0.830f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.700f);
        glVertex2f(-0.25f, 0.680f);
        glVertex2f(-0.35f, 0.680f);
        glVertex2f(-0.35f, 0.700f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.600f);
        glVertex2f(-0.25f, 0.580f);
        glVertex2f(-0.35f, 0.580f);
        glVertex2f(-0.35f, 0.600f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.500f);
        glVertex2f(-0.25f, 0.480f);
        glVertex2f(-0.35f, 0.480f);
        glVertex2f(-0.35f, 0.500f);
    glEnd();


glBegin(GL_QUADS);
   glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.400f);
        glVertex2f(-0.25f, 0.380f);
        glVertex2f(-0.35f, 0.380f);
        glVertex2f(-0.35f, 0.400f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.300f);
        glVertex2f(-0.25f, 0.280f);
        glVertex2f(-0.35f, 0.280f);
        glVertex2f(-0.35f, 0.300f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.200f);
        glVertex2f(-0.25f, 0.180f);
        glVertex2f(-0.35f, 0.180f);
        glVertex2f(-0.35f, 0.200f);
    glEnd();


    glBegin(GL_QUADS);
   glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.100f);
        glVertex2f(-0.25f, 0.080f);
        glVertex2f(-0.35f, 0.080f);
        glVertex2f(-0.35f, 0.100f);
    glEnd();




glBegin(GL_QUADS);
    glColor3f(0.40f, 0.70f, 0.65f);
        glVertex2f(-0.25f, 0.0100f);
        glVertex2f(-0.25f, -0.0120f);
        glVertex2f(-0.35f, -0.0120f);
        glVertex2f(-0.35f, 0.0100f);
    glEnd();

//6th
glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(-0.25f, 0.500f);
        glVertex2f(-0.25f, -0.110f);
        glVertex2f(-0.175f, -0.048f);
        glVertex2f(-0.175f, 0.500f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.81f, 0.92f);
        glVertex2f(-0.24f, 0.450f);
        glVertex2f(-0.24f, -0.070f);
        glVertex2f(-0.185f, -0.028f);
        glVertex2f(-0.185f, 0.450f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(-0.200f, 0.470f);
        glVertex2f(-0.200f, -0.070f);
        glVertex2f(-0.225f, -0.058f);
        glVertex2f(-0.225, 0.470f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(-0.25f, 0.400f);
        glVertex2f(-0.25f, 0.350f);
        glVertex2f(-0.175f, 0.350f);
        glVertex2f(-0.175f, 0.400f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(-0.25f, 0.300f);
        glVertex2f(-0.25f, 0.250f);
        glVertex2f(-0.175f, 0.2500f);
        glVertex2f(-0.175f, 0.300f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(-0.25f, 0.200f);
        glVertex2f(-0.25f, 0.150f);
        glVertex2f(-0.175f, 0.150f);
        glVertex2f(-0.175f, 0.200f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(-0.25f, 0.100f);
        glVertex2f(-0.25f, 0.050f);
        glVertex2f(-0.175f, 0.050f);
        glVertex2f(-0.175f, 0.100f);
    glEnd();
    //Footpath Right side
    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.72f, 0.53f); // RGB: 222, 184, 135
        glVertex2f(0.1f, 0.0f);        // Top-left point
        glVertex2f(0.12f, 0.0f);         // Top-right point
        glVertex2f(1.0f, -0.75f);        // Bottom-right point
        glVertex2f(1.0f, -1.0f);      // Bottom-left point
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.80f, 0.60f, 0.50f); // RGB: 222, 184, 135
        glVertex2f(0.1f, 0.0f);        // Top-left point
        glVertex2f(0.11f, 0.0f);         // Top-right point
        glVertex2f(1.0f, -0.95f);        // Bottom-right point
        glVertex2f(1.0f, -1.0f);      // Bottom-left point
    glEnd();


    //First Building Right side


    glBegin(GL_QUADS);
    glColor3f(1.80f, 0.80f, 0.20f);
        glVertex2f(0.66f, 0.900f);
        glVertex2f(0.66f, -0.465f);
        glVertex2f(1.0f, -0.75f);
        glVertex2f(1.0f, 0.900f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f,- 0.200f);
        glVertex2f(0.66f, -0.430f);
        glVertex2f(1.0f, -0.65f);
        glVertex2f(1.0f,- 0.200f);
    glEnd();




    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, 0.800f);
        glVertex2f(0.66f, 0.700f);
        glVertex2f(1.0f, 0.700f);
        glVertex2f(1.0f, 0.800f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, 0.600f);
        glVertex2f(0.66f, 0.500f);
        glVertex2f(1.0f, 0.500f);
        glVertex2f(1.0f, 0.600f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, 0.400f);
        glVertex2f(0.66f, 0.300f);
        glVertex2f(1.0f, 0.300f);
        glVertex2f(1.0f, 0.400f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, 0.200f);
        glVertex2f(0.66f, 0.100f);
        glVertex2f(1.0f, 0.100f);
        glVertex2f(1.0f, 0.200f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, 0.00f);
        glVertex2f(0.66f, -0.100f);
        glVertex2f(1.0f, -0.100f);
        glVertex2f(1.0f, 0.00f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, -0.200f);
        glVertex2f(0.66f,- 0.300f);
        glVertex2f(1.0f, -0.300f);
        glVertex2f(1.0f, -0.200f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.80f, 0.80f, 0.20f);
        glVertex2f(0.66f, 0.900f);
        glVertex2f(0.66f, -0.465f);
        glVertex2f(0.69f, -0.485f);
        glVertex2f(0.69f, 0.900f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.80f, 0.80f, 0.20f);
        glVertex2f(0.75f, 0.900f);
        glVertex2f(0.75f, -0.53f);
        glVertex2f(0.77f, -0.55f);
        glVertex2f(0.77f, 0.900f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.80f, 0.80f, 0.20f);
        glVertex2f(0.84f, 0.900f);
        glVertex2f(0.84f, -0.615f);
        glVertex2f(0.86f, -0.620f);
        glVertex2f(0.86f, 0.900f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(1.80f, 0.80f, 0.20f);
        glVertex2f(0.93f, 0.900f);
        glVertex2f(0.93f, -0.67f);
        glVertex2f(0.95f, -0.69f);
        glVertex2f(0.95f, 0.900f);
    glEnd();

 //2nd
      glBegin(GL_QUADS);
       glColor3f(0.50f, 0.91f, 0.62f);
        glVertex2f(0.66f, 0.850f);
        glVertex2f(0.66f, -0.465f);
        glVertex2f(0.40f, -0.240f);
        glVertex2f(0.40f, 0.850f);
    glEnd();

glBegin(GL_QUADS);
glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, 0.850f);
        glVertex2f(0.66f, 0.800f);
        glVertex2f(0.40f, 0.800f);
        glVertex2f(0.40f, 0.850f);
    glEnd();


    glBegin(GL_QUADS);
   glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, 0.700f);
        glVertex2f(0.66f, 0.650f);
        glVertex2f(0.40f, 0.650f);
        glVertex2f(0.40f, 0.700f);
    glEnd();


     glBegin(GL_QUADS);
    glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, 0.500f);
        glVertex2f(0.66f, 0.550f);
        glVertex2f(0.40f, 0.550f);
        glVertex2f(0.40f, 0.500f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, 0.400f);
        glVertex2f(0.66f, 0.350f);
        glVertex2f(0.40f, 0.350f);
        glVertex2f(0.40f, 0.400f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, 0.200f);
        glVertex2f(0.66f, 0.250f);
        glVertex2f(0.40f, 0.250f);
        glVertex2f(0.40f, 0.200f);
    glEnd();


    glBegin(GL_QUADS);
   glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, 0.100f);
        glVertex2f(0.66f, 0.0450f);
        glVertex2f(0.40f, 0.050f);
        glVertex2f(0.40f, 0.100f);
    glEnd();


    glBegin(GL_QUADS);
 glColor3f(0.30f, 0.40f, 0.40f);
        glVertex2f(0.66f, -0.100f);
        glVertex2f(0.66f, -0.465f);
        glVertex2f(0.40f, -0.240f);
        glVertex2f(0.40f,- 0.100f);
    glEnd();

    glBegin(GL_QUADS);
 glColor3f(0.230f, 0.31f, 0.020f);
        glVertex2f(0.66f, -0.465f);
        glVertex2f(0.66f, -0.405f);
        glVertex2f(0.40f, -0.230f);
        glVertex2f(0.40f,- 0.250f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.23f, 0.31f, 0.02f);
        glVertex2f(0.66f, -0.100f);
        glVertex2f(0.66f, -0.050f);
        glVertex2f(0.40f, -0.050f);
        glVertex2f(0.40f, -0.100f);
    glEnd();


glBegin(GL_QUADS);
glColor3f(0.23f, 0.31f, 0.02f);

        glVertex2f(0.60f, 0.850f);
        glVertex2f(0.60f, -0.410f);
        glVertex2f(0.61f, -0.420f);
        glVertex2f(0.61f, 0.850f);
    glEnd();


glBegin(GL_QUADS);
glColor3f(0.23f, 0.31f, 0.02f);

        glVertex2f(0.50f, 0.850f);
        glVertex2f(0.50f, -0.330f);
        glVertex2f(0.51f, -0.340f);
        glVertex2f(0.51f, 0.850f);
    glEnd();


glBegin(GL_QUADS);
glColor3f(0.23f, 0.31f, 0.02f);

        glVertex2f(0.40f, 0.850f);
        glVertex2f(0.40f, -0.230f);
        glVertex2f(0.43f, -0.260f);
        glVertex2f(0.43f, 0.850f);
    glEnd();




    //3th
    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.81f, 0.62f);
        glVertex2f(0.30f, 0.900f);
        glVertex2f(0.30f, -0.155f);
        glVertex2f(0.40f, -0.240f);
        glVertex2f(0.40f, 0.900f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.73f, 0.81f, 0.252f);
        glVertex2f(0.40f, 0.900f);
        glVertex2f(0.40f, -0.240f);
        glVertex2f(0.37f, -0.215f);
        glVertex2f(0.37f, 0.900f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, 0.850f);
        glVertex2f(0.40f, 0.750f);
        glVertex2f(0.30f, 0.750f);
        glVertex2f(0.30f, 0.850f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, 0.700f);
        glVertex2f(0.40f, 0.600f);
        glVertex2f(0.30f, 0.600f);
        glVertex2f(0.30f, 0.700f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, 0.550f);
        glVertex2f(0.40f, 0.450f);
        glVertex2f(0.30f, 0.450f);
        glVertex2f(0.30f, 0.550f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, 0.400f);
        glVertex2f(0.40f, 0.300f);
        glVertex2f(0.30f, 0.300f);
        glVertex2f(0.30f, 0.400f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, 0.250f);
        glVertex2f(0.40f, 0.150f);
        glVertex2f(0.30f, 0.150f);
        glVertex2f(0.30f, 0.250f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, 0.100f);
        glVertex2f(0.40f, 0.00f);
        glVertex2f(0.30f, 0.00f);
        glVertex2f(0.30f, 0.100f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.0f, 0.50f, 0.40f);
        glVertex2f(0.40f, -0.050f);
        glVertex2f(0.40f, -0.150f);
        glVertex2f(0.30f, -0.130f);
        glVertex2f(0.30f, -0.050f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.81f, 0.225f);
        glVertex2f(0.305f, 0.900f);
        glVertex2f(0.305f, -0.155f);
        glVertex2f(0.30f, -0.155f);
        glVertex2f(0.30f, 0.900f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.73f, 0.81f, 0.225f);
        glVertex2f(0.375f, 0.900f);
        glVertex2f(0.375f, -0.215f);
        glVertex2f(0.370f, -0.215f);
        glVertex2f(0.370f, 0.900f);
    glEnd();

    //4th
    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(0.25f, 0.800f);
        glVertex2f(0.25f, -0.110f);
        glVertex2f(0.30f, -0.155f);
        glVertex2f(0.30f, 0.800f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.35f, 0.81f, 0.80f);
        glVertex2f(0.265f, 0.750f);
        glVertex2f(0.265f, -0.100f);
        glVertex2f(0.285f, -0.100f);
        glVertex2f(0.285f, 0.750f);
    glEnd();



glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(0.25f, 0.650f);
        glVertex2f(0.25f, 0.600f);
        glVertex2f(0.30f, 0.600f);
        glVertex2f(0.30f, 0.650f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(0.25f, 0.450f);
        glVertex2f(0.25f, 0.400f);
        glVertex2f(0.30f, 0.400f);
        glVertex2f(0.30f, 0.450f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(0.25f, 0.250f);
        glVertex2f(0.25f, 0.200f);
        glVertex2f(0.30f, 0.200f);
        glVertex2f(0.30f, 0.250f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.73f, 0.71f, 0.62f);
        glVertex2f(0.25f, 0.050f);
        glVertex2f(0.25f, 0.000f);
        glVertex2f(0.30f, 0.000f);
        glVertex2f(0.30f, 0.050f);
    glEnd();





    //5th

 glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.800f);
        glVertex2f(0.25f, -0.110f);
        glVertex2f(0.15f, -0.030f);
        glVertex2f(0.15f, 0.700f);
    glEnd();

    glBegin(GL_QUADS);
       glColor3f(0.35f, 0.81f, .80f);
        glVertex2f(0.23f, 0.720f);
        glVertex2f(0.23f, -0.080f);
        glVertex2f(0.16f, -0.029f);
        glVertex2f(0.16f, 0.650f);
    glEnd();

glBegin(GL_QUADS);
       glColor3f(0.75f, 0.81f, .62f);
        glVertex2f(0.18f, 0.730f);
        glVertex2f(0.18f, -0.060f);
        glVertex2f(0.17f, -0.030f);
        glVertex2f(0.17f, 0.680f);
    glEnd();

glBegin(GL_QUADS);
       glColor3f(0.75f, 0.81f, .62f);
        glVertex2f(0.21f, 0.730f);
        glVertex2f(0.21f, -0.080f);
        glVertex2f(0.195f, -0.055f);
        glVertex2f(0.195f, 0.680f);
    glEnd();


glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.700f);
        glVertex2f(0.25f, 0.650f);
        glVertex2f(0.15f, 0.550f);
        glVertex2f(0.15f, 0.600f);
    glEnd();

glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.600f);
        glVertex2f(0.25f, 0.550f);
        glVertex2f(0.15f, 0.450f);
        glVertex2f(0.15f, 0.500f);
    glEnd();

    glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.500f);
        glVertex2f(0.25f, 0.450f);
        glVertex2f(0.15f, 0.350f);
        glVertex2f(0.15f, 0.400f);
    glEnd();

    glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.400f);
        glVertex2f(0.25f, 0.350f);
        glVertex2f(0.15f, 0.250f);
        glVertex2f(0.15f, 0.300f);
    glEnd();

glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.300f);
        glVertex2f(0.25f, 0.250f);
        glVertex2f(0.15f, 0.150f);
        glVertex2f(0.15f, 0.200f);
    glEnd();

glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.200f);
        glVertex2f(0.25f, 0.150f);
        glVertex2f(0.15f, 0.050f);
        glVertex2f(0.15f, 0.100f);
    glEnd();

glBegin(GL_QUADS);
       glColor3f(0.73f, 0.81f, .62f);
        glVertex2f(0.25f, 0.100f);
        glVertex2f(0.25f, 0.050f);
        glVertex2f(0.15f, 0.000f);
        glVertex2f(0.15f, 0.0100f);
    glEnd();

//6th
glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f);
        glVertex2f(0.1f, 0.50f);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.15f, -0.030f);
        glVertex2f(0.15f, 0.50f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.30f, 0.30f);
        glVertex2f(0.11f, 0.475f);
        glVertex2f(0.11f, 0.010f);
        glVertex2f(0.14f, -0.010f);
        glVertex2f(0.14f, 0.475f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f);
        glVertex2f(0.1f, 0.40f);
        glVertex2f(0.1f, 0.35f);
        glVertex2f(0.15f, 0.35f);
        glVertex2f(0.15f, 0.40f);
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f);
        glVertex2f(0.1f, 0.20f);
        glVertex2f(0.1f, 0.15f);
        glVertex2f(0.15f, 0.15f);
        glVertex2f(0.15f, 0.20f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f);
        glVertex2f(0.12f, 0.475f);
        glVertex2f(0.12f, 0.010f);
        glVertex2f(0.13f, -0.010f);
        glVertex2f(0.13f, 0.475f);
    glEnd();

//Sun



    AddText("Hospital",-0.82,0.85,0.0);
    AddText("Star Tower",0.48,0.80,0.0);
    AddText("School",0.78,0.82,0.0);


//Clouds
     glLoadIdentity();
     glTranslatef(cloudposition,0.0f,0.0f);
    drawCloud(-1.0f,0.8f,0.2f);
    drawCloud(-0.8f,0.75f,0.2f);
    drawCloud(-0.9f,0.9f,0.3f);
    drawCloud(-0.21f,0.77,0.4f);
    glTranslatef(cloudposition2,0.0f,0.0f);
    drawCloud(-0.41f,0.87,0.5f);



//Left Tree 1
   glLoadIdentity();
    glTranslatef(0.06f,-0.999f,0.0f);
 tree();
 //Left Tree 2
 glLoadIdentity();
    glTranslatef(0.21f,-0.849f,0.0f);
 tree();

 //Left Tree 2
 glLoadIdentity();
    glTranslatef(0.355f,-0.729f,0.0f);
 tree();

 //tree3
 tree2(0.50f,0.1f);
//tree 4
 tree2(0.40,0.2f);
 //tree 4
 tree2(0.30f,40.3f);
 //tree 4
 tree2(0.20f,0.4f);
 //tree 4
 tree2(0.10f,0.5f);
glLoadIdentity();





// CAR
glPushMatrix();
glTranslatef(0.0f,carposition,0.0f);
glScalef(carScale,carScale,0);
//car1


glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.05f,-0.80f);         // Top-right point
        glVertex2f(0.05f, -0.55f);        // Top-left point
        glVertex2f(0.20f, -0.55f);       // Bottom-left point
        glVertex2f(0.20f, -0.80f);     // Bottom-right point
    glEnd();


glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.07f,-0.45f);         // Top-right point
        glVertex2f(0.05f, -0.55f);        // Top-left point
        glVertex2f(0.20f, -0.55f);       // Bottom-left point
        glVertex2f(0.18f, -0.45f);     // Bottom-right point
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.80f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.07f,-0.45f);         // Top-right point
        glVertex2f(0.06f, -0.49f);        // Top-left point
        glVertex2f(0.19f, -0.49f);       // Bottom-left point
        glVertex2f(0.18f, -0.45f);     // Bottom-right point
    glEnd();



    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.20f, 1.0f);    // Black color
        glVertex2f(0.07f,-0.50f);         // Top-right point
        glVertex2f(0.06f, -0.54f);        // Top-left point
        glVertex2f(0.19f, -0.54f);       // Bottom-left point
        glVertex2f(0.18f, -0.50f);     // Bottom-right point
    glEnd();


glBegin(GL_QUADS);
        glColor3f(0.90f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.05f,-0.80f);         // Top-right point
        glVertex2f(0.05f, -0.865f);        // Top-left point
        glVertex2f(0.20f, -0.865f);       // Bottom-left point
        glVertex2f(0.20f, -0.80f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.70f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.05f,-0.80f);         // Top-right point
        glVertex2f(0.05f, -0.73f);        // Top-left point
        glVertex2f(0.20f, -0.73f);       // Bottom-left point
        glVertex2f(0.20f, -0.80f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.30f, 1.0f);    // Black color
        glVertex2f(0.06f,-0.79f);         // Top-right point
        glVertex2f(0.06f, -0.74f);        // Top-left point
        glVertex2f(0.19f, -0.74f);       // Bottom-left point
        glVertex2f(0.19f, -0.79f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.80f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.05f,-0.915f);         // Top-right point
        glVertex2f(0.05f, -0.8650f);        // Top-left point
        glVertex2f(0.20f, -0.8650f);       // Bottom-left point
        glVertex2f(0.20f, -0.915f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.50f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.06f,-0.905f);         // Top-right point
        glVertex2f(0.06f, -0.89f);        // Top-left point
        glVertex2f(0.09f, -0.89f);       // Bottom-left point
        glVertex2f(0.09f, -0.905f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.50f, 0.0f, 0.0f);    // Black color
        glVertex2f(0.16f,-0.905f);         // Top-right point
        glVertex2f(0.16f, -0.89f);        // Top-left point
        glVertex2f(0.19f, -0.89f);       // Bottom-left point
        glVertex2f(0.19f, -0.905f);     // Bottom-right point
    glEnd();
glPopMatrix();


//car2



glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
glScalef(0.5,0.5,0);
//glTranslatef(0.0f,car2position,0.0f);
glScalef(car2Scale,car2Scale,0);

glBegin(GL_QUADS);
        glColor3f(0.70f, 0.70f, 0.70f);    // Black color
        glVertex2f(-0.1f,-0.80f);         // Top-right point
        glVertex2f(-0.1f, -0.55f);        // Top-left point
        glVertex2f(-0.25f, -0.55f);       // Bottom-left point
        glVertex2f(-0.25f, -0.80f);     // Bottom-right point
    glEnd();


glBegin(GL_QUADS);
        glColor3f(0.80f, 0.80f, 0.80f);    // Black color
        glVertex2f(-0.12f,-0.49f);         // Top-right point
        glVertex2f(-0.1f, -0.55f);        // Top-left point
        glVertex2f(-0.25f, -0.55f);       // Bottom-left point
        glVertex2f(-0.23f, -0.49f);     // Bottom-right point
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.20f, 1.0f);    // Black color
        glVertex2f(-0.12f,-0.50f);         // Top-right point
        glVertex2f(-0.11f, -0.54f);        // Top-left point
        glVertex2f(-0.24f, -0.54f);       // Bottom-left point
        glVertex2f(-0.23f, -0.50f);     // Bottom-right point
    glEnd();


glBegin(GL_QUADS);
        glColor3f(0.80f, 0.80f, 0.80f);    // Black color
        glVertex2f(-0.1f,-0.80f);         // Top-right point
        glVertex2f(-0.1f, -0.865f);        // Top-left point
        glVertex2f(-0.25f, -0.865f);       // Bottom-left point
        glVertex2f(-0.25f, -0.80f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.90f, 0.90f, 0.90f);    // Black color
        glVertex2f(-0.1f,-0.80f);         // Top-right point
        glVertex2f(-0.1f, -0.71f);        // Top-left point
        glVertex2f(-0.25f, -0.71f);       // Bottom-left point
        glVertex2f(-0.25f, -0.80f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.30f, 1.0f);    // Black color
        glVertex2f(-0.11f,-0.79f);         // Top-right point
        glVertex2f(-0.11f, -0.72f);        // Top-left point
        glVertex2f(-0.24f, -0.72f);       // Bottom-left point
        glVertex2f(-0.24f, -0.79f);     // Bottom-right point
    glEnd();



    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.90f, 0.90f);    // Black color
        glVertex2f(-0.1f,-0.915f);         // Top-right point
        glVertex2f(-0.1f, -0.8650f);        // Top-left point
        glVertex2f(-0.25f, -0.8650f);       // Bottom-left point
        glVertex2f(-0.25f, -0.915f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);    // Black color
        glVertex2f(-0.15f,-0.915f);         // Top-right point
        glVertex2f(-0.15f, -0.895f);        // Top-left point
        glVertex2f(-0.20f, -0.895f);       // Bottom-left point
        glVertex2f(-0.20f, -0.915f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.50f, 0.0f, 0.0f);    // Black color
        glVertex2f(-0.11f,-0.905f);         // Top-right point
        glVertex2f(-0.11f, -0.89f);        // Top-left point
        glVertex2f(-0.14f, -0.89f);       // Bottom-left point
        glVertex2f(-0.14f, -0.905f);     // Bottom-right point
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.50f, 0.0f, 0.0f);    // Black color
        glVertex2f(-0.21f,-0.905f);         // Top-right point
        glVertex2f(-0.21f, -0.89f);        // Top-left point
        glVertex2f(-0.24f, -0.89f);       // Bottom-left point
        glVertex2f(-0.24f, -0.905f);     // Bottom-right point
    glEnd();

    glPopMatrix();
//SCENARIO 4 END DISPLAY
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 700);
    glutInitWindowPosition(100, 20);
    glutCreateWindow("Computer Graphics Project");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glutDisplayFunc(display); // Set display callback
    glutKeyboardFunc(keyboard); // Set keyboard callback
   glutTimerFunc(100, Movement, 0);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(100, CarMovement, 0);
     glutTimerFunc(100,jbMovement,0);
    glutTimerFunc(100, Car2Movement, 0);
    glutTimerFunc(100,ABMovement,0);
    glutMouseFunc(handleMouse);
     sound();
    glutMainLoop();

    return 0;
}
