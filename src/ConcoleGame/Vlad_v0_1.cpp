#include <iostream>
//#include <conio.h>
#include <time.h>
using namespace std;
const int X = 50;
const int Y = 50;
int heroX;
int heroY;
void AddEnemy(char field[X][Y],int count);
void Show(char field[X][Y])
{
	system("cls");
	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			
			cout << field[i][j];
		}
		cout << endl;
	}
}

void Initialize(char field[X][Y])
{
	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			field[i][j] = ' ';
		}
	}
	heroX = X - 1;
	heroY = Y / 2;
	field[heroX][heroY] = 30;
}
void MoveHeroLeft(char field[X][Y])
{
	field[heroX][heroY - 1] = field[heroX][heroY];
	field[heroX][heroY] = ' ';
	heroY--;
}
void MoveHeroRight(char field[X][Y])
{
	field[heroX][heroY + 1] = field[heroX][heroY];
	field[heroX][heroY] = ' ';
	heroY++;
}


int main()
{
	srand(time(0));
	char field[X][Y];
	Initialize(field);
	int counter = clock() + 1000;
	// while (true)
	// {
	// 	if (_kbhit())
	// 	{
	// 		auto x = _getch();
	// 		//75 - left
	// 		//77-right
	// 		//cout << x;
	// 		switch (x)
	// 		{
	// 		case 75:
	// 			MoveHeroLeft(field);
	// 			Show(field);
	// 			break;
	// 		case 77:
	// 			MoveHeroRight(field);
	// 			Show(field);
	// 			break;
	// 		default:
	// 			break;
	// 		}
	// 	}
	// 	if (clock() > counter)
	// 	{
	// 		AddEnemy(field, 5);
	// 		Show(field);
	// 		counter = clock() + 1000;
	// 	}
	// }
					MoveHeroRight(field);
				Show(field);

}

void AddEnemy(char field[X][Y],int count)
{
	for (size_t i = 0; i <X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			if ( i < count)
			{
				field[i][j] ='*';
				cout << field[i][j] << ends;
			}

		}
	}
}

void MoveEnemy(char field[X][Y])
{

}