#include<iostream>
#include<iomanip>

using namespace std;
/*Print out the grade school multiplication table upto 12*12.*/
int main(int argc,char* argv[])
{
	for(int i = 1; i<=12;i++)
	{
		for(int j =1;j<=12;j++)
		{
			cout<<setw(4)<<(i*j);
		}
		cout<<endl;
	}

	return 0;
}