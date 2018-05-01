#include <iostream>
#include <iomanip>      // std::setw

#include "ami.h"


using namespace std;

int main(int argc, char const *argv[]) {

    char array[6000];

    int size_array=txtRead_v2(array, "numbers.txt"),
        mass_j=51,
        mass_i=size_array/mass_j,
        mass[mass_i][mass_j],
        sum_mass_j[mass_j];

    //coutArray(array,size_array);
    //std::cout << mass_i << '\n';
    int k=0;
    for(int i=0; i<mass_i; i++)
    {
        for(int j=0; j<mass_j; j++)
        {
            if (int(array[k]==10))
            {
                mass[i][j]=0;
            }
            else
            {
                mass[i][j]=int(array[k])-48;
            }

            k++;
        }
    }

    for(int i=0; i<mass_i; i++)
    {
        for(int j=0; j<mass_j; j++)
        {
            std::cout << mass[i][j];
        }
        std::cout << "" << '\n';
    }

    for(int i=0;i<mass_j;i++)
    {
        for(int j=0;j<mass_i;j++)
        {
            sum_mass_j[i]+=mass[j][i];
        }
    }

    for(int i=0;i<mass_j;i++)
    {
        if (i==(mass_j/2)) {
            std::cout << "" << '\n';
        }
        std::cout << sum_mass_j[i] << ' ';
    }

/*
    int test=48;
    std::cout << "" << '\n';
    std::cout << sum_mass_j[test] << '\n';
    sum_mass_j[test]+=sum_mass_j[test+1]/10;
    std::cout << sum_mass_j[test] << '\n';
*/


    for(int i=49;i>=0;i--)
    {
        sum_mass_j[i]+=sum_mass_j[i+1]/10;
    }

    std::cout << "/* message */" << '\n';

    for(int i=0;i<mass_j;i++)
    {
        if (i==(mass_j/2)) {
            std::cout << "" << '\n';
        }
        std::cout << sum_mass_j[i] << ' ';
    }

    std::cout << "" << '\n';

    for(int i=0;i<=7;i++)
    {
        if(i==0)
        {
            std::cout << sum_mass_j[i];
        }
        else
        {
            std::cout << sum_mass_j[i]%10;
        }
    }












    return 0;
}
//5537376230
//g++ /home/aswiz/Documents/ProjectEuler/problem13_v0.cpp -o Vlad
