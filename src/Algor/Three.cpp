#include <iostream>
#include <ctime>

#include "../../ProjectEuler/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {

    srand(time(NULL));

    int coins[]={1,2,5,10,20,50,100,200,500},
        sizeCoins=(sizeof(coins)/4)-1,
        total=0;
    bool check=false;

        std::cout << sizeCoins << '\n';

        std::cin >> total;


        while (total>0)
        {
            for(int i=sizeCoins;i>=0;i++)
            {
                while (total>=coins[i])
                {
                    total-=coins[i];
                    std::cout << total << '\n';
                }
            }
        }




    return 0;
}
//
//g++ /home/aswiz/Documents/C++/Algor/Three.cpp -o Vlad
