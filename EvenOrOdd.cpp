#include<iostream>
#include<fstream>

using namespace std;
/*Write a program which checks input numbers and determines whether a number is even or not.*/
int is_even(int number)
{
	if( number % 2 == 0)
		return 1;
	else
		return 0;
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
		int number = atoi(line);
		if(is_even(number))
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
	file.close();
	return 0;
}
