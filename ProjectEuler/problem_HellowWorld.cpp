#include <iostream>

#include "ami.h"


using namespace std;

int main(int argc, char const *argv[]) {

    int n=10000,
    sizeCollatzSequence=0,
    digits_CollatzSequence[n],
    max_sizeCollatzSequence=0,
    digit_max_sizeCollatzSequence=0,
    k=0;

    bool check=true;

    std::cin >> n;
    std::cout << "" << '\n';





    for(int i=n;i>1;i--)
    {
        sizeCollatzSequence=0;
        n=i;
        std::cout << n<<endl;
        while (n>1) {
            check=true;

            for(int j=0;j<k;j++)
            {
                if (digits_CollatzSequence[j]==n)
                {
                    check=false;
                    break;
                }
            }
            if (check==true)
            {
                digits_CollatzSequence[k]=n;
                //std::cout << digits_CollatzSequence[k] << ' ';
                k++;
            }
            else break;


            if ((n%2)==0)
            {
                n/=2;
            }
            else
            {
                n*=3;
                n+=1;
            }
            sizeCollatzSequence++;
            std::cout << n << ' ';
        }
        std::cout << endl << "sizeCollatzSequence = " << sizeCollatzSequence << '\n';
        if (max_sizeCollatzSequence<sizeCollatzSequence)
        {
            max_sizeCollatzSequence=sizeCollatzSequence;
            digit_max_sizeCollatzSequence=i;
        }
    }

    std::cout << endl << "Number - " << digit_max_sizeCollatzSequence << '\n';
    std::cout << "max_sizeCollatzSequence = " << max_sizeCollatzSequence << '\n';

    std::cout << k << '\n';
    for(int i=0;i<k;i++)
    {
        std::cout << digits_CollatzSequence[i] << ' ';
    }



    //test
    /*
    while (n>1) {
        if ((n%2)==0)
        {
            n/=2;
        }
        else
        {
            n*=3;
            n+=1;
        }
        sizeCollatzSequence++;
        std::cout << n << ' ';
        if (n==10) {
            break;
        }
    }
    */
    //test




















    return 0;
}
//
//g++ /home/aswiz/Documents/ProjectEuler/problem14_v0.cpp -o Vlad
