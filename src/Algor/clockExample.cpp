//пример использования функции clock
// для оператора cout
#include <iostream>
// для функции clock
#include <ctime>
// для функции sqrt
#include <cmath>
 
// функция поиска простых чисел
int frequencyPrimes (int n)
{
	int freq = n-1;
	for (int i = 2; i <= n; ++i)
			for (int j = sqrt( (float)i ); j > 1; --j)
					if (i % j == 0)
					{
						--freq;
						break;
					}
	return freq;
}

int main ()
{
	std::cout <<  "Вычисление..." << std::endl;
	int f = frequencyPrimes (100000);
	// ищем простые числа в интервале от 2 до 100000
	int t = clock();                                           // получаем количество тиков времени
	std::cout << "Количество простых чисел меньших 100 000 = "
						<< f << std::endl;
	std::cout << "Для вычисления понадобилось "
						<< t << " тиков времени или "
						<< ((float)t) / CLOCKS_PER_SEC << " секунд.n"
						<< std::endl;
 
	return 0;
}