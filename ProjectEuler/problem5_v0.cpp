#include <iostream>

#include "ami.h"
using namespace std;

int main(int argc, char const *argv[]) {

    bool bool_DWAR=false; //divided without any remainder 1 to size

    int x=1,
        trueSize=0,
        size=20;

    while (bool_DWAR!=true)
    {
        trueSize=0;
        for(int i=1;i<=size;i++)
        {
            if(DWAR(x,i)==1)
            {
                trueSize++;
            }
        }
        if(trueSize==size)
        {
            bool_DWAR=true;
            cout<<x<<endl;
        }
        else
        {
            x++;
        }
    }

    return 0;
}
//g++ /home/aswiz/Documents/ProjectEuler/problem5_v0.cpp -o Vlad
