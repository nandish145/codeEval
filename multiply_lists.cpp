#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

/*You have 2 lists of positive integers. Write a program which multiplies corresponding
elements in these lists.*/

void multiply_numbers(string str)
{
	string left = str.substr(0,str.find('|'));
	string right = str.substr(str.find('|')+1);

	stringstream sl(left);
	stringstream sr(right);

	string op1,op2;

	while( sl >> op1 && sr >> op2)
	{
		int temp = stoi(op1)*stoi(op2);
		cout<<temp<<" ";
	}
	cout<<endl;
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
		multiply_numbers(str);
		
	}

	file.close();
	return 0;
}