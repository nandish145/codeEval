#include<iostream>
#include<string>
#include<fstream>

using namespace std;
/*swap case of letters*/
void swap_case(string str)
{
	for(int i=0;i< str.length();i++)
	{
		if( str[i] <= 'z' && str[i] >= 'a')
				str[i] -= 32;
		else if ( str[i] <= 'Z' && str[i] >= 'A')
				str[i] += 32;
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
		swap_case(str);
	}

	file.close();
	return 0;
}