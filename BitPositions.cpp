#include<iostream>
#include<fstream>

using namespace std;
/*Given a number n and two integers p1,p2 determine if the bits in 
position p1 and p2 are the same or not. Positions p1 and p2 and 1 based.*/
bool checkbitpositions(int number,int first,int second)
{
	int first_help = 1;
	int second_help = 1;

	first_help <<= (first - 1 );
	second_help <<= (second - 1 );

	first_help &= number;
	second_help &= number;
	bool first_sign = first_help > 0;
	bool second_sign = second_help > 0;

	return first_sign == second_sign;
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
		int number = atoi(str.substr(0,space_index).c_str());
		str = str.substr(space_index+1);
		space_index = str.find(',');
		int first = atoi(str.substr(0,space_index).c_str());
		str = str.substr(space_index+1);
		int second = atoi(str.c_str());
		if(checkbitpositions(number,first,second))
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}

	return 0;
}