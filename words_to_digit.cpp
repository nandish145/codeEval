#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<map>
using namespace std;

/*Having a string representation of a set of numbers you need to print this numbers.

All numbers are separated by semicolon. There are up to 20 numbers in one line.
The numbers are "zero" to "nine"*/

int word_to_digit(string str,map<string,int> &mymap)
{
	char *cstr = new char[str.length()+1];
	strcpy(cstr,str.c_str());

	char* tokptr;

	tokptr = strtok(cstr,";");

	while( tokptr != NULL)
	{
		cout<<mymap[string(tokptr)];
		tokptr = strtok(NULL,";");
	}

	cout<<endl;


	return 0;
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
	
	map<string,int> mymap;
	mymap.insert(make_pair(string("zero"),0));
	mymap.insert(make_pair(string("one"),1));
	mymap.insert(make_pair(string("two"),2));
	mymap.insert(make_pair(string("three"),3));
	mymap.insert(make_pair(string("four"),4));
	mymap.insert(make_pair(string("five"),5));
	mymap.insert(make_pair(string("six"),6));
	mymap.insert(make_pair(string("seven"),7));
	mymap.insert(make_pair(string("eight"),8));
	mymap.insert(make_pair(string("nine"),9));
	
	while(!file.eof())
	{
		string str;
		getline(file,str);
		if(str.length() == 0)
			continue;
		word_to_digit(str,mymap);
	}

	file.close();
	return 0;
}