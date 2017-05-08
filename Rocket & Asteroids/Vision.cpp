#include<glut.h>
#include<iostream>                 // Header files declaration for strlen and other cpp functions
#include<stdlib.h>


 
int i,q;
int score = 0;                             //for score counting
int screen = 0;
bool collide = false;                      //check if rocket collide to make game over
char buffer[10];
int button_down=0;                         // checking if the button is pressed or not


int rocketX = 100, rocketY = 70;   
int asteroidsX[4], asteroidsY[4];              // Rocket and Asteroid Position
int divx = 250, divy = 4, movd;



void drawText(char ch[],int xpos, int ypos)     //draw the text for Points and Game Over(COLLIDE)
{
    int numofchar = strlen(ch); 
	glLoadIdentity();                             // Loading Identity Matrix
    glRasterPos2f( xpos , ypos);                 // Screen Position
    for (i = 0; i <= numofchar - 1; i++)
    {
     glColor3f(0,0,0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);  //font used here, may use other font also
    }
}
 
 
void drawTextNum(char ch[],int numtext,int xpos, int ypos)       //counting the POINTS
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }
     
    }
}
 
 
void background()                                // Background color Sky Color
{

      glClearColor(0.4,0.4,1.0,1);
	
for(i = 0; i < 4; i++)                          // Randomness of the Asteroid
{
    if(rand() % 2 == 0)
    {
        asteroidsX[i] = 200;
    }
    else
    {
        asteroidsX[i] = 300;
    }  
    asteroidsY[i] = 1000 - i * 160;
}

}
 
 
void drawPath()                // Sky Highway
{
    glBegin(GL_QUADS); 
        glColor3f(0.5,0.5,0.5);
        glVertex2f(250 - 200, 500);
        glVertex2f(250 - 200, 0);
        glVertex2f(250 + 200, 0);
        glVertex2f(250 + 200, 500);
    glEnd();
}
 
 
     
 
void drawRocket()             //rocket
{

		glBegin(GL_TRIANGLES); // Rocket's TOP 
	    glColor3f(0.0,0,0);
		glVertex2f(rocketX - 15, rocketY + 20);
		glColor3f(0.9,0,0);
	    glVertex2f(rocketX + 0, rocketY + 45);
		glColor3f(0.0,0,0);
		glVertex2f(rocketX + 15, rocketY + 20);
	glEnd();
     
   glBegin(GL_QUADS);  
        glColor3f(0.8,0.1,0);//middle body
        glVertex2f(rocketX - 5, rocketY + 20);
		glColor3f(0.1,0.8,0);
        glVertex2f(rocketX - 5, rocketY - 20);
		glColor3f(0,0.1,0.8);
        glVertex2f(rocketX + 5, rocketY - 20);
		glColor3f(0.8,0.1,0);
        glVertex2f(rocketX + 5, rocketY + 20);
    glEnd();



	    glBegin(GL_QUADS); // Rocket's tail
		glColor3f(0,0,0);
		glVertex2f(rocketX - 14, rocketY - 20);
		glColor3f(0.9,0.3,0.0);
        glVertex2f(rocketX - 18, rocketY - 30);
		glColor3f(0.0,0.0,0.0);
        glVertex2f(rocketX + 18, rocketY - 30);
		glColor3f(0.2,0.1,0.1);
        glVertex2f(rocketX + 14, rocketY - 20);
		glEnd();
}
  
void asteroids()//Asteroids
{
     
    for(i = 0; i < 4; i++)
    {
    
     
    glBegin(GL_QUADS);  
        glColor3f(0.2, 0.2, 0.3);   // Only one quad 
        glVertex2f(asteroidsX[i] - 4, asteroidsY[i] + 20);
        glVertex2f(asteroidsX[i] - 2, asteroidsY[i] - 20);
        glColor3f(0.9, 0.7, 0.7);
        glVertex2f(asteroidsX[i] + 2, asteroidsY[i] - 20);
		glColor3f(0.9, 0.1, 0.2);
        glVertex2f(asteroidsX[i] + 4, asteroidsY[i] + 20);
    glEnd();
 
   
     
    asteroidsY[i] = asteroidsY[i] - 16; 
		if(score > 100 && score < 150)                                    // Speed increase and Decrease
       asteroidsY[i] = asteroidsY[i] - 18;
		if(score > 150 && score < 200)
       asteroidsY[i] = asteroidsY[i] - 20;
		if(score > 200)
       asteroidsY[i] = asteroidsY[i] - 22;
     
    if(asteroidsY[i] > rocketY - 22 - 22 && asteroidsY[i] < rocketY + 22 + 22 && asteroidsX[i] == rocketX)   // Check for Collision
    {
        collide = true;                       // Collision checking 
    }
     
    if(asteroidsY[i] < -10)
    { 
        if(rand() % 4 == 0)
        {
            asteroidsX[i] = 100;
        }
        else if(rand() % 4 == 1)                    // Speed changing
        {
            asteroidsX[i] = 200;
        }
		else if(rand() % 4 == 2)
		{
            asteroidsX[i] = 300;
		}
		else
		{
            asteroidsX[i] = 400;
		}
        asteroidsY[i] = 600; 
    } 
    }
}



void mouse(int btn,int state,int x,int y)              // Mouse functionality
{

if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
asteroidsY[i] = asteroidsY[i] - 16;
}


 
void Specialkey(int key, int x, int y)      //keyboard button_down value and allow to use navigation key for movement of rocket
{
switch(key)
{
case GLUT_KEY_UP: 
	for(i = 0; i <4; i++)
             {
              asteroidsY[i] = asteroidsY[i] - 10;  
             }
             movd = movd - 20;
             break;	
case GLUT_KEY_DOWN: 
	for(i = 0; i <4; i++)
             {
              asteroidsY[i] = asteroidsY[i] + 10;  
             }
             movd = movd + 20;
             break;
case GLUT_KEY_LEFT: rocketX = rocketX - 100;
	                  if(rocketX<100)
						  rocketX=400;
             break;
case GLUT_KEY_RIGHT: rocketX = rocketX + 100;

	                   if(rocketX>400)
						   rocketX = 100;
					   break;
			 
}

glutPostRedisplay();
}
 


void Keyboard(unsigned char r,int x,int y)      
{
	switch (r)
	{
	case 27 : exit(0);


	case 13:
			button_down=1;	
			break;


}
}
 



void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 500, 0, 500);
glMatrixMode(GL_MODELVIEW);
}
 


void scene()                               // Display function 
{
   
    glClear(GL_COLOR_BUFFER_BIT);
    drawPath();
    drawRocket();
    asteroids();
    movd = movd - 16;
    if(movd < - 60)
    {
        movd = 0;
    }
     
    score = score + 1;

    glColor3f(1,1,1);
    drawText("Points:", 360,455);
    drawText(" <  LEFT  <", 450,53);
	drawText(" > RIGHT >", 450,35);
    itoa (score, buffer, 10);                // Convert integer to array of character string
    drawTextNum(buffer, 6, 400,455);
    glutSwapBuffers(); 
    for(q = 0; q<= 10000000; q++){;}
    if(collide == true)
    {
        glColor3f(1,0,0);
        drawText("COLLISION!", 200,240);
        glutSwapBuffers();
        getchar();
        //exit(0);
			
    }
    
}



void scene2()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();

glColor3f(0.0,0.0,0.0);
	drawText("BANGALORE TECHNOLOGICAL INSTITIUTE",185,420);
		

glColor3f(0.0,0.0,0.0);
	drawText("Computer Science & Engineering",205,400);
		

glColor3f(0.0,0.0,0.0);
	drawText("ROCKET & ASTEROIDS",205,300);
	glColor3f(1.0,1.0,0.0);
	drawText("-------------------",205,290);

		

glColor3f(1.0,1.0,1.0);
	drawText("Project Submitted by:",50,200);
	drawText("__________________",50,195);
		

glColor3f(1.0,1.0,0.0);
	drawText("Roshan Adhikari (1BH14CS046)",110,170);
		
glColor3f(1.0,1.0,0.0);
	drawText("Anuj Dubey (1BH13CS003)",110,150);
		
	glColor3f(0.6,0.0,0.0);
	drawText("Esc to Quit",50,30);
	glColor3f(0.6,0.0,0.0);
	drawText("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<",5,20);
	
	
	glColor3f(0.0,0.2,0.0);
	drawText("Journey to Space", 430,50);
	glColor3f(0.0,0.2,0.0);
	drawText("Hit Enter to FLY",430,30);
	glColor3f(0.0,0.2,0.0);
	drawText(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>",240,20);


		if(button_down==1)
	{

	glutDisplayFunc(&scene);
		
	glutIdleFunc(&scene);
	}
	glutSwapBuffers();
	glFlush();


}



 
 
void main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);     // # 3 colors and two buffers
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1360,710);
    glutCreateWindow("Journey to Space");
    background();
    init();
	glutSpecialFunc(Specialkey);    // For Keyboard
    glutKeyboardFunc(Keyboard);    //  For Exiting
	glutMouseFunc(mouse);          // Using Right Mouse Click to exit
	glutDisplayFunc(&scene2);
    glutIdleFunc(&scene2);
    glutMainLoop();
}