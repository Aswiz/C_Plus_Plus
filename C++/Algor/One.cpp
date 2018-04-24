#include <iostream>
#include <ctime>

#include "../../ProjectEuler/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {

    srand(time(NULL));


    int sizeArray=1000,
        array[sizeArray],
        k=0,
        max=0,
        max_index=0;


    for(int i=0;i<sizeArray;i++)
    {
        array[i]=rand()%100;
    }
    coutArray(array,sizeArray," ",20);

    for(int i=0;i<sizeArray;i++)
    {
        k=0;
        for(int j=0;j<sizeArray;j++)
        {
            if (array[i]==array[j])
            {
                k++;
            }
        }
        if (max_index<k)
        {
            max_index=k;
            max=array[i];
        }
    }

    std::cout << "Max = " << max << '\n';
    std::cout << "Return size = " << max_index << '\n';

    int sum=0;
    for(int i=0;i<=100;i++)
    {
        sum+=i;
    }
    cout<<sum<<endl;

    return 0;
}
//
//g++ /home/aswiz/Documents/C++/Algor/One.cpp -o Vlad
