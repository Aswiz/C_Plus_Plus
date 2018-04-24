#include <iostream>
using namespace std;

int main(){
	int x;//Вводимая переменна
	long long fact=1;

	cout<<"Введите число: ";
	cin>>x;

	for (int i = 1; i <= x; ++i)
	{	
		fact*=i;
		//cout<<fact<<" ";
	}

	cout<<"Факториал от числа равен: "<<fact<<endl;

	//system("pause");
	return 0;
}