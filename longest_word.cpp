#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

/*In this challenge you need to find the longest word in a sentence. If the sentence has 
more than one word of the same length you should pick the first one.*/

string longest_word(string str)
{
	char *cstr = new char[str.length() +1];
	strcpy(cstr,str.c_str());

	char *tokptr;
	string res_string;
	
	tokptr = strtok(cstr," ");
	while(tokptr!= NULL)
	{
		if( string(tokptr).length() > res_string.length())
			res_string = string(tokptr);
		tokptr = strtok(NULL," ");
	}
	return res_string;
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
		
		cout<<longest_word(str)<<endl;
	}

	file.close();
	return 0;
}