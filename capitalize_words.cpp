#include<iostream>
#include<string>
#include<fstream>

using namespace std;
/*Capitalize words in a sentence*/
void capitalize_word(string str)
{
	if( str[0] != ' ')
	{
		if( str[0] <= 'z' && str[0] >= 'a')
				str[0] -= 32;
	}
	
	for(int i=1;i< str.length();i++)
	{
		if( str[i-1] == ' ' && str[i] != ' ')
		{
			if( str[i] <= 'z' && str[i] >= 'a')
				str[i] -= 32;
		}
	}

	cout<<str<<endl;
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
		capitalize_word(str);
	}

	file.close();
	return 0;
}