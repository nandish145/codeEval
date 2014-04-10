#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;

void string_reverse(char *start,char* end)
{
	while(start < end)
	{
		char c = *start;
		*start = *end;
		*end = c;
		start++;
		end--;
	}
}

void words_reverse(char *str)
{
	char *start = str;
	int count = 0;

	string_reverse(str,str+strlen(str)-1);
	cout<<str<<endl;
	for(int i = 0; i < strlen(str);i++)
	{
		if( str[i] != ' ')
		{
			if( count == 0)
				 start = str+i;
			count++;
		}
		else
		{
			if(count == 0)
				continue;
			string_reverse(start,str+i-1);
			cout<<str<<endl;
			count = 0;
		}
	}

	if( start != str + strlen(str)-1)
		string_reverse(start,str + strlen(str)-1);

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
	char line[300];

	while(!file.eof())
	{
		file.getline(line,300);
		if(strlen(line) == 0)
			continue;

		//char *nline = new char[strlen(line.c_str())+1];
		//strcpy(nline,line.c_str());
		words_reverse(line);
		cout<<line<<endl;
		//delete nline;
	}
	file.close();
	return 0;
}

