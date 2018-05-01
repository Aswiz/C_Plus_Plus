#include <iostream>
#include <stdio.h>

using namespace std;

int main(){


	int heightTree=15;
	int weightTree=19;
	char symbol='*';
	char symbol1='.';
	for (int i = 0; i < weightTree; ++i)
	{
		for (int j = 0; j < heightTree; ++j)
		{
			switch ( i )
	  	    {
	         case 0:  
		         if (j==7)
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 1:
		         if ((j>5)&&(j<9))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 2:
		         if ((j>4)&&(j<10))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 3:
		         if ((j>3)&&(j<11))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 4:
		         if ((j>2)&&(j<12))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 5:
		         if ((j>1)&&(j<13))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 6:
		         if ((j>4)&&(j<10))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 7:
		         if ((j>3)&&(j<11))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 8:
		         if ((j>2)&&(j<12))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 9:
		         if ((j>1)&&(j<13))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 10:
		         if ((j>0)&&(j<14))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 11:
		         if ((j>3)&&(j<11))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 12:
		         if ((j>2)&&(j<12))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 13:
		         if ((j>1)&&(j<13))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 14:
		         if ((j>0)&&(j<14))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 15:
		         if ((j>=0)&&(j<15))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 16:
		         if ((j>4)&&(j<10))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 17:
		         if ((j>4)&&(j<10))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;
	         case 18:
		         if ((j>4)&&(j<10))
		         {
		         	cout<<symbol;
		         }
		         else
		         	cout<<symbol1;
	         break;

	     	}
      cout<<symbol1;
		}
		cout<<endl;
	}



	return 0;
}
