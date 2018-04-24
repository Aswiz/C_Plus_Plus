using namespace std;
#include <iostream>
void func(int c);



int main()
{
	int i=100000000, k;
	while (i <1000000000)
	{
		i++;
		func(i);
	}



	system("pause");
}


void func(int c)
{
	int count = 0;
	for (int b = 1; b < 21; b++)
	{
		if (c%b == 0)
		{
			count++;
		}
		else
		{
			cout << "";
		}

	}
	if (count == 20)
	{
		cout << c << ends;
	}
	else
	{
		cout << "";
	}
}
