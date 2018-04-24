#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "glut.h"
#include <iomanip>
using namespace std;

int sizeSorting = 2500;
int colorSortingRed = 255, colorSortingGreen =0,colorSortingBlue = 0;
int RotateX = 0, RotateY = 0, Zoom = -100;
int mas2d[10][10];
int mas1d[2500];
int k = 0;
int max = 0;
bool timerSorting = false;
bool saveSorting = false;

int *mas3 = new int[sizeSorting];


//1111111111111
//KeydoardEvent
//1111111111111
//
//----------------------------------------------------------------
//Rotate the camera with the mouse/ Вращение камеры с помощью мыши 
//Version / Версия 0.0.1
//Gorbatuk Oleg / Горбатюк Олег
//09.09.2016
//----------------------------------------------------------------
//Начальный поворот камеры по оси ОХ
int mouseRotateX0;
//Начальный поворот камеры по оси ОY
int mouseRotateY0;
//Начальная координата курсора по оси ОХ
int mouseX0;
//Начальная координата курсора по оси ОY
int mouseY0;
//Координата курсора по оси ОХ
int mouseX2;
//Координата курсора по оси ОY
int mouseY2;
//Изменение поворота камеры относительно оси ОХ
int changeMouseRotateX;
//Изменение поворота камеры относительно оси ОY
int changeMouseRotateY;
//Положение левой кнопки мыши (true - нажата)
bool downLeftButton = false;
void MouseMovePrintMode(int x, int y) {
	if (downLeftButton == true) {
		system("cls");
		//Получение координат курсора
		mouseX2 = x;
		mouseY2 = y;
		cout << "Координата курсора по оси ОХ (mouseX2) = " << mouseX2 << endl;
		cout << "Координата курсора по оси ОY (mouseY2) = " << mouseY2 << endl;
		//Вычисление изменения поворота камеры
		changeMouseRotateX = mouseX2 - mouseX0;
		changeMouseRotateY = mouseY2 - mouseY0;
		//cout << "Изменение поворота камеры относительно оси ОХ (changeMouseRotateX) = " << changeMouseRotateX << endl;
		//cout << "Изменение поворота камеры относительно оси ОY (changeMouseRotateY) = " << changeMouseRotateY << endl;
		//Изменение поворота камеры
		RotateX = mouseRotateX0 + changeMouseRotateY;
		RotateY = mouseRotateY0 + changeMouseRotateX;
		cout << "Поворот камеры относительно оси ОХ (RotateX) = " << RotateX << endl;
		cout << "Поворот камеры относительно оси ОY (RotateY) = " << RotateY << endl;
	}
}
void MouseButtonPrintMode(int button, int state, int x, int y) {
	// Только при нажатой левой кнопке мыши
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		downLeftButton = true;
		system("cls");
		//Получение начальных координат зажатого курсора
		mouseX0 = x;
		cout << "Начальные координата курсора по оси OХ (mouseX0) = " << mouseX0 << endl;
		mouseY0 = y;
		cout << "Начальные координата курсора по оси OY (mouseY0) = " << mouseY0 << endl;
		//Получение начального поворота камеры
		mouseRotateX0 = RotateX;
		cout << "Начальный поворот камеры относительно оси ОХ (mouseRotateX0) = " << mouseRotateX0 << endl;
		mouseRotateY0 = RotateY;
		cout << "Начальный поворот камеры относительно оси ОY (mouseRotateY0) = " << mouseRotateY0 << endl <<
			"========================================================================" << endl;
	}
	else {
		downLeftButton = false;
	}
}
//----------------------------------------------------------------
//Rotate the camera with the mouse/ Вращение камеры с помощью мыши 
//Version / Версия 0.0.1
//Gorbatuk Oleg / Горбатюк Олег
//09.09.2016
//----------------------------------------------------------------
void KubDisplay(int point_x1, int point_y1, int point_z1, int size, 
	bool color, double color_red, double color_green, double color_blue,
	bool line, double color_red2, double color_green2, double color_blue2) {
	color_red = color_red*0.003921568627451;
	color_green = color_green*0.003921568627451;
	color_blue = color_blue*0.003921568627451;
	color_red2 = color_red2*0.003921568627451;
	color_green2 = color_green2*0.003921568627451;
	color_blue2 = color_blue2*0.003921568627451;
	if (color == true) {
		glBegin(GL_POLYGON);
		glColor3d(color_red, color_green, color_blue);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3d(color_red, color_green, color_blue);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glVertex3f(point_x1, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1, point_z1 + size);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3d(color_red, color_green, color_blue);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glVertex3f(point_x1, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3d(color_red, color_green, color_blue);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glVertex3f(point_x1 + size, point_y1, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3d(color_red, color_green, color_blue);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3d(color_red, color_green, color_blue);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glVertex3f(point_x1, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1);
		glEnd();
	}
	////////////////////////////////
	if (line == true) {
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glVertex3f(point_x1, point_y1, point_z1);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glVertex3f(point_x1, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1, point_z1 + size);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glVertex3f(point_x1, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glVertex3f(point_x1, point_y1, point_z1);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glVertex3f(point_x1 + size, point_y1, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y1, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1, point_z1);
		glVertex3f(point_x1, point_y1, point_z1);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glVertex3f(point_x1, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1 + size);
		glVertex3f(point_x1 + size, point_y1 + size, point_z1);
		glVertex3f(point_x1, point_y1 + size, point_z1);
		glEnd();
	}
}
void Sorting2_1(int n,int mas[]) {
	if (saveSorting == false) {
		for (int i = 0; i < n; i++) {
			mas3[i] = mas[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			mas[i]= mas3[i];
		}
	}

}
void Sorting2(int n, int mas[]) {


	int *max = new int;

	/*
	for (int i = 0; i < 10; i++) {
	mas[i] = rand() % 10 + 1;
	}*/
	/*
	for (int i = 0; i < n; i++) {
	cout << mas[i] << " ";

	}
	*/
	//cout << endl;
	//system("pause");

		for (int i = 0; i < n - 1; i++) {
			if (mas[i + 1] < mas[i]) {
				*max = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = *max;
				//
				//system("cls");

				for (int i = 0; i < n; i++) {

					//cout << mas[i] << " ";
					//display();
					//cout << "mas[" << i << "]= " << mas[i] << "           " << "*max= " << *max << endl;
				}
				//Sleep(100);
				//

			}
		}
	
	//cout << endl << endl;
	//system("pause");
	/*
	for (int i = 0; i < n; i++) {
	cout << mas[i] << " ";
	//cout << "mas[" << i << "]= " << mas[i] << "           " << "*max= " << *max << endl;
	}
	*/
	//cout << endl;
	//delete mas;
	//delete max;
}
void display() {
	int kub_x = 0, kub_y = 0, kub_z = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-25, -25, Zoom);
	glRotatef(RotateX, 1, 0, 0);
	glRotatef(RotateY, 0, 1, 0);


	k = 0;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {

			colorSortingRed = mas1d[k];
			colorSortingGreen = mas1d[k];
			colorSortingBlue = mas1d[k];

			KubDisplay(j, i, 1, 1, true, colorSortingRed, colorSortingGreen,colorSortingBlue, true, 0, 0, 0);

			k++;
		}
	}

	

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void Sorting(int n, int mas[]) {


	int *max = new int;

	/*
	for (int i = 0; i < 10; i++) {
	mas[i] = rand() % 10 + 1;
	}*/
	/*
	for (int i = 0; i < n; i++) {
	cout << mas[i] << " ";

	}
	*/
	cout << endl;
	//system("pause");
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (mas[i + 1] < mas[i]) {
				*max = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = *max;
				//
				//system("cls");

				for (int i = 0; i < n; i++) {

					//cout << mas[i] << " ";
					//display();
					//cout << "mas[" << i << "]= " << mas[i] << "           " << "*max= " << *max << endl;
				}
				//Sleep(100);
				//

			}
		}
	}
	cout << endl << endl;
	//system("pause");
	/*
	for (int i = 0; i < n; i++) {
	cout << mas[i] << " ";
	//cout << "mas[" << i << "]= " << mas[i] << "           " << "*max= " << *max << endl;
	}
	*/
	cout << endl;
	//delete mas;
	//delete max;
}
void Random(int n, int mas[],int min,int max) {
	for (int i = 0; i < n; i++) {
			mas[i] = rand() % max + min;
			cout << mas[i]<< ", ";
		}
		cout << endl;
}
void KeyboardEvent(unsigned char key, int a, int b) {
	switch (key)
	{
	case 'e': Sorting(2500, mas1d); break;
	case ' ':  timerSorting = true;  break;
	case 'r': saveSorting = false; Sorting2_1(2500, mas1d); break;
	case 't': saveSorting = true; Sorting2_1(2500, mas1d); break;
	case 'q': Random(2500, mas1d,0,255); break;
	default:
		break;
	}
}
void mouseMove(int x, int y) {
	MouseMovePrintMode(x, y);
}
void mouseButton(int button, int state, int x, int y) {
	MouseButtonPrintMode(button, state, x, y);
}

void timer(int = 0)
{
	if (timerSorting == true)
	{
		for (int j = 0; j <2500; j++) {
			Sorting2(2500, mas1d);
			display();
		}
		timerSorting = false;
	}
	else {

		display();
	}
	glutTimerFunc(1, timer, 0);
}

int main(int argc, char*argv[]) {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int Nmas = 50;
	int Mmas = 50;
	
	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {
			mas2d[i][j] = rand() % 255 + 1;
		}
	}
	
	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {
			
			cout << setw(3) << mas2d[i][j] << " ";
			
		}
		cout << endl;
	}

	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {
			mas1d[k] = mas2d[i][j];
			k++;
		}
	}
	

	for (int i = 0; i < Nmas*Mmas; i++) {
		cout << mas1d[i] << " ";
	}
	/*
	for (int j = 0; j < 99; j++) {
		for (int i = 0; i < 99; i++) {
			if (mas1d[i] > mas1d[i + 1]) {
				max = mas1d[i];
				mas1d[i] = mas1d[i + 1];
				mas1d[i + 1] = max;
				
			}
			//cout << mas1d[i] << " ";
		}
	}
	*/
	
	for (int i = 0; i < Nmas*Mmas; i++) {
		cout << mas1d[i] << " ";
	}

	k = 0;
	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {
			 mas2d[i][j]= mas1d[k] ;
			k++;
		}
	}

	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {

			cout << setw(3) << mas2d[i][j] << " ";

		}
		cout << endl;
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(690, 690);
	glutInitWindowPosition(660, 0);
	glutCreateWindow("Time");
	glClearColor(0.58, 0, 0.827, 1.0);  //цвет фона
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 0, 100);
	glutDisplayFunc(display);
	glutKeyboardFunc(KeyboardEvent);
	glutTimerFunc(10, timer, 0);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutMainLoop();
	return 0;
}