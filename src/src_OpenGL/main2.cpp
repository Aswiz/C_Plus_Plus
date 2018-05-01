#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "../OpenGlLib/free/glut.h"
#include <iomanip>
//#include <Windows.h>
using namespace std;

int sizeSorting = 2500;
int colorSortingRed = 255, colorSortingGreen =0,colorSortingBlue = 0;
int RotateX = 0, RotateY = 0,
TranslateX=-25, TranslateY=-25,Zoom = -100;
//mas1
int mas1d_1_Size[2] = { 10,10 };
int mas1d_1_Size_2 = mas1d_1_Size[0] * mas1d_1_Size[1];
int mas1d_1[100];
int mas2d_1[10][10];
//mas1_2
int mas1d_1_2_Size[2] = { 10,10 };
int mas1d_1_2_Size_2 = mas1d_1_2_Size[0] * mas1d_1_2_Size[1];
int mas1d_1_2[100];
int mas2d_1_2[10][10];
//mas2
int mas1d_2_Size[2] = { 40,40 };
int mas1d_2_Size_2 = mas1d_2_Size[0] * mas1d_2_Size[1];
int mas1d_2[3600];
int mas2d_2[40][40];


int k = 0;
int max = 0;
bool timerSorting_1 = false;
bool timerSorting_1_2 = false;
bool timerSorting_1_2_3 = false;
int mas1d_1_2_Y = 0;

bool timerSorting_2 = false;
bool saveSorting = false;
bool kub2display = false;
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
		system("clear");
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
		system("clear");
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
void Kub2dDisplay(double point_x1, double point_y1, double point_z1,
				  double point_x2, double point_y2, double point_z2,
			   	  bool color, double color_red, double color_green, double color_blue,
				  bool line, double color_red2, double color_green2, double color_blue2)
{
	glBegin(GL_POLYGON);
	glColor3d(color_red, color_green, color_blue);
	glVertex3f(point_x1, point_y1, point_z1);
	glVertex3f(point_x1, point_y2, point_z1);
	glVertex3f(point_x2, point_y2, point_z2);
	glVertex3f(point_x2, point_y1, point_z2);

	glEnd();
	if (line == true) {
		glBegin(GL_LINE_STRIP);
		glColor3d(color_red2, color_green2, color_blue2);
		glVertex3f(point_x1, point_y1, point_z1);
		glVertex3f(point_x1, point_y2, point_z1);
		glVertex3f(point_x2, point_y2, point_z2);
		glVertex3f(point_x2, point_y1, point_z2);
		glVertex3f(point_x1, point_y1, point_z1);
		glEnd();
	}
}
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
	for (int i = 0; i < n - 1; i++) {
		if (mas[i + 1] < mas[i]) {
			*max = mas[i];
			mas[i] = mas[i + 1];
			mas[i + 1] = *max;
		}
	}
	delete max;
}
void Sorting2_2(int n, int mas[],int k) {
	int *max = new int;
	for (int i = 0; i < n - 1; i++) {
		if (mas[i + 1] < mas[i]) {
			*max = mas[i];
			mas[i] = mas[i + 1];
			mas[i + 1] = *max;
		}
	}
	delete max;
}
void display() {

	int kub_x = 0, kub_y = 0, kub_z = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glEnable(GL_DEPTH_TEST);    //разрешить тест глубины
	//glDepthFunc(GL_LEQUAL);
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glShadeModel(GL_SMOOTH);                             // Включается плавное затенение
	glEnable(GL_LINE_SMOOTH);                            // Включается сглаживание линий
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);              // Выбирается самый качественный
														 // режим сглаживания для линий
	glEnable(GL_BLEND);                                  // Включается смешение цветов, необходимое
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // для работы сглаживания и задается


	glPushMatrix();
	glTranslatef(TranslateX, TranslateY, Zoom);
	glRotatef(RotateX, 1, 0, 0);
	glRotatef(RotateY, 0, 1, 0);


	k = 0;
	for (int i = 0; i < mas1d_1_Size[0]; i++) {
		for (int j = 0; j < mas1d_1_Size[1]; j++) {

			colorSortingRed = mas1d_1[k];
			colorSortingGreen = mas1d_1[k];
			colorSortingBlue = mas1d_1[k];

			KubDisplay(j, i, 1, 1, true, colorSortingRed, colorSortingGreen,colorSortingBlue, false, 0, 0, 0);

			k++;
		}
	}
	k = 0;
	if (kub2display == true) {
		for (int i = 0; i < mas1d_1_Size[0]; i++) {
			for (int j = 0; j < mas1d_1_Size[1]; j++) {

				colorSortingRed = mas1d_2[k];
				colorSortingGreen = mas1d_2[k];
				colorSortingBlue = mas1d_2[k];

				KubDisplay(j - mas1d_1_2_Size[0]-1, i, 1, 1, true, colorSortingRed, colorSortingGreen, colorSortingBlue, false, 0, 0, 0);

				k++;
			}
		}

	}
	k = 0;
	if (timerSorting_1_2 == true) {
		for (int i = 0; i < mas1d_1_2_Size[0]; i++) {
			for (int j = 0; j < mas1d_1_2_Size[1]; j++) {

				colorSortingRed = mas1d_1_2[k];
				colorSortingGreen = mas1d_1_2[k];
				colorSortingBlue = mas1d_1_2[k];
				if (mas1d_1_2_Y < mas1d_1_2_Size[0])mas1d_1_2_Y++;
				KubDisplay(j, i + mas1d_1_2_Y + 1 , 1, 1, true, colorSortingRed, colorSortingGreen, colorSortingBlue, false, 0, 0, 0);

				k++;
			}
		}
	}
/*	Kub2dDisplay(0, 0, 0, 10, 10, 0, true, 0, 255, 0, true, 0, 0, 0);
	Kub2dDisplay(10, 0, 0, 10, 10, 10, true, 255, 100, 200, true, 0, 0, 0);
	Kub2dDisplay(0, 0, 0, 10, 10, 10, true, 255, 0, 200, true, 0, 0, 0);
	glutWireCube(10.0f);
	*/
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
			//cout << mas[i]<< ", ";
		}
	//	cout << endl;
}
void CameraUp(int zoom) {
		zoom--;
}
void SaveMas1d(int n1, int mas1[], int mas2[]) {
	for (int i = 0; i < n1; i++) {
		mas1[i] = mas2[i];
	}
}
void KeyboardEvent(unsigned char key, int a, int b) {
	switch (key)
	{
	case 'e': Sorting(mas1d_1_Size_2, mas1d_1); break;
	case ' ':  timerSorting_1 = true; CameraUp(Zoom); SaveMas1d(mas1d_1_2_Size_2,mas1d_1_2,mas1d_1); break;
	case 'o':SaveMas1d(mas1d_1_Size_2, mas1d_1, mas1d_1_2); break;
	case 'r': saveSorting = false; Sorting2_1(mas1d_1_Size_2, mas1d_1); break;
	case 't': saveSorting = true; Sorting2_1(mas1d_1_Size_2, mas1d_1); break;
	case 'q': Random(mas1d_1_Size_2, mas1d_1,0,255); break;
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
	if (timerSorting_1 == true)
	{
		for (int j = 0; j <mas1d_1_Size_2; j++) {
			Sorting2(mas1d_1_Size_2, mas1d_1);

			if (Zoom > -150) {
				Zoom--;
			}
			if (TranslateX < 0) {
				TranslateX++;
			}
			display();
		}
		timerSorting_1 = false;
		timerSorting_1_2 = true;
	}
	else {

	display();
	}
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char*argv[]) {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int Nmas = mas1d_1_Size[0];
	int Mmas = mas1d_1_Size[1];
	int NMmas = Nmas*Mmas;


	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {
			mas2d_1[i][j] = rand() % 255 + 1;
			mas2d_2[i][j] = rand() % 255 + 1;
		}
	}
	k = 0;
	for (int i = 0; i < Nmas; i++) {
		for (int j = 0; j < Mmas; j++) {
			mas1d_1[k] = mas2d_1[i][j];
			mas1d_2[k] = mas2d_2[i][j];
			k++;
		}
	}



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(690,690);
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
