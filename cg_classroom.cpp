#include<iostream>
#if defined(__APPLE__)
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
using namespace std;
void specialKeys();
/// Global Variables
double rotate_y=0;
double rotate_x=0;
double zoom=0.0;
double pan_hor=0.0;
double pan_ver=0.0;
double XPOS=-2.3;
double YPOS=1.6;
double YPOS1=-0.35;
double YPOS2=-0.8;
double XPOS2=-2.275;
double YPPOS=0.1;
double YPPOS1=0.05;
double YPPOS2=0.0;
double SCALEP=16.0;
double TY=0.9;
/// display() Callback function
void draw_floor(){
	glPushMatrix();
        glColor3f( 0.4, 0.4, 0.4);
		glTranslatef(0.0,-0.70,-1.8);
		glScalef(55.0,1.0,70.0);
		glutSolidCube(0.1);
	glPopMatrix();
}

void draw_walls(){
	///ceil
	glPushMatrix();
		glColor3f( 1, 1, 0.8);
		glColor3f(1,1,0.7);
		glTranslatef(0.0,2.3,-1.8);
		glScalef(55.0,1.0,70.0);
		glutSolidCube(0.1);
	glPopMatrix();

	///leftwall
	glPushMatrix();
	    glColor3f(1,1,0.5);
		glTranslatef(2.7,0.85,-1.8);
		glScalef(1.0,30.0,70.0);
		glutSolidCube(0.1);
	glPopMatrix();

	///rightwall
	glPushMatrix();
        glColor3f(1,1,0.5);
		glTranslatef(-2.7,0.85,-1.8);
		glScalef(1.0,30.0,70.0);
		glutSolidCube(0.1);
	glPopMatrix();

	///backwall
	glPushMatrix();
		glColor3f(1,1,0.55);
		glTranslatef(0,0.8,1.7);
		glScalef(55,30,1);
		glutSolidCube(0.1);
	glPopMatrix();
}

void draw_blackboard(){
	glPushMatrix();
        glColor3f(0 ,0.329,0.1 );
		glTranslatef(0,0.7,1.65);
		glScalef(25,14,1);
		glutSolidCube(0.1);
	glPopMatrix();
}

void draw_table(){

///leftleg

	glColor3f(   0.8,0.4,0);
	glPushMatrix();
		glTranslatef(.6,-0.2,0);
		glScalef(0.3,8.0,8);
		glColor3f(   0.75,0.35,0);
		glutSolidCube(0.1);
	glPopMatrix();

///partition1

	glColor3f(   0.8,0.4,0);
	glPushMatrix();
		glTranslatef(-0.3,-0.2,0);
		glScalef(0.3,8.0,8);
		glColor3f(   0.75,0.35,0);
		glutSolidCube(0.1);
	glPopMatrix();
	
///partition2

	glColor3f(   0.8,0.4,0);
	glPushMatrix();
		glTranslatef(0.3,-0.2,0);
		glScalef(0.3,8.0,8);
		glColor3f(   0.75,0.35,0);
		glutSolidCube(0.1);
	glPopMatrix();
///rightleg

	glColor3f(   0.75,0.35,0);
	glPushMatrix();
		glTranslatef(-.6,-0.2,0);
		glScalef(0.3,8.0,8);
		glutSolidCube(0.1);
	glPopMatrix();

///top

	glPushMatrix();
	glColor3f(   0.85,0.45,0);
		glTranslatef(0,0.2,0);
		glScalef(12.9,1,8.5);
		glutSolidCube(0.1);
	glPopMatrix();


///deskt front wall
	glPushMatrix();
	glColor3f(   0.8,0.4,0);
		glTranslatef(0,0,-.4);
		glScalef(6,4,-0.25);
		glutSolidCube(0.1);
	glPopMatrix();


///deskt front side wall
	glPushMatrix();
	glColor3f(   0.82,0.42,0);
		glTranslatef(-0.45,-0.2,-.4);
		glScalef(3,8,-0.25);
		glutSolidCube(0.1);
	glPopMatrix();
}

void draw_draw_platform(){

	glPushMatrix();
		glColor3f( 0.33, 0.33, 0.33);
		glTranslatef(0.0,-.60,0.55);
		glScalef(25.0,2.0,25.0);
		glutSolidCube(0.1);
	glPopMatrix();
}

void draw_tablechair(int x,int z){

///leg of chair of 5th
///leg 3c

    glColor3f(   0.929,0.8086,0.629);
	glPushMatrix();
		glTranslatef(x+.3,-0.4,-1.8+z);
		glScalef(0.3,6.0,0.3);
		glutSolidCube(0.1);
	glPopMatrix();

///leg 4c

	glPushMatrix();
		glTranslatef(x+-.3,-0.4,-1.8+z);
		glScalef(0.3,6.0,0.3);
		glutSolidCube(0.1);
	glPopMatrix();

///leg2c

	glPushMatrix();
		glTranslatef(x+-.3,-0.5,-1.6+z);
		glScalef(0.3,3.0,0.3);
		glutSolidCube(0.1);
	glPopMatrix();

///leg 1c

	glPushMatrix();
		glTranslatef(x+.3,-0.5,-1.6+z);
		glScalef(0.3,3.0,0.3);
		glutSolidCube(0.1);
	glPopMatrix();
	
///leg of chair ends

///chairback
    glPushMatrix();
    glColor3f(0.996,0.574,0.248);
		glTranslatef(x+0,-0.2,-1.8+z);
		glScalef(6.25,1.75,0.25);
		glutSolidCube(0.1);
	glPopMatrix();

///leg of chair
///tableleg
///leg2

    glColor3f(   0.929,0.8086,0.629);
	glPushMatrix();
		glTranslatef(x+-.3,-0.4,-1.2+z);
		glScalef(0.3,6.0,0.3);
		glutSolidCube(0.1);
	glPopMatrix();

///leg 1

	glPushMatrix();
		glTranslatef(x+.3,-0.4,-1.2+z);
		glScalef(0.3,6.0,0.3);
		glutSolidCube(0.1);
	glPopMatrix();

///chairtop
    glPushMatrix();
    glColor3f(0.996,0.644,0.308);
		glTranslatef(x+0,-0.35,-1.7+z);
		glScalef(6.2,0.25,2.4);
		glutSolidCube(0.1);
	glPopMatrix();

///tabletop

    glPushMatrix();
    glColor3f(0.996,0.644,0.308);
		glTranslatef(x+0,-0.1,-1.35+z);
		glScalef(6.5,0.25,3.95);
		glutSolidCube(0.1);
	glPopMatrix();
	
///desk ///bottom

    glPushMatrix();
    glColor3f(   0.929,0.8086,0.629);
        glTranslatef(x+0,-0.29,-1.3+z);
		glScalef(6.22,0.22,1.8);
		glutSolidCube(0.1);
	glPopMatrix();

///desk right wall

    glPushMatrix();
    glColor3f(   0.996,0.867,0.675);
		glTranslatef(x-0.3,-0.2,-1.3+z);
		glScalef(0.25,1.9,2.25);
		glutSolidCube(0.1);
	glPopMatrix();

///desk left wall

   glPushMatrix();
   glColor3f(   0.996,0.867,0.675);
		glTranslatef(x+0.3,-0.2,-1.3+z);
		glScalef(0.25,1.9,2.25);
		glutSolidCube(0.1);
   glPopMatrix();

///deskt front wall

    glPushMatrix();
    glColor3f(   0.8,  0.7265,  0.586);
		glTranslatef(x+0,-0.2,-1.2+z);
		glScalef(6.25,1.75,0.25);
		glutSolidCube(0.1);
	glPopMatrix();


///front bottomrod

    glPushMatrix();
    glColor3f(   0.8,  0.7265,  0.586);
		glTranslatef(x+0,-0.635,-1.2+z);
		glScalef(6.2,0.25,0.25);
		glutSolidCube(0.1);
	glPopMatrix();

///left bottomrod

     glPushMatrix();
		glTranslatef(x+0.3,-0.635,-1.5+z);
		glScalef(0.25,0.25,6.2);
		glutSolidCube(0.1);
	glPopMatrix();

///right bottomrod

     glPushMatrix();
		glTranslatef(x+-0.3,-0.635,-1.5+z);
		glScalef(0.25,0.25,6.2);
		glutSolidCube(0.1);
	glPopMatrix();

///back bottomrod

     glPushMatrix();
		glTranslatef(x+0,-0.635,-1.8+z);
		glScalef(6.2,0.25,0.25);
		glutSolidCube(0.1);
	glPopMatrix();

}

void draw_projector()
{
///projector screen
    glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(-0.8,TY,1.6); //TY=0.9
			glScalef(10.0,SCALEP,0.3); //scale in y SCALEP=16.0
			glutSolidCube(0.1);
    glPopMatrix();
///upper rod
	glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-0.8,1.7,1.6);
			glScalef(11.0,0.3,0.4);
			glutSolidCube(0.1);
	glPopMatrix();
///bottom rod
    glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-0.8,YPPOS,1.6); ///YPPOS=0.1;
			glScalef(10.0,0.3,0.4);
			glutSolidCube(0.1);
	glPopMatrix();
///hanging line
	glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-1.1,YPPOS1,1.6);   ///YPPOS1=0.05
			glScalef(0.3,1,0.3);
			glutSolidCube(0.1);
	glPopMatrix();
///hanging circle
	 glPushMatrix();
        glColor3f(  0.0, 0.0, 0.0 );
		glTranslatef(-1.1,YPPOS2,1.6); ///YPPOS2=0.0
		glutSolidSphere(0.03,20,20);
	 glPopMatrix();

///projector-rod
	glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-0.8,2.0,-1.0);
		glScalef(0.8,7,0.3);
		glutSolidCube(0.1);
	glPopMatrix();
///projector-box
	glPushMatrix();
        glColor3f(0.7,0.7,0.7);
        glTranslatef(-0.8,1.6,-1.0);
		glScalef(2.0,1.5,1);
		glutSolidCube(0.1);
	glPopMatrix();

}


void draw_lights()	{
///3rd row light -1
						glPushMatrix();
							glColor3f(1,1,1);
							glTranslatef(1.3,2.2,-5.0);
							glScalef(3.0,0.3,3.0);
							glutSolidCube(0.1);
						glPopMatrix();

					///2nd row light -1
						glPushMatrix();
							glTranslatef(1.3,2.2,-4.0);
							glScalef(3.0,0.3,3.0);
							glutSolidCube(0.1);
						glPopMatrix();

					///1st row light -1
						glPushMatrix();
							glTranslatef(1.3,2.2,-3.0);
							glScalef(3.0,0.3,3.0);
							glutSolidCube(0.1);
						glPopMatrix();

///3rd row light -2
                                glPushMatrix();
                                glTranslatef(0,2.2,-5.0);
								glScalef(3.0,0.3,3.0);
								glutSolidCube(0.1);
								glPopMatrix();
	       ///2nd row light -2
                                glPushMatrix();
                                glTranslatef(0,2.2,-4.0);
								glScalef(3.0,0.3,3.0);
								glutSolidCube(0.1);
								glPopMatrix();
	      ///1st row light -2
                                glPushMatrix();
                                glTranslatef(0,2.2,-3.0);
								glScalef(3.0,0.3,3.0);
								glutSolidCube(0.1);
								glPopMatrix();


	      ///3rd row light -3
                                glPushMatrix();
                                glTranslatef(-1.3,2.2,-5.0);
								glScalef(3.0,0.3,3.0);
								glutSolidCube(0.1);
								glPopMatrix();
	       ///2nd row light -3
                                glPushMatrix();
                                glTranslatef(-1.3,2.2,-4.0);
								glScalef(3.0,0.3,3.0);
								glutSolidCube(0.1);
								glPopMatrix();
	      ///1st row light -3
                                glPushMatrix();
                                glTranslatef(-1.3,2.2,-3.0);
								glScalef(3.0,0.3,3.0);
								glutSolidCube(0.1);
								glPopMatrix();
}

void draw_switchboard()
{
///1st switch board
								glPushMatrix();
                                glColor3f(0.5,0.5,0.5);
                                glTranslatef(1.2,-0.1,1.5);
								glScalef(1.0,1.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///3 circles

					///2nd switch board
								glPushMatrix();
                                glColor3f(0.5,0.5,0.5);
                                glTranslatef(1.0,-0.1,1.5);
								glScalef(2.0,1.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1 switch
	                ///3rd switch board

								glPushMatrix();
                                glTranslatef(0.8,-0.1,1.5);
								glScalef(0.4,1.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();
	               
}

void draw_windows()
{
///1st window
                                glPushMatrix();
                                glColor3f(1,1,1);
                                glTranslatef(2.6,1.0,-1);
								glScalef(0.3,10.0,16.0);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1st window boundaries-1
								glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.5,-1);
								glScalef(0.3,0.3,16.0);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1st window boundaries-2
	                			glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,0.5,-1);
								glScalef(0.3,0.3,16.0);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1st window boundaries-3
								glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-1.8);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1st window boundaries-4
								glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-0.2);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1st window boundaries-mid-1
								glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-1.3);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();
	                ///1st window boundaries-mid-2
								glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-0.7);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
								glPopMatrix();

			///2nd window
                                glPushMatrix();
                                glColor3f(1,1,1);
                                glTranslatef(2.6,1.0,-4);
								glScalef(0.3,10.0,16.0);
								glutSolidCube(0.1);
	                glPopMatrix();
	        ///2nd window boundaries-1
	                glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.5,-4);
								glScalef(0.3,0.3,16.0);
								glutSolidCube(0.1);
	                glPopMatrix();
	        ///2nd window boundaries-2
	                glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,0.5,-4);
								glScalef(0.3,0.3,16.0);
								glutSolidCube(0.1);
	                glPopMatrix();
	        ///2nd window boundaries-3
	                glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-4.8);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
	                glPopMatrix();
	        ///2nd window boundaries-4
	                glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-3.2);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
	                glPopMatrix();
	        ///2nd window boundaries-mid-1
	                glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-3.7);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
	                glPopMatrix();
	        ///2nd window boundaries-mid-2
	                glPushMatrix();
                                glColor3f(0,0,0);
                                glTranslatef(2.6,1.0,-4.2);
								glScalef(0.3,10.0,0.3);
								glutSolidCube(0.1);
	                glPopMatrix();
}

void draw_door()
{

	///door knob
		glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(XPOS2,0.5,1.6); //XPOS2=-2.275
		glutSolidSphere(0.03,20,20);
		glPopMatrix();
		///door knob 2 


///open door
		glPushMatrix();
        
		glBegin(GL_QUADS);
		glColor3f(0.8039, 0.4, 0.1137);	/// door color
		glVertex3d(-2,1.85,1.6);
		
		glVertex3d(XPOS,YPOS, 1.6);     //XPOS=-2.3 , YPOS=1.6 YPOS1=-0.35, YPOS2=-0.8
		                                //XPOS=-2.6,YPOS=1.85,YPOS1=-0.7,YPOS2=-0.7
	 
	 glVertex3d(XPOS,YPOS1,1.6);
	    
	     glVertex3d(-2,YPOS2,1.6);
		glEnd();
	glPopMatrix();
	
///vertical bar-1


		glColor3f(0.7039, 0.35, 0.0937);  ///border color
        glPushMatrix();
        glTranslatef(-2.0,0.6,1.6);
		glScalef(0.3,25.0,0.3);
		glutSolidCube(0.1);
	    glPopMatrix();
	     ///vertical bar-2

	    glPushMatrix();
        glTranslatef(-2.6,0.6,1.6);
		glScalef(0.3,25.0,0.3);
		glutSolidCube(0.1);
	    glPopMatrix();

	                ///horizontal bar-1
	    glPushMatrix();
        glTranslatef(-2.3,1.85,1.6);
		glScalef(6.0,0.3,0.3);
		glutSolidCube(0.1);
	    glPopMatrix();
	    
	   
	    
}

void draw_keyboard()
{
        glPushMatrix();
        glColor3f(0.0,0.0,0.0);
		glTranslatef(0.3,0.3,0.0);
		glScalef(5.0,0.4,3.0);
		glutSolidCube(0.1);
	    glPopMatrix();
}

void display(){

	///  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	/// Reset transformations
	glLoadIdentity();

	gluLookAt(0.0+pan_hor,1.0+pan_ver,-3.0+zoom,0.0,0.0,0.0,0.0,1.0,0.0);

	/// Rotate when user changes rotate_x and rotate_y
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );


 glColor3f(  0.5,  0.0,  0.0 );

///draw benches
int z=1;
int x=-0;

///3rd row
for(int i=0;i<4;i++){
    z--;
    draw_tablechair(x,z);
}

///2nd row
x=1.3;
z=1;
for(int i=0;i<4;i++){
    z--;
    draw_tablechair(x,z);
}
///4th row
x=-1.3;
z=1;
for(int i=0;i<4;i++){
    z--;
    draw_tablechair(x,z);
}

///1st row
x=-2.6;
z=1;
for(int i=0;i<4;i++){
    z--;
    draw_tablechair(x,z);
}
///5th row
x=2.6;
z=1;
for(int i=0;i<4;i++){
    z--;
    draw_tablechair(x,z);
}
draw_draw_platform();
draw_walls();
draw_floor();
draw_blackboard();
draw_table();
draw_projector();
draw_lights();
draw_switchboard();
draw_windows();
draw_door();
draw_keyboard();

glFlush();
glutSwapBuffers();


}

/// specialKeys() Callback Function

void specialKeys( int key, int x, int y ) {

	///  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
	rotate_y += 5;

	///  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
	rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
	rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
	rotate_x -= 5;

	///  Request display update
	glutPostRedisplay();

}

void keyboard(unsigned char key,int x,int y){
	if(key=='z'){
		zoom+=0.1;
	}
	else if(key=='x'){
		zoom-=0.1;
	}
	else if(key=='a'){
		pan_hor-=0.1;
	}
	else if(key=='d'){
		pan_hor+=0.1;
	}
	else if(key=='s'){
		pan_ver-=0.1;
	}
	else if(key=='w'){
		pan_ver+=0.1;
	}
	else if(key=='c')
	{
	XPOS=-2.6;
	YPOS=1.85;
	YPOS1=-0.7;
	YPOS2=-0.7;
	XPOS2=-2.575;
	}
	else if(key=='o')
	{
	XPOS=-2.3;
	YPOS=1.6;
	YPOS1=-0.35;
	YPOS2=-0.8;
	XPOS2=-2.275;
	}
	else if(key=='p')
	{
	YPPOS=0.1;
	YPPOS1=0.05;
	YPPOS2=0.0;
	SCALEP=16.0;
	TY=0.9;
	}
	else if(key=='q')
	{
	YPPOS=1.4;
	YPPOS1=1.35;
	YPPOS2=1.32;
	SCALEP=2.8;
	TY=1.55;
	}
           glutPostRedisplay();
}



void mouse(int button, int state, int x, int y)
{
	if(button==3){
		zoom+=0.1;
	}
	else if(button==4){
		zoom-=0.1;
	}
	glutPostRedisplay();
}



void reshape(int w,int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}



void init(){
	glClearColor(0.0f,0.0f,0.4f,1.0f);
	///  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

}



/// main() function

int main(int argc, char* argv[]){

	///  Initialize GLUT and process user parameters
	glutInit(&argc,argv);

	///  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize (800,500);

	glutInitWindowPosition (100, 100);

	/// Create window
	glutCreateWindow("BITS Classroom");

	init();

	/// Callback functions
	
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
                glutMouseFunc(mouse);
	glutSpecialFunc(specialKeys);
	glutReshapeFunc(reshape);

	///  Pass control to GLUT for events
	glutMainLoop();

	///  Return to OS
	return 0;

}
