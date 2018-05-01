// **************
// OLEH HORBATIUK
// 13.04.18
// **************

// Плохие коменты
// Если слишком мало колец то ломаеться

#include <iostream>

using namespace std;

//Обьявим наши функции, чтобы в дальнейшем их можно было вызывать из любой части кода
void hanoi(int n, int start, int finish, int buffer),
		 hanoi_n(int n, int start, int finish, int* buffers, int size_buffers),
		 releasingBuffers(int start, int finish, int* buffers, int size_buffers),
		 coutTower(int start, int finish);
int  fillingBuffers(int start, int finish, int* buffers, int size_buffers);

int main(int argc, char const *argv[]) {
  // Начальная позиция             - start  = 1
  // Конечная позиция              - finish
  // Количестов столбов            - columns
  // Количестов колец              - rings
  // Буффер         при columns=3  - buffer1
  // Размер буффера при columns>3  - size_buffers
  // Буфер при columns>3           - buffers
    int start = 1,
        finish,
        columns,
        rings,
        buffer1,
        size_buffers;
        //buffers

    // Выведем на экран сообщение "Введите количестов столбов"
    std::cout << "Input number of columns"<< std::endl;
    // Ожидаем от пользователя, т.е. вас, блядь. Никто кроме меня и вас не будет пользоваться этим дерьмом
    std::cin >> columns;

    // Выведем на экран сообщение "Введите количестов колец - rings"
    std::cout << "Input number of rings"<< std::endl;
    // Ожидаем от пользователя, т.е. вас, блядь. Никто кроме меня и вас не будет пользоваться этим дерьмом
    std::cin >> rings;

    // Выведем на экран сообщение "Введите конечную позицию"
    std::cout << "Input Finish position"<< std::endl;
    // Ожидаем от пользователя, т.е. вас, блядь. Никто кроме меня и вас не будет пользоваться этим дерьмом
    std::cin >> finish;

    // Если количество столбцов меньше трех то выписываем ошибку
    if (columns<3)
      std::cout << "Number of columns is less than three" << '\n';
    // Во всех остальных случаях:
    else
    {
      // Это нужно для дальнейшего тестирования кода в программе Хожеля
      // Выводим количество колец
      std::cout << '\n' << rings << '\n';
      // Выводим количество столбцов
      std::cout << columns << '\n';

      // Если количество столбцов равно трем то запускаем обычную функцию башни Хоноя, для трех столбов - hanoi
      if (columns==3)
      {
        // На основе известных позиций начального и нонечного столбцов находим номер столбца буффера(buffer1)
        for(int i=1; i<=columns;i++)
        {
          // Если номер столбца не является ни номером начального, ни конечного столбцов то это номер столбца буффера
          if((i!=start)&&(i!=finish))
          {
            buffer1 = i;
          }
        }
        // Запускаем функции башни Ханоя для трех столбцов
        hanoi(rings,start,finish,buffer1);
      }
      // Если количество столбцов больше трех то запускаем функцию башни Хоноя, для N столбцов - hanoi_n
      else if(columns>3)
      {
        // size_buffers - Количество буфферов на 2 меньше, чем количество столбцов (2 столбца занимает начало и конец)
        size_buffers = columns-2;
        int buffers[size_buffers];
        // Заполняем массив с буферами
        for(int i=1, x=0; i<=columns;i++)
        {
          // Буфферы занимают все свободные столбцы, а заняты на данный момет только столбцы начала и конца
          if((i!=start)&&(i!=finish))
          {
            buffers[x]=i;
            x++;
          }
        }
        // Запускаем функцию Башни Хоноя для N столбцов - hanoi_n
        hanoi_n(rings,start,finish,buffers,size_buffers);
      }
    }
    return 0;
}

// Функция выводит номера башен Ханоя через пробел
void coutTower(int start, int finish)
{
	std::cout << start << " " << finish << '\n';
}

// Пишу функцию заполнения дополнительных буфферов
int fillingBuffers(int start, int finish, int* buffers, int size_buffers)
{
	// 1. Перекладываем самые маленькие кольца на дополнительные буфферы (start->buffers)
	int j=1, // Ой сложно, я её только ввел, а уже не помню нахуя
	numbersOfRingsOnBuffers=0; //Количество колец находящихся на дополнительных буфферах

	// пока дополнительные буфферы не закончаться
	while ((size_buffers-j)>0)
	{
		//Заполняем финишную башню и башню-буффер для алгоритма hanoi(для 3-х) самыми верхними кольцами стартовой башни
		coutTower(start,buffers[size_buffers-1]);
		coutTower(start, finish);
		numbersOfRingsOnBuffers+=2;
		// заполняем буфферы кольцами из стартовой башни
		for(int i=0;i<size_buffers-j;i++)
		{
			coutTower(start, buffers[i]);
			numbersOfRingsOnBuffers++;
		}
		// и перекладываем их на полследний из доступных буфферов
		for(int i=size_buffers-j-2;i>=0;i--)
		{
			coutTower(buffers[i], buffers[size_buffers-j-1]);
		}
		//Перекладываем кольца с финишной башни и башни-буффера для алгоритма hanoi(для 3-х) на последний доступный буффер
		coutTower(finish, buffers[size_buffers-j-1]);
		coutTower(buffers[size_buffers-1], buffers[size_buffers-j-1]);
		j++;
	}
	// Возвращаем количество колец на дополнительных буфферах
	return numbersOfRingsOnBuffers;
}

// Пишу функцию очистки дополнительных буфферов
// Допиши коменты в функции releasingBuffers!!!
void releasingBuffers(int start, int finish, int* buffers, int size_buffers)
{
	int j=0; // Ой сложно, я её только ввел, а уже не помню нахуя
	// пока
	while (j<(size_buffers-1))
	{
		//
		coutTower(buffers[j], buffers[size_buffers-1]);
		coutTower(buffers[j], start);
		//
		for(int i=1; i<=j; i++)
		{
			coutTower(buffers[j], buffers[j-i]);
		}
		//
		coutTower(buffers[j], finish);
		//
		for(int i=0; i<j; i++)
		{
			coutTower(buffers[i], finish);
		}
		//
		coutTower(start, finish);
		coutTower(buffers[size_buffers-1], finish);
		j++;
	}
}
// Итак теперь у нас есть баня Старта(start) башня конца(finish) и массив башен-буфферов(занимают все отличные от начала и конца башни)
// Начальная позиция             - start  = 1
// Конечная позиция              - finish
// Количестов столбов            - columns
// Количестов колец              - rings
// Буффер         при columns=3  - buffer1
// Размер буффера при columns>3  - size_buffers
// Буфер при columns>3           - buffers

void hanoi_n(int n, int start, int finish, int* buffers, int size_buffers)
{

	int numbersOfRingsOnBuffers;//Количество колец находящихся на дополнительных буфферах
	numbersOfRingsOnBuffers=fillingBuffers(start,finish,buffers,size_buffers);
	// 2. После чего забываем про все вспомогательные буфферы кроме последнего(buffers[size_buffers-1]), который мы будем использовать для функции hanoi
	//    Запускаем рекурсивную функцию hanoi с параметрами n = n-size_buffers+1, start, finish и последним свободным буффером - buffers[size_buffers-1]
	//    n = n-size_buffers+1 - Общее количество колец - кольца оставшиеся на столбцах-буфферах
	//    и +1 из за того, что на последнем столбце-буффере нет кольца, так как мы используем этот буффер для функции hanoi
	hanoi(n-numbersOfRingsOnBuffers,start,finish,buffers[size_buffers-1]);
	// После этого все кольца,кроме колец, оставленных на столбцах-буфферах, будут находиться на конечной башне.
	// Для окончания алгоритма нам осталось переложить кольца с столбцов буфферов на конечную башню, что мы и сделаем.
	// 3. Перекладываем кольца c дополнительных буфферов на конечную башню в порядке убывания,
	// В начале самое большое(buffer[size_buffers-2]) а в конце самое маленькое(buffer[0]) (buffers->finish)
	releasingBuffers(start,finish,buffers,size_buffers);
}

void hanoi(int n, int start, int finish, int buffer)
{
	//Если количество колец(n) == 0 то выходим из функции(рекурсии) под названием hanoi
	if (n==0)
	{
		return;
	}
	// Eсли количество колец на башне под номером start больше нуля то :
	else
	{
		// 1. Перекладываем n-1 колец с башни начала(start) на башню-буффер(buffer)
		hanoi(n-1,start,buffer,finish);
		//    Самое большое кольцо останеться на начальной(start) башне, а остальные перейдут на башню буффер
		// 2. После чего перекладываем самое большое кольцо с стартовой позиции на конечную (start -> finish)
		coutTower(start, finish);
		//    Теперь Самое большое кольцо находится на финишной позиции, а остальные кольца на дополнительной башне(buffer)
		//    Начальная башня(start) теперь пуста
		// 3. Чтобы завершить алгоритм нам нужно переместить оставшие кольца c башни-буффера на конечную позицию
		//    Теперь в роли буффера будет выступать башня start так как она пустая,
		//    В роли стартовой башни - buffer
		//
		//    Начальная башня - buffer
		//    Конечная башня - finish
		//    Башня буффер - start
		hanoi(n-1,buffer,finish,start);
		// Итого все башни находятся на конечной башне
		// Finish!!!
	}
}

