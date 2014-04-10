#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
/*Given a string write a program to convert it into lowercase.*/

int converttolower(char* str)
{
	for(int i =0;i<strlen(str);i++)
		if( str[i] >= 65 && str[i] <= 90)
				str[i] += 32;

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
	char line[250];

	while(!file.eof())
	{
		file.getline(line,250);
		if( strlen(line) == 0)
			continue;
		converttolower(line);
		cout<<line<<endl;
	}

	return 0;
}