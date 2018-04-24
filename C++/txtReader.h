#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;



void txtRead(int sizeArr,char* fileName)
{
    char array[sizeArr];
    strcat(fileName, ".txt");
  //  strcat(fileName,".txt");
    FILE * ptrFile = fopen("NewYearTree.txt", "rb");
    int c, counter = 0;
    long ctr = 0;                                        // счетчик символов
    if (ptrFile == NULL) perror("Ошибка открытия файла");
    else
    {
      do
      {
        c = fgetc(ptrFile);
        array[ctr]=c;
        ctr++;
      } while (c != EOF); // пока не конец файла

      fclose (ptrFile);                                    // закрыть файл

      //std::cout << "Общее количество байтов: " << (ctr - 1);
    }
    for (int i = 0; i < (ctr-1); ++i)
    {
      cout<<array[i];
    }
  cout<<endl;



}
