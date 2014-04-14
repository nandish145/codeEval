#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*You are given a number N and a pattern. The pattern consists of lowercase latin letters
and one operation "+" or "-". The challenge is to split the number and evaluate it 
according to this pattern e.g. 
1232 ab+cd -> a:1, b:2, c:3, d:2 -> 12+32 -> 44*/

int split_number(string str)
{
	string number = str.substr(0,str.find(' '));
	string code = str.substr(str.find(' ')+1);

	int plus = code.find('+');
	if( plus != string::npos)
	{
		int left = stoi(number.substr(0,plus));
		int right = stoi(number.substr(plus));

		return left + right;
	}
	
	int minus = code.find('-');
	if( minus != string::npos)
	{
		int left = stoi(number.substr(0,minus));
		int right = stoi(number.substr(minus));

		return left - right;
	}

}
int main(int argc,char* argv[])
{
	if( argc != 2)
	{
		cout<<"File name required as argument"<<endl;
		return -1;
	}

	fstream file;
	file.open(argv[1],ios::in);
	
	


	while(!file.eof())
	{
		string str;
		getline(file,str);
		if(str.length() == 0)
			continue;
		cout<<split_number(str)<<endl;
	}

	file.close();
	return 0;
}