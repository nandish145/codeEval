#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;
/*The Fibonacci series is defined as: F(0) = 0; F(1) = 1; F(n) = F(n-1) + F(n-2) when n>1. Given a positive integer 'n', print out the F(n).*/

int nthfib(int num)
{
	if( num == 0)
		return 0;
	if( num == 1)
		return 1;

	int res;
	int a = 0;
	int b = 1;

	for(int i = 2; i<= num;i++)
	{
		res = b + a;
		a = b;
		b = res;
	}

	return res;
}

int main(int argc,char *argv[])
{
	if( argc != 2)
	{
		cout<<"File name required as argument"<<endl;
		return -1;
	}

	fstream file;
	file.open(argv[1],ios::in);
	char line[25];

	while(!file.eof())
	{
		file.getline(line,25);
		if( strlen(line) == 0)
			continue;
		
		int num = atoi(line);
		cout<<nthfib(num)<<endl;
	}

	return 0;
}