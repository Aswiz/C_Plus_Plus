#include <iostream>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
int main ()
{
  char mass[6000];

  FILE * ptrFile = fopen("NewYearTree.txt", "rb");
  int c, counter = 0;
  long ctr = 0;                                        // счетчик символов
  if (ptrFile == NULL) perror("Ошибка открытия файла");
  else
  {
    do
    {
      c = fgetc(ptrFile);
      mass[ctr]=c;
     // cout<<mass[ctr];
      ctr++;
    } while (c != EOF); // пока не конец файла

    fclose (ptrFile);                                    // закрыть файл

    //std::cout << "Общее количество байтов: " << (ctr - 1);
  }
  for (int i = 0; i < (ctr-1); ++i)
  {
    cout<<mass[i];
  }
cout<<endl;



  return 0;
}
