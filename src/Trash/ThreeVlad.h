//#pragma once
#include <iostream>

using namespace std;

float FsizeNumber(float number);
void searchPoints(float number,int &point1,int &point2);
void swapRandomDigits(float number);

float FsizeNumber(float number)
{
	float size=number;
	int k=0;
	while(size>1){
		size/=10;
		k++;
	}
//	cout<<"size="<<k<<endl;
	return k;
}


 void searchPoints(float number,int &point1,int &point2)
{
	srand( time( 0 ) ); // автоматическая рандомизация
	int size=FsizeNumber(number);

	point1=rand()%size+1;
	point2=rand()%size+1;

	while(point1==point2)
	{
		point2=rand()%size+1;
	}
//dasdasdas

//	cout<<"point1="<<point1<<endl;
//	cout<<"point2="<<point2<<endl;
}
//***
//В передаваемом числе меняет местами дву случайные цифры
//***
void swapRandomDigits(float number)
{
	int point1,point2;
	searchPoints(number,point1,point2);

	//int massGigits[int(FsizeNumber(number))];

	int x;
	for (int i = 0; i < int(FsizeNumber(number)); ++i)
	{
		x=int(number)%10;
		cout<<"x="<<x<<endl;
	}
}
