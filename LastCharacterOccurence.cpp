#include<iostream>
#include<fstream>
#include<string>
#include<cstring>


using namespace std;
/*You are given a string 'S' and a character 't'. 
Print out the position of the rightmost occurrence of 't' (case matters) in 'S' 
or -1 if there is none. The position to be printed out is zero based.*/
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
		char last;
		if(str.length() == 0)
			continue;
		string search_string = str.substr(0,str.find(","));
		char ch = str.c_str()[str.size() -1];
		int pos = search_string.find_last_of(ch);
		cout<<pos<<endl;
	}

	file.close();
	return 0;
}