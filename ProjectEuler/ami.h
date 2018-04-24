//AMI - Aswis Mathematical Library
#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>      // std::setw

#include "txtReader.h"

using namespace std;


//Функция находит длину числа
int discharge(int var){
    int size_var=0;

    while (var>0) {
        var/=10;
        size_var++;
    }
    //std::cout << size_var << '\n';
    return size_var;
}

//Функция возвращает цифру по её номеру от начала числа
//Например Функция getDigitWhithNumber(54321,4) вернет значение 2
//А если int number > int var вернет ошибку - "Error: номер цифры больше длины числа"
int getDigitWhithNumber(int var,int number)
{
    int first=0;
    if(discharge(var)>=number)
    {
        while (discharge(var)!=number)
        {
            var/=10;
        }
        //std::cout << var << '\n';

        first=var%10;
        //std::cout << first << '\n';

        return first;
    }
    else
    {
        cout<<"Error: номер цифры больше длины числа"<<endl;

        return 0;
    }
}

//divided without any remainder
//Проверка остатка от деления двух числе
//Если число поделилось без остатка то возвращает true в другом случае false
bool DWAR(int var,int number)
{
    float check=var%number;

    if(check==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Функция получает Массив символов и номер элемента
//Возвращает элемент массива с заданным номером
//Eсли это цифра то преобразовывает чар в инт.
int getDigitFromCharArray(char* array, int number)
{
    return int(array[number])-48;
}

//fllor - округление
//fllorMax - округление до наибольшего значения
//0,1->1  0,5->1  0,9->1
int floorMax(double number)
{
    number+=0.999999;
    return floor(number);
}

//Функция проверяющая простое ли число
//v0.2
bool primeNumber(int var)
{
    if (var<=1)
    {
        return false;
    }

    if ((var!=2)&&((var%2)==0)) {
        //std::cout << "Четное - " << var << '\n';
        return false;
    }
    else
    {
        for(int i=3;i<=floorMax(sqrt(var));i+=2)
        {
            if((var%i)==0)
            {
                return false;
            }
        }
    }
    return true;
}


//Принимает в себя символ и проверяет число ли он
//Если он число то возвращает его под типом int
//А если нет - то возвращает -1
bool isItDigits(char x_char)
{
    int x=x_char;
    if ((x>=48)&&(x<=57))
        return true;
    else
        return false;
}

//Поиск чисел в чар-массиве
void searchDigits(char* array,int* array_int,int size_array,int* _array_int_index)
{
    //char digits[2];
    //char var[1];
    int numbers[size_array],
        k=0,
        p=0,
        number=0,
        array_int_index=0,
        mass_i=0,
        mass_j=0;
        int mass[150][150];
    for(int i=0;i<size_array;i++)
    {
        if (isItDigits(array[i])==true)
        {
            numbers[k]=getDigitFromCharArray(array,i);
            k++;
            p++;
            mass[mass_i][mass_j]=numbers[k];
            mass_j++;
        }
        else
        {
            if(p>0)
            {
                number=numbers[k-1];
                while (p!=0)
                {
                    for (int z = 1; z < p; z++)
                    {
                        numbers[k-p]*=10;
                        number+=numbers[k-p];
                    }
                    p--;
                }
                array_int[array_int_index]=number;
                mass_i++;
                array_int_index++;
            }
        }
    }
    *_array_int_index=array_int_index;
}


int name(int var)
{
    int quantity_divisors=0;
    for (int i = 1; i <= var; i++)
    {
        if ((var%i)==0) {
            quantity_divisors++;
        }
    }
    //std::cout << "quantity_divisors = " << quantity_divisors << '\n';
    return quantity_divisors;
}

int divisors(int var,int quantity_divisors)
{

    int divisors[quantity_divisors],
        k=0;
    for(int i=0;i<quantity_divisors;i++)
    {
        divisors[i]=0;
    }


    //std::cout << var << " - ";
    quantity_divisors=0;
    for (int i = 1; i <= int(sqrt(var)+0.99999); i++)
    {
        if ((var%i)==0) {
            divisors[k]=i;
            k++;
            divisors[k]=var/i;
            k++;
        }
    }
    quantity_divisors=k;


    for(int i=0;i<k;i++)
    {
        std::cout << divisors[i] << "; ";
    }
    std::cout << "" << '\n';

    for(int i=0;i<k-1;i++)
    {
        for(int j=i;j<k-1;j++)
        {
            if (divisors[i]==divisors[j+1])
            {
                quantity_divisors--;
            }
        }
    }
    return quantity_divisors;
}

//Функция coutArray выводит массив
template <typename T>
void coutArray(T* array,int array_size)
{
    for (size_t i = 0; i < array_size; i++) {
        std::cout << array[i];
    }
}
template <typename T>
void coutArray(T* array,int array_size,string spase)
{
    for (size_t i = 0; i < array_size; i++) {
        std::cout << array[i] << spase;
    }
}
template <typename T>
void coutArray(T* array,int array_size,string spase,int endL)
{
    std::cout << '\n';
    for (size_t i = 0; i < array_size; i++) {
        if (((i%endL)==0)&&(i>0))
        {
            std::cout << '\n';
        }
        std::cout << std::setw(2);
        std::cout << array[i] << spase;

    }
    std::cout << '\n';
}
template <typename T>
void coutArray(T* array,int array_size,string spase,int endL,int setw)
{
    std::cout << '\n';
    for (size_t i = 0; i < array_size; i++) {
        if (((i%endL)==0)&&(i>0))
        {
            std::cout << '\n';
        }
        std::cout << std::setw(setw);
        std::cout << array[i] << spase;

    }
    std::cout << '\n';
}

//Вывод массива для визуализации сортировки
//Функция должна показывать какой элемент куда перемещается при каждом шаге сортировки
template <typename T>
void coutArray(T* array,int array_size,string spase,int endL,int setw,int target)
{
    std::cout << '\n';
    for (size_t i = 0; i < array_size; i++) {
        if (((i%endL)==0)&&(i>0))
        {
            std::cout << '\n';
        }
        if (i==target){
          std::cout << std::setw(setw);
          std::cout << array[i] << " <- ";
        }
        else
        {
          std::cout << std::setw(setw);
          std::cout << array[i] << spase;
        }
    }
    std::cout << '\n';
}
//Функция coutArray выводит массив

//
template <typename T>
int indexOfMinOfArray(T* array,int array_size)
{
    float min=array[0];
    int minIndex;
    for(int i=0;i<array_size;i++)
    {
        if (min>array[i])
        {
            min=array[i];
            minIndex=i;
        }
    }
    return minIndex;
}
template <typename T>
int indexOfMinOfArray(T* array,int array_size,int start)
{
    float min=array[0+start];
    int minIndex=start;
    for(int i=0+start;i<array_size;i++)
    {
        if (min>array[i])
        {
            min=array[i];
            minIndex=i;
        }
    }
    return minIndex;
}
//

template <typename T>
int minOfArray(T* array,int array_size)
{
    float min=array[0];
    int minIndex=0;
    for(int i=0;i<array_size;i++)
    {
        if (min>array[i])
        {
            min=array[i];
            minIndex=i;
        }
    }
    return min;
}

template <typename T>
int minOfArray(T* array,int array_size, int start)
{
    float min=array[0+start];
    int minIndex=0;
    for(int i=0+start;i<array_size;i++)
    {
        if (min>=array[i])
        {
            min=array[i];
            minIndex=i;
        }
    }
    return min;
}

template <typename T>
void randDigits(T* array, int size_array, int max, int min)
{
    max++;
    srand( time(0) );
    for(int i=0;i<size_array;i++)
    {
        array[i]=min + rand() % (max - min);
    }
}

template <typename T>
void Sort1(T* array, int size_array, int start)
{


    for(int i=start; i<size_array;i++)
    {
        float min_array=minOfArray(array, size_array,i),
              boofer;

        int index_min_array=indexOfMinOfArray(array, size_array, i);

        boofer=array[start];
        array[start]=min_array;
        array[index_min_array]=boofer;

        // std::cout << endl << min_array << '\n';
        // std::cout << index_min_array << '\n';
        // coutArray(array, size_array, " ", 10, 2);

        start++;
    }
}


template <typename T>
void bubbleSort(T* array, int size_array, int start)
{
  float boofer;
  for(int j=start; j<size_array; j++)
  {
      for(int i=start; i<size_array-1; i++)
      {
        if (array[i]>array[i+1])
        {
          boofer=array[i+1];
          array[i+1]=array[i];
          array[i]=boofer;
        }
      }
  }
}


//Меняет местами array[start] и array[finish]
template <typename T>
void sortSwap(T* array, int start, int finish)
{
  float boofer;

  boofer=array[finish];
  array[finish]=array[start];
  array[start]=boofer;
}

template <typename T>
void insertionSort(char* array, int size_array, int start)
{
  for(int i=start; i<size_array; i++)
  {
    coutArray(array, size_array, " ", 10, 2, i);
    int j=i;
    int check_index=0;
    bool check=false;
    while (j!=0)
    {
      if (array[j-1]>array[j])
      {
      sortSwap(array, j-1, j);
      check=true;
      check_index=j-1;
      }
      j--;
    }
    if (check)
        coutArray(array, size_array, " ", 10, 2,check_index);

    std::cout << "---------" << '\n';
  }

}

