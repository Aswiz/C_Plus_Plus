#include <iostream>

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {
//a < b < c
//a^2 + b^2 = c^2
    int a=0,
        b=0,
        c=0,
        sum=1000;
    bool check=false,
         checkSum=false;

while (checkSum!=true)
{
    //Проверка a<b<c
    while (b<=a)
    {
        b++;
    }
    while ((c<=b)||(c<=a))
    {
        c++;
    }
    //Проверка a<b<c
    for(b=0;b<c;b++)
    {
        for(a=0;a<b;a++)
        {
            if (((a*a)+(b*b))==(c*c)) {
                check=true;
                //std::cout << check << '\n';
                //std::cout << "a = "<< a << "; b = "<< b << "; c = "<< c <<";   Suma = "<<a+b+c<< '\n';
                if((a+b+c)==sum)
                {
                std::cout << "a = "<< a << "; b = "<< b << "; c = "<< c <<";   Suma = "<<a+b+c<< '\n';
                std::cout << "Otvet - " << a*b*c << '\n';
                checkSum=true;
                }
            }
            else
            {
                check=false;
                //std::cout << check << '\n';
            }
        }
    }
    //std::cout << "aaaaaa" << '\n';
}

    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem9_v0.cpp -o Vlad
