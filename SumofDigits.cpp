#include<iostream>
#include<fstream>

using namespace std;
/*Given a positive integer, find the sum of its constituent digits*/
int finddigitssum(int num)
{
	int sum = 0;

	while(num != 0)
	{
		sum+= num % 10;
		num = num/10;
	}

	return sum;
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
		
		int num = atoi(str.c_str());
		cout<<finddigitssum(num)<<endl;
	}

	return 0;
}