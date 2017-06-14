#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

//global declaration
GLfloat a=360,b=180,c=-360,d=0,e=0,g=400,h=0;

//style1 to write text
void drawBitmapText(char *string,float xy,float yz,float zx) 
{  
	char *c;
	glRasterPos3f(xy, yz,zx);

	for (c=string; *c != NULL; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

//style2 to write text
void drawBitmapText1(char *string,float xy,float yz,float zx) 
{  
	char *c;
	glRasterPos3f(xy, yz,zx);

	for (c=string; *c != NULL; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

//scene 1 - boy studying
void boystuding(){

    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    double radius = 30;
	double twicePi = 2.0 * 3.142;
	GLfloat x,y;

	//background - 	238-221-130 -  color
	glColor3ub(238,221,130); 
	glBegin(GL_QUADS);
		glVertex2f(0,120);
		glVertex2f(0,500);
		glVertex2f(500,500);
		glVertex2f(500,120);
	glEnd();
	glColor3ub(255,255,255); 
	glBegin(GL_QUADS);
		glVertex2f(0,0);
		glVertex2f(0,120);
		glVertex2f(500,120);
		glVertex2f(500,0);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	drawBitmapText1("Once upon a time there lived a boy in India",100.0,450.0,0.0);
	drawBitmapText1("who aspired to study and work in the US",100.0,420.0,0.0);

    //face    
    glColor3ub(234, 192, 134); //skin color
    x = 0*50 + 250, y = 0*50 + 250;
	radius = 30;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	//cap
	glColor3ub(25, 56, 134); //cap color
	x =  250, y = 0.3*50 + 250;
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x, y); // center of cap
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END
	x = 0.5*50 + 250, y = 0.3*50 + 250;
	radius = 15;
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x, y); // center of cap
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	//body trunc
	glColor3ub(234, 0, 0); //shirt color
	glBegin(GL_QUADS);
	glVertex2f(212,183);
	glVertex2f(288,183);
	glVertex2f(288,150);
	glVertex2f(212,150);
	glEnd();

	//arms
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(260,217);
	glVertex2f(1.5*50 + 250,-1*50 + 250);
	glVertex2f(1.5*50 + 250,-1*50 + 250);
	glVertex2f(0.2*50 + 250,-1.8*50 + 250);

	glVertex2f(240,217);
	glVertex2f(-1.5*50 + 250,-1*50 + 250);
	glVertex2f(-1.5*50 + 250,-1*50 + 250);
	glVertex2f(-0.2*50 + 250,-1.8*50 + 250);
	glEnd();
	//body upper
	radius = 38;
    glColor3ub(234, 0, 0); //shirt color
    x = 250, y = 183;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	GLfloat bookheight=0.3;
	int tableheight=-2;
	//book before him
	glColor3ub(0, 0, 0); //book color
	glBegin(GL_QUADS);
	glVertex2f(-0.5*50 + 250,tableheight*50 + 250);
	glVertex2f(0.5*50 + 250,tableheight*50 + 250);
	glVertex2f(0.5*50 + 250,(tableheight+bookheight)*50 + 250);
	glVertex2f(-0.5*50 + 250,(tableheight+bookheight)*50 + 250);
	glEnd();

	//table
	
	glLineWidth(50.0);
	glColor3ub(139, 69, 19); //table color
	glBegin(GL_QUADS);
	glVertex2f(100,0);
	glVertex2f(100,150);
	glVertex2f(350,150);
	glVertex2f(350,0);
	
	glEnd();

	//books
	
	glLineWidth(50.0);

	glColor3ub(13, 60, 10); //book color
	glBegin(GL_QUADS);
	glVertex2f(-3*50 + 250,tableheight*50 + 250);
	glVertex2f(-2*50 + 250,tableheight*50 + 250);
	glVertex2f(-2*50 + 250,(tableheight+bookheight)*50 + 250);
	glVertex2f(-3*50 + 250,(tableheight+bookheight)*50 + 250);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-3*50 + 250,(tableheight+bookheight)*50 + 250);
	glVertex2f(-2*50 + 250,(tableheight+bookheight)*50 + 250);
	glEnd();

	glColor3ub(13, 69, 100); //book color
	glBegin(GL_QUADS);
	glVertex2f(-3*50 + 250,(tableheight+bookheight)*50 + 250);
	glVertex2f(-2*50 + 250,(tableheight+bookheight)*50 + 250);
	glVertex2f(-2*50 + 250,(tableheight+bookheight+bookheight)*50 + 250);
	glVertex2f(-3*50 + 250,(tableheight+bookheight+bookheight)*50 + 250);
	glEnd();

	glFlush();
	glutSwapBuffers();
	
}

//scene2 - flight take off
void road()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//black road
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,100.0);
	glVertex2f(500.0,100.0);
	glVertex2f(500.0,0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//white strips on road
	glVertex2f(0.0,40.0);
	glVertex2f(8.0,60.0);
	glVertex2f(58.0,60.0);
	glVertex2f(50.0,40.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100.0,40.0);
	glVertex2f(108.0,60.0);
	glVertex2f(158.0,60.0);
	glVertex2f(150.0,40.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(200.0,40.0);
	glVertex2f(208.0,60.0);
	glVertex2f(258.0,60.0);
	glVertex2f(250.0,40.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(300.0,40.0);
	glVertex2f(308.0,60.0);
	glVertex2f(358.0,60.0);
	glVertex2f(350.0,40.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(400.0,40.0);
	glVertex2f(408.0,60.0);
	glVertex2f(458.0,60.0);
	glVertex2f(450.0,40.0);
	glEnd();
	glPopMatrix();
}
void update(int value)
{
	a+=20.0; //Plane position takeoff on x axis
	b-=10.0; //Road Strip backward movement
	c+=15; //take off at certain angle on y axis
	if(b<=-78.0)// moving of run way
	b=0.0;
	glutPostRedisplay();
	glutTimerFunc(150,update,0);//delay
}
void flighttakeoff()
{
	drawBitmapText1("Soon he flew to US to live his dreams!",100.0,450.0,0.0);
	//code for plane
		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//rectangular body
			glVertex2f(0.0,30.0);
			glVertex2f(0.0,55.0);
			glVertex2f(135.0,55.0);
			glVertex2f(135.0,30.0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//upper triangle construction plane
			glVertex2f(135.0,55.0);
			glVertex2f(150.0,50.0);
			glVertex2f(155.0,45.0);
			glVertex2f(160.0,40.0);
			glVertex2f(135.0,40.0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINE_LOOP);//outline of upper triangle plane
			glVertex2f(135.0,55.0);
			glVertex2f(150.0,50.0);
			glVertex2f(155.0,45.0);
			glVertex2f(160.0,40.0);
			glVertex2f(135.0,40.0);
		glEnd();
		drawBitmapText("AMERICAN AIRLINES",10.0,45.0,0.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);//lower triangle
			glVertex2f(135.0,40.0);
			glVertex2f(160.0,40.0);
			glVertex2f(160.0,37.0);
			glVertex2f(145.0,30.0);
			glVertex2f(135.0,30.0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);//back wing
			glVertex2f(0.0,55.0);
			glVertex2f(0.0,80.0);
			glVertex2f(10.0,80.0);
			glVertex2f(40.0,55.0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);//left side wing
			glVertex2f(65.0,55.0);
			glVertex2f(50.0,70.0);
			glVertex2f(75.0,70.0);
			glVertex2f(90.0,55.0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(a,c,0.0);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);//rightside wing
			glVertex2f(70.0,40.0);
			glVertex2f(100.0,40.0);
			glVertex2f(80.0,15.0);
			glVertex2f(50.0,15.0);
		glEnd();
		glPopMatrix();

		glFlush();
		glutSwapBuffers();
}

//scene 3 - graduation
void graduation(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    //glTranslatef(0, 0, -10);
    int i;
    double radius = 30;
	double twicePi = 2.0 * 3.142;
	GLfloat x,y;
	
	//background
	glLineWidth(20.0);
	glColor3ub(255,160,122);
	glBegin(GL_QUADS);
	glVertex2f(0,170);
	glVertex2f(500,170);
	glVertex2f(500,500);
	glVertex2f(0,500);
	glEnd();
	glColor3ub(255,250,240);
	glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(500,0);
	glVertex2f(500,170);
	glVertex2f(0,170);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2f(50,450);
	glVertex2f(450,450);
	glVertex2f(450,350);
	glVertex2f(50,350);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	drawBitmapText1("Stanford GRADUATION DAY !!!",200.0,400.0,0.0);

    //face    
    glColor3ub(234, 192, 134); //skin color
    x = 0*50 + 250, y = 0*50 + 260;
	radius = 30;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END

	//cap
	glColor3ub(0, 0, 0); //cap color
	glBegin(GL_QUADS);
		glVertex2f(-0.5*50 + 250,0.3*50 + 260);
		glVertex2f(0.5*50 + 250,0.3*50 + 260);
		glVertex2f(0.5*50 + 250,1*50 + 260);
		glVertex2f(-0.5*50 + 250,1*50 + 260);
	glEnd();

	glBegin(GL_TRIANGLES); 
	glVertex2f(0.5*50 + 250, 1*50 + 260);
	glVertex2f(0.7*50 + 255, 0.8*50 + 265);
	glVertex2f(0.6*50 + 250, 0.8*50 + 260);
    glEnd(); //END

	//body trunc
	glColor3ub(234, 0, 0); //shirt color
	glBegin(GL_QUADS);
	glVertex2f(212,193);
	glVertex2f(288,193);
	glVertex2f(288,150);
	glVertex2f(212,150);
	glEnd();

	//arms
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(260,217);
	glVertex2f(1.5*50 + 250,-1*50 + 250);
	glVertex2f(1.5*50 + 250,-1*50 + 250);
	glVertex2f(0.2*50 + 250,-1.8*50 + 250);

	glVertex2f(240,217);
	glVertex2f(-1.5*50 + 250,-1*50 + 250);
	glVertex2f(-1.5*50 + 250,-1*50 + 250);
	glVertex2f(-0.2*50 + 250,-1.8*50 + 250);
	glEnd();

	//body upper
	radius = 38;
    glColor3ub(234, 0, 0); //shirt color
    x = 250, y = 193;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	GLfloat bookheight=0.3;
	int tableheight=-2;
	//book before him
	glColor3ub(255, 255, 255); //book color
	glBegin(GL_QUADS);
	glVertex2f(-0.5*50 + 250,tableheight*50 + 250);
	glVertex2f(0.5*50 + 250,tableheight*50 + 250);
	glVertex2f(0.5*50 + 250,(tableheight+bookheight)*50 + 250);
	glVertex2f(-0.5*50 + 250,(tableheight+bookheight)*50 + 250);
	glEnd();
	
	glLineWidth(50.0);

	//pants
	glColor3ub(0, 0, 0); //pant color
	glLineWidth(50.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.8*50 + 255,-2*50 + 250);
	glVertex2f(0*50 + 250,-2*50 + 250);
	glVertex2f(-0.2*50 + 250,-4.7*50 + 250);
	glVertex2f(-0.6*50 + 250,-4.7*50 + 250);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.8*50 + 245,-2*50 + 250);
	glVertex2f(0*50 + 250,-2*50 + 250);
	glVertex2f(0.2*50 + 250,-4.7*50 + 250);
	glVertex2f(0.6*50 + 250,-4.7*50 + 250);
	glEnd();

	glFlush();
	glutSwapBuffers();
	
}

//scene 4 - office
void buildOffice(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//background
	glBegin(GL_POLYGON); 
	glColor3f(0.196,0.80,0.196);
	glVertex2i(0, 0);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(500, 0);
	glEnd();

	glBegin(GL_POLYGON);  //start house 
	glColor3ub(255,0,0);
	glVertex2i(100, 200);
	glColor3ub(255,160,122);
	glVertex2i(100, 400);
	glColor3ub(245,222,179);
	glVertex2i(200, 400);
	glColor3ub(245,245,220);
	glVertex2i(200,200);
	glEnd();   //end house

	glColor3f(1.0,1.0,1.0);
	drawBitmapText1("He started working in an MNC!",50.0,450.0,0.0);
	glBegin(GL_POLYGON);  //start window 1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(110, 280);
	glVertex2i(130, 280);
	glVertex2i(130, 265);
	glVertex2i(110, 265);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(140, 280);
	glVertex2i(160, 280);
	glVertex2i(160, 265);
	glVertex2i(140, 265);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(170, 280);
	glVertex2i(190, 280);
	glVertex2i(190, 265);
	glVertex2i(170, 265);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 2
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(110, 300);
	glVertex2i(130, 300);
	glVertex2i(130, 285);
	glVertex2i(110, 285);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 2
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(140, 300);
	glVertex2i(160, 300);
	glVertex2i(160, 285);
	glVertex2i(140, 285);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 2
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(170, 300);
	glVertex2i(190, 300);
	glVertex2i(190, 285);
	glVertex2i(170, 285);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 3
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(110, 320);
	glVertex2i(130, 320);
	glVertex2i(130, 305);
	glVertex2i(110, 305);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 3
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(140, 320);
	glVertex2i(160, 320);
	glVertex2i(160, 305);
	glVertex2i(140, 305);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 3
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(170, 320);
	glVertex2i(190, 320);
	glVertex2i(190, 305);
	glVertex2i(170, 305);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 4
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(110, 340);
	glVertex2i(130, 340);
	glVertex2i(130, 325);
	glVertex2i(110, 325);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 4
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(140, 340);
	glVertex2i(160, 340);
	glVertex2i(160, 325);
	glVertex2i(140, 325);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 4
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(170, 340);
	glVertex2i(190, 340);
	glVertex2i(190, 325);
	glVertex2i(170, 325);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 5
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(110, 360);
	glVertex2i(130, 360);
	glVertex2i(130, 345);
	glVertex2i(110, 345);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 5
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(140, 360);
	glVertex2i(160, 360);
	glVertex2i(160, 345);
	glVertex2i(140, 345);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 5
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(170, 360);
	glVertex2i(190, 360);
	glVertex2i(190, 345);
	glVertex2i(170, 345);
	glEnd();   //end window
	

	glBegin(GL_POLYGON);  //start door
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(130, 200);
	glVertex2i(130, 250);
	glVertex2i(170, 250);
	glVertex2i(170,200);
	glEnd();  //end door

	glBegin(GL_POLYGON);  //start house 
	glColor3ub(255,0,0);
	glVertex2i(300, 200);
	glColor3ub(255,160,122);
	glVertex2i(300, 450);
	glColor3ub(245,222,179);
	glVertex2i(400, 450);
	glColor3ub(245,245,220);
	glVertex2i(400,200);
	glEnd();   //end house

	
	glBegin(GL_POLYGON);  //start window 1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(310, 330);
	glVertex2i(330, 330);
	glVertex2i(330, 315);
	glVertex2i(310, 315);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(340, 330);
	glVertex2i(360, 330);
	glVertex2i(360, 315);
	glVertex2i(340, 315);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(370, 330);
	glVertex2i(390, 330);
	glVertex2i(390, 315);
	glVertex2i(370, 315);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 2
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(310, 350);
	glVertex2i(330, 350);
	glVertex2i(330, 335);
	glVertex2i(310, 335);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 2
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(340, 350);
	glVertex2i(360, 350);
	glVertex2i(360, 335);
	glVertex2i(340, 335);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 2
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(370, 350);
	glVertex2i(390, 350);
	glVertex2i(390, 335);
	glVertex2i(370, 335);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 2+1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(310, 370);
	glVertex2i(330, 370);
	glVertex2i(330, 355);
	glVertex2i(310, 355);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 2+1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(340, 370);
	glVertex2i(360, 370);
	glVertex2i(360, 355);
	glVertex2i(340, 355);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 2+1
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(370, 370);
	glVertex2i(390, 370);
	glVertex2i(390, 355);
	glVertex2i(370, 355);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 3
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(310, 390);
	glVertex2i(330, 390);
	glVertex2i(330, 375);
	glVertex2i(310, 375);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 3
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(340, 390);
	glVertex2i(360, 390);
	glVertex2i(360, 375);
	glVertex2i(340, 375);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 3
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(370, 390);
	glVertex2i(390, 390);
	glVertex2i(390, 375);
	glVertex2i(370, 375);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 4
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(310, 410);
	glVertex2i(330, 410);
	glVertex2i(330, 395);
	glVertex2i(310, 395);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 4
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(340, 410);
	glVertex2i(360, 410);
	glVertex2i(360, 395);
	glVertex2i(340, 395);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 4
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(370, 410);
	glVertex2i(390, 410);
	glVertex2i(390, 395);
	glVertex2i(370, 395);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 5
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(310, 430);
	glVertex2i(330, 430);
	glVertex2i(330, 415);
	glVertex2i(310, 415);
	glEnd();   //end window

	glBegin(GL_POLYGON);  //start window 5
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(340, 430);
	glVertex2i(360, 430);
	glVertex2i(360, 415);
	glVertex2i(340, 415);
	glEnd();   //end window
	
	glBegin(GL_POLYGON);  //start window 5
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(370, 430);
	glVertex2i(390, 430);
	glVertex2i(390, 415);
	glVertex2i(370, 415);
	glEnd();   //end window
	

	glBegin(GL_POLYGON);  //start door
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(330, 200);
	glVertex2i(330, 250);
	glVertex2i(370, 250);
	glVertex2i(370,200);
	glEnd();  //end door
	glBegin(GL_POLYGON);  //road
	glColor3f(0.7, 0.7, 0.7);
	glVertex2i(205, 0);
	glVertex2i(225, 500);
	glVertex2i(275, 500);
	glVertex2i(295,0);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 175);
	glVertex2i(247, 200);
	glVertex2i(253, 200);
	glVertex2i(253,175);
	glEnd();  //end 
	
	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 225);
	glVertex2i(247, 250);
	glVertex2i(253, 250);
	glVertex2i(253,225);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 275);
	glVertex2i(247, 300);
	glVertex2i(253, 300);
	glVertex2i(253,275);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 325);
	glVertex2i(247, 350);
	glVertex2i(253, 350);
	glVertex2i(253,325);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 375);
	glVertex2i(247, 400);
	glVertex2i(253, 400);
	glVertex2i(253,375);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 375);
	glVertex2i(247, 400);
	glVertex2i(253, 400);
	glVertex2i(253, 375);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 425);
	glVertex2i(247, 445);
	glVertex2i(253, 445);
	glVertex2i(253, 425);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(247, 460);
	glVertex2i(247, 480);
	glVertex2i(253, 480);
	glVertex2i(253, 460);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road
	glColor3f(0.7, 0.7, 0.7);
	glVertex2i(0, 0);
	glVertex2i(0, 180);
	glVertex2i(500,180);
	glVertex2i(500,0);
	glEnd();  //end 
	
	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 86);
	glVertex2i(10, 94);
	glVertex2i(30, 94);
	glVertex2i(30, 86);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 86);
	glVertex2i(10, 94);
	glVertex2i(60, 94);
	glVertex2i(60, 86);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(110, 86);
	glVertex2i(110, 94);
	glVertex2i(160, 94);
	glVertex2i(160, 86);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(210, 86);
	glVertex2i(210, 94);
	glVertex2i(260, 94);
	glVertex2i(260, 86);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(310, 86);
	glVertex2i(310, 94);
	glVertex2i(360, 94);
	glVertex2i(360, 86);
	glEnd();  //end 

	glBegin(GL_POLYGON);  //road strip
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(410, 86);
	glVertex2i(410, 94);
	glVertex2i(460, 94);
	glVertex2i(460, 86);
	glEnd();  //end 
	glFlush();
	glutSwapBuffers();
	
}

//scene 5 - boss discussion
void boss_scene(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
	//background
	glLineWidth(20.0);
	glColor3ub(216,191,216);
	glBegin(GL_QUADS);
	glVertex2f(0,170);
	glVertex2f(500,170);
	glVertex2f(500,500);
	glVertex2f(0,500);
	glEnd();
	glColor3ub(255,250,240);
	glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(500,0);
	glVertex2f(500,170);
	glVertex2f(0,170);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	drawBitmapText1("He informed his boss about the opportunites and perks",300.0,450.0,0.0);
	drawBitmapText1("of MAKE IN INDIA campaign!",350.0,400.0,0.0);
	drawBitmapText1("and convinced him to setup a factory in India!",300.0,350.0,0.0);
    double radius = 30;
	double twicePi = 6.284;
	GLfloat x,y;
	
	/** boss **/
	//chair
	radius = 60;
    glColor3ub(139,137,137); //chair color
    x = 190, y = 225;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END

	glBegin(GL_POLYGON);
	glVertex2f(115,225);
	glVertex2f(265,225);
	glVertex2f(255,150);
	glVertex2f(125,150);
	glEnd();

	GLfloat bookheight=0.3;
	int tableheight=-2;
	glLineWidth(50.0);
    //face    
    glColor3ub(234, 192, 134); //skin color
    x = 200, y =  250;
	radius = 30;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	//eyes of boss
	radius=7;
	glColor3ub(0,0,0);
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	x=-2.1*50 + 300;
	y=-0.4*50 + 270;
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	x=215;
	y=255;
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END

	//body trunc
	glColor3ub(234, 0, 0); //shirt color
	glBegin(GL_QUADS);
	glVertex2f(162,183);
	glVertex2f(238,183);
	glVertex2f(238,150);
	glVertex2f(162,150);
	glEnd();

	//arms
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(210,217);
	glVertex2f(275,150);
	glVertex2f(275,150);
	glVertex2f(210,160);

	glVertex2f(190,217);
	glVertex2f(125,150);
	glVertex2f(125,150);
	glVertex2f(190,160);
	glEnd();

	//body upper
	radius = 38;
    glColor3ub(234, 0, 0); //shirt color
    x = 200, y = 183;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	

	//table
	
	
	glColor3ub(139, 69, 19); //table color
	glBegin(GL_QUADS);
	glVertex2f(50,0);
	glVertex2f(50,150);
	glVertex2f(300,150);
	glVertex2f(300,0);
	
	glEnd();

	//name plate
	
	glLineWidth(50.0);

	glColor3ub(49,79,79); //name plate color
	glBegin(GL_QUADS);
	glVertex2f(50,tableheight*50 + 250);
	glVertex2f(100,tableheight*50 + 250);
	glVertex2f(100,(tableheight+bookheight)*50 + 250);
	glVertex2f(50,(tableheight+bookheight)*50 + 250);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	drawBitmapText1("Manager",57.0,153.0,0.0);

	/** boy standing **/
	//face    
    glColor3ub(234, 192, 134); //skin color
    x = 380, y = 300;
	radius = 30;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	//eyes of boy
	radius=7;
	glColor3ub(0,0,0);
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	x=365;
	y=302.5;
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END

	//body trunc
	glColor3ub(234, 0, 0); //shirt color
	glBegin(GL_QUADS);
	glVertex2f(352,243);
	glVertex2f(408,243);
	glVertex2f(408,180);
	glVertex2f(352,180);
	glEnd();

	//arms
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(390,267);
	glVertex2f(325,200);
	glVertex2f(325,200);
	glVertex2f(290,210);

	glEnd();

	//body upper
	radius = 28;
    glColor3ub(234, 0, 0); //shirt color
    x = 380, y = 243;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 10; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }

    glEnd(); //END

	//lower body
	glColor3ub(25,25,25); //pant color
	glBegin(GL_QUADS);
	glVertex2f(352,180);
	glVertex2f(408,180);
	glVertex2f(395,15);
	glVertex2f(365,15);
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}   

//scene 6 - flight landing
void runway()
{

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//black road
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,100.0);
	glVertex2f(500.0,100.0);
	glVertex2f(500.0,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//white strips on road
	glVertex2f(0.0,40.0);
	glVertex2f(8.0,60.0);
	glVertex2f(58.0,60.0);
	glVertex2f(50.0,40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100.0,40.0);
	glVertex2f(108.0,60.0);
	glVertex2f(158.0,60.0);
	glVertex2f(150.0,40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(200.0,40.0);
	glVertex2f(208.0,60.0);
	glVertex2f(258.0,60.0);
	glVertex2f(250.0,40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(300.0,40.0);
	glVertex2f(308.0,60.0);
	glVertex2f(358.0,60.0);
	glVertex2f(350.0,40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(b,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(400.0,40.0);
	glVertex2f(408.0,60.0);
	glVertex2f(458.0,60.0);
	glVertex2f(450.0,40.0);
	glEnd();
	glPopMatrix();
}
void flightlanding(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawBitmapText1("He finally flew back to India after years!",100.0,450.0,0.0);
	runway();
	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//rectangular body
	glVertex2f(0.0,30.0);
	glVertex2f(0.0,55.0);
	glVertex2f(135.0,55.0);
	glVertex2f(135.0,30.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//upper triangle construction plane
	glVertex2f(135.0,55.0);
	glVertex2f(150.0,50.0);
	glVertex2f(155.0,45.0);
	glVertex2f(160.0,40.0);
	glVertex2f(135.0,40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);//outline of upper triangle plane
	glVertex2f(135.0,55.0);
	glVertex2f(150.0,50.0);
	glVertex2f(155.0,45.0);
	glVertex2f(160.0,40.0);
	glVertex2f(135.0,40.0);
	glEnd();
	drawBitmapText("AIR INDIA",10.0,45.0,0.0);
	glPopMatrix();


	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//lower triangle
	glVertex2f(135.0,40.0);
	glVertex2f(160.0,40.0);
	glVertex2f(160.0,37.0);
	glVertex2f(145.0,30.0);
	glVertex2f(135.0,30.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//back wing
	glVertex2f(0.0,55.0);
	glVertex2f(0.0,80.0);
	glVertex2f(10.0,80.0);
	glVertex2f(40.0,55.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(65.0,55.0);
	glVertex2f(50.0,70.0);
	glVertex2f(75.0,70.0);
	glVertex2f(90.0,55.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(h,g,0.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//rightside wing
	glVertex2f(70.0,40.0);
	glVertex2f(100.0,40.0);
	glVertex2f(80.0,15.0);
	glVertex2f(50.0,15.0);

	glEnd();

	glPopMatrix();
	if(h>500)//window position during take off
	{
		//exit(0);

		a=0;
		b=0;
	}
	g-=15.0;
	h+=20.0;
	glFlush();
	glutSwapBuffers();
}

//scene 7 - India office
void build_outline()//building out lines
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(350.0,80.0);
	glVertex2f(350.0,480.0);
	glVertex2f(400.0,400.0);
	glVertex2f(400.0,0.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(400.0,0.0);
	glVertex2f(400.0,400.0);
	glVertex2f(450.0,400.0);
	glVertex2f(450.0,0.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(400.0,400.0);
	glVertex2f(350.0,480.0);
	glVertex2f(400.0,480.0);
	glVertex2f(450.0,400.0);
	glEnd();
}
void building()
{
		glClear(GL_COLOR_BUFFER_BIT);

		//grass
		glColor3f(0.196,0.80,0.196);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,200.0);
	glVertex2f(500.0,200.0);
	glVertex2f(500.0,0.0);
	glEnd();

	//building
	glColor3f(0.60,0.40,0.70);
	glBegin(GL_POLYGON);
	glVertex2f(350.0,80.0);
	glVertex2f(350.0,480.0);
	glVertex2f(400.0,400.0);
	glVertex2f(400.0,0.0);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	drawBitmapText1("The India Office is under construction!!!",100.0,450.0,0.0);

	glColor3f(0.75,0.75,0.75);
	glBegin(GL_POLYGON);
	glVertex2f(400.0,0.0);
	glVertex2f(400.0,400.0);
	glVertex2f(450.0,400.0);
	glVertex2f(450.0,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(400.0,400.0);
	glVertex2f(350.0,480.0);
	glVertex2f(400.0,480.0);
	glVertex2f(450.0,400.0);
	glEnd();
	glColor3f(0.60,0.40,0.70);
	glBegin(GL_POLYGON);//upper triangle of building
	glVertex2f(400.0,400.0);
	glVertex2f(350.0,480.0);
	glVertex2f(400.0,480.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);//seperation line of floors
	glVertex2f(350.0,180);
	glVertex2f(400.0,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(350.0,280);
	glVertex2f(400.0,200);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(350.0,380);
	glVertex2f(400.0,300);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(450.0,100);
	glVertex2f(400.0,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(450.0,200);
	glVertex2f(400.0,200);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(450.0,300);
	glVertex2f(400.0,300);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(350.0,180);
	glEnd();
	build_outline();
	if(c>2160)
		exit (0);
	glFlush();
	glutSwapBuffers();
}

void display(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.529f,0.807f,0.98f,0.0f);
	glColor3f(1.0,1.0,1.0);
	if(c<0)  //scene 1
		boystuding();
	else if(c<360 && c>0) //scene 2
	{
		if(a>500.0)//window position during take off
		{
			a=0.0;
			b=0.0;
		}
		road();
		flighttakeoff();
	}
	else if(c>360 && c<720) //scene 3
	{
		graduation();
		d+=20;//plane takeoff on x in 2nd display
	}
	
	else if(c>720 && c<1080)//scene 4
	{
		buildOffice();
		e+=20;//plane takeoff on x in 3rd display
	}
	else if(c>1080 && c<1440) //scene 5
		boss_scene();

	if(c>1440 && c<1800) //scene 6
		flightlanding();

	if(c>1800) //scene 7
		building();
	
}
void myinit()
{
	glClearColor(0.529f,0.807f,0.98f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500.0,500.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("SWADESH");
	glutDisplayFunc(display);
	myinit();
	glutTimerFunc(100,update,0);
	glutMainLoop();
}