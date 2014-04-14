#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*shortest repeating substring*/

int shortest_repeating_substring(string str)
{
	int compare_index;
	int pattern_end = 1;

	for(int j = 1; j< str.length();j++)
	{

		compare_index = j% pattern_end;
		if( str[compare_index] != str[j])
			pattern_end = j+1;

	}

	return str.substr(0,pattern_end).length();
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
		cout<<shortest_repeating_substring(str)<<endl;
		
	}

	file.close();
	return 0;
}