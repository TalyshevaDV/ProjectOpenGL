#include <iostream>
// #include <GLUT/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
// #include <glm/gtc/matrix_transform.hpp> //glm::translate, glm::rotate, glm::scale, glm::perspective

using namespace std;
// using namespace glm;

//Объявляем глобальные переменные
float rquad = 0;
float xr = 0, yr = 0;

class cub
{
	float x;
	float y;
	float z;

	public:
	cub(float _x = 0, float _y = 0, float _z = 0)
	{	}
	void Draw()
	{
		glRotatef(rquad, 1.0f, 1.0f, 0.0f);

		glBegin(GL_QUADS);
		//верхняя грань
		glColor3f(1.0, 1.0, 1.0);        //red
		glVertex3f( -10.5, 10.5, -10.5); // A
		glVertex3f( -10.5, 10.5, 10.5);  // B
		glVertex3f( 10.5, 10.5, 10.5);   // C
		glVertex3f( 10.5, 10.5, -10.5);  // D

		//нижняя грань
		glColor3f( 0.0, 1.0, 0.0);       // green
		glVertex3f( -10.5, -10.5, 10.5); // A
		glVertex3f( -10.5, -10.5, -10.5);// B
		glVertex3f( 10.5, -10.5, -10.5); // C
		glVertex3f( 10.5, -10.5, 10.5);  // D

		//передняя грань
		glColor3f( 0.0, 0.0, 1.0);       // blue
		glVertex3f(-10.5, 10.5, 10.5);   // A
		glVertex3f(-10.5, -10.5, 10.5);  // B
		glVertex3f(10.5, -10.5, 10.5);   // C
		glVertex3f(10.5, 10.5, 10.5);    // D

		//задняя грань
		glColor3f( 1.0, 0.0, 1.0);       //purple
		glVertex3f(-10.5, -10.5, -10.5); // A
		glVertex3f( -10.5, 10.5, -10.5); // B
		glVertex3f( 10.5, 10.5, -10.5);  // C
		glVertex3f(10.5, -10.5, -10.5);  // D

		//правая грань
		glColor3f( 0.0, 1.0, 1.0);        //turquoise
		glVertex3f(10.5, 10.5, 10.5);     // A
		glVertex3f( 10.5, -10.5, 10.5);   // B
		glVertex3f( 10.5, -10.5, -10.5);  // C
		glVertex3f(10.5, 10.5, -10.5);    // D

		//левая грань
		glColor4f( 1.0, 1.0, 0.0, 1.0);        //yellow
		glVertex3f(-10.5, 10.5, -10.5);   // A
		glVertex3f( -10.5, -10.5, -10.5); // B
		glVertex3f( -10.5, -10.5, 10.5);  // C
		glVertex3f(-10.5, 10.5, 10.5);    // D

		glEnd();
		rquad -= 0.005f;

		glFlush();
		glutPostRedisplay();
		glutSwapBuffers();
	}
}cub(0, 0, 0);

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cub.Draw();
}

void specialkey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			yr = yr + 1;
			cout<<y<<endl;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			yr--;
			cout<<y<<endl;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			xr--;
			cout<<x<<endl;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			xr;
			cout<<x<<endl;
			glutPostRedisplay();
			break;

	}
}

void timer (int = 0)
{
	display();
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
  int WinH = 600;
  int WinW = 800;
	cout << "use array key" << endl;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //окно с поддержкой двойной буферизации,
  glutInitWindowSize(WinW, WinH);                           //z-буферизации и цветовой схемы True Color
	glutInitWindowPosition(100, 20);
	glutCreateWindow("3D");
	glutDisplayFunc(display);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	glOrtho(-100, 100, 100, -100, -100, 100);
	glutSpecialFunc(specialkey);
	timer();
  glutMainLoop();
	return 0;
}
# ProjectOpenGL
