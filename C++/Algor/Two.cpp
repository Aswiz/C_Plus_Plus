#include <iostream>
#include <ctime>

#include "../../ProjectEuler/ami.h"

using namespace std;

int main(int argc, char const *argv[]) {

    srand(time(NULL));

    int quantityCoins=25,
        sizeEagle=0,
        n=0,
        x[quantityCoins];

    bool coins[quantityCoins];

    std::cin >> n;
    std::cout << "" << '\n';

    for(int i=0;i<quantityCoins;i++)
    {
        x[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        sizeEagle=0;
        for(int j=0;j<quantityCoins;j++)
        {
            coins[j]=rand()%2;
            if (coins[j]==true)
                sizeEagle++;
        }
        x[sizeEagle]++;
    }

    for(int i=0;i<quantityCoins;i++)
    {
        std::cout << x[i] << '\n';
    }

    std::cout << "" << '\n';
    return 0;
}
//
//g++ /home/aswiz/Documents/C++/Algor/Two.cpp -o Vlad
