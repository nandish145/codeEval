#include<iostream>
#include<string>
#include<fstream>
#include<cstring>

using namespace std;
/*You have a set of rows with names of famous writers encoded inside.
Each row is divided into 2 parts by pipe char (|). The first part has a writer's name.

The second part is a "key" to generate a name.

Your goal is to go through each number in the key
(numbers are separated by space) left-to-right. Each number represents a position in the 
1st part of a row. This way you collect a writer's name which you have to output.*/

void find_writer(string str)
{
	string code = str.substr(0,str.find('|'));
	string key = str.substr(str.find('|')+1);

	string result;

	char *tokptr;
	char *cstr = new char[key.length()+1];
	strcpy(cstr,key.c_str());

	tokptr = strtok(cstr," ");

	while(tokptr != NULL)
	{
		int index = atoi(tokptr);
		result += string(1,code.c_str()[index-1]);
		tokptr = strtok(NULL," ");
	}
	cout<<result<<endl;
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
		find_writer(str);
	}

	file.close();
	return 0;
}