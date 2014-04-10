#include<iostream>
#include<fstream>

using namespace std;
/*Given numbers x and n, where n is a power of 2, print out the smallest multiple of n which is greater than or equal to x. Do not use division or modulo operator.*/
int nextlargemultiple(int x,int n)
{
	int next = n;

	while( next < x)
		next <<=1;

	while(next > x)
		next -= n;

	if( next == x)
		return next;

	return next+n;
}

int main(int argc, char* argv[])
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
		string str = string(line);
		if( str.length() == 0)
			continue;
		int space_index = str.find(',');
		int x = atoi(str.substr(0,space_index).c_str());
		str = str.substr(space_index+1);
		int n = atoi(str.c_str());
		cout<<nextlargemultiple(x,n)<<endl;
	}

	return 0;
}