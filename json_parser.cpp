#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<cmath>

using namespace std;
/*CHALLENGE DESCRIPTION:

You have JSON string which describes a menu. Calculate the SUM of IDs of all "items"
in the case a "label" exists for an item.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input example is 
the following

{"menu": {"header": "menu", "items": [{"id": 27}, {"id": 0, "label": "Label 0"}, null,
{"id": 93}, {"id": 85}, {"id": 54}, null, {"id": 46, "label": "Label 46"}]}}*/

int json_parser(string str)
{
	str = str.substr(str.find('[')+1,str.find(']'));

	int left = str.find_first_of('{'),right = str.find_first_of('}');
	int id=0;
	while(left != string::npos && right != string::npos)
	{
		int label_index = str.find("label");
		if( label_index > left && label_index < right)
		{
			id += stoi(str.substr(str.find_first_of(':')+2,str.find_first_of(',')));
			str = str.substr(right+2);
		}
		else
		{
			str = str.substr(right+2);

		}
		left = str.find_first_of('{');
		right = str.find_first_of('}');
	}

	return id;
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
		cout<<json_parser(str)<<endl;
	}

	file.close();
	return 0;
}