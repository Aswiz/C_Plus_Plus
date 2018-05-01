#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;



void txtRead(int sizeArr,string fileName)
{
    char array[sizeArr];

    FILE * ptrFile = fopen(fileName.c_str(), "rb");
    int c;
    long ctr = 0;        // счетчик символов
    if (ptrFile == NULL) perror("Ошибка открытия файла");
    else
    {
      do
      {
        c = fgetc(ptrFile);
        array[ctr]=c;
        ctr++;
      } while (c != EOF); // пока не конец файла

      fclose (ptrFile);   // закрыть файл

      //std::cout << "Общее количество байтов: " << (ctr - 1);
    }
    for (int i = 0; i < (ctr-1); ++i)
    {
      cout<<array[i];
    }
  cout<<endl;
}


int txtRead_v2(char* array,string fileName)
{

    FILE * ptrFile = fopen(fileName.c_str(), "rb");
    int c;
    long ctr = 0;        // счетчик символов
    if (ptrFile == NULL) perror("Ошибка открытия файла");
    else
    {
      do
      {
        c = fgetc(ptrFile);
        array[ctr]=c;
        ctr++;
      } while (c != EOF); // пока не конец файла

      fclose (ptrFile);   // закрыть файл

      //std::cout << "Общее количество байтов: " << (ctr - 1);
    }
    /*
    for (int i = 0; i < (ctr-1); ++i)
    {
      cout<<array[i];
    }
  cout<<endl;
  */
  return  ctr-1;
}
