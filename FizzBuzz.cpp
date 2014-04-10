#include<fstream>
#include<iostream>
#include<string>

using namespace std;

void fizzbuzz( int a, int b, int N)
{
	for(int i = 1; i <= N; i++)
	{
		if( (i%a == 0) && ( i%b ==0 ))
			cout<<"FB ";
		else if( (i%a == 0))
			cout<<"F ";
		else if( (i%b == 0))
			cout<<"B ";
		else
			cout<<i<<" ";
	}

	cout<<endl;
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
		int space_index = str.find(' ');
		int a = atoi(str.substr(0,space_index).c_str());
		str = str.substr(space_index+1);
		space_index = str.find(' ');
		int b = atoi(str.substr(0,space_index).c_str());
		str = str.substr(space_index+1);
		
		int N = atoi(str.c_str());
		

		fizzbuzz(a,b,N);
	}

	return 0;
}

