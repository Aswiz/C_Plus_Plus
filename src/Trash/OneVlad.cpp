#include <iostream>
using namespace std;

int main(){
	int i=1;
	int j=2;

	int k=0;
//	long long x=0;
	int sum=0;

	while(j<=4000000)
	{
		if((j%2)==0)
		{
			sum+=j;
		}
		k=j;
		j+=i;
		i=k;
		//cout<<j<<" ";
	}
	cout<<"Summa ruwna: "<<sum;





	//system("pause");
	return 0;
}
