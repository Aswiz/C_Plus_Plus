#include <iostream>
#include <ctime>
#include <iomanip>      // std::setw
#include <stdlib.h>     // atoi 
#include "../ami/ami.h"

using namespace std;

int main(int argc, char *argv[]) {

	int x,
			i1,
			i2,
			i3,
			numbers[] = { 1, 2, 5 },
			sum[3],
			suma = 0;



	std::cout << "Input x: ";
	std::cin >> x;
	// std::cout << "x: " << x << endl;

	i1 = x / numbers[0];
	std::cout << "i1= " << i1	 << endl;
	i2 = x / numbers[1];
	std::cout << "i2= " << i2	 << endl;
	i3 = x / numbers[2];
	std::cout << "i3= " << i3	 << endl;


	for (int i = 0; i <= i1; ++i)
	{
		for (int j = 0; j <= i2; ++j)
		{
			for (int k = 0; k <= i3; ++k)
			{
				if ((i+j*2+k*5)==x)
				{	
					for (int l = 0; l < k; ++l)
					{
						cout << "5+";
					}
					for (int l = 0; l < j; ++l)
					{
						cout << "2+";
					}
					for (int l = 0; l < i; ++l)
					{
						if (l==i-1)
							cout << "1";
						else
							cout << "1+";
					}
					cout << " = " << i+j*2+k*5 << endl;
				}
			}
		}
	}
















	return 0;
}
