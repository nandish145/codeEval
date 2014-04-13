#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;
/*You will be given a hexadecimal (base 16) number. Convert it into decimal (base 10).*/
int hex_to_dec(char *str)
{
	int dec_number = 0;
	int value;
	int exp = 0;
	
	for(int i =strlen(str) -1; i >=0 ; i--,exp++)
	{		
		if(str[i] <= '9' && str[i] >= '0')
			value = str[i] - 48;
		else if( str[i] <= 'f' && str[i] >= 'a')
			value = str[i] - 'a' + 10;
		else
			return -1;
			
		dec_number += value * pow(16.0,exp);
	}
	
	return dec_number;

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
		char *cstr = new char[str.length()+1];
		strcpy(cstr,str.c_str());
		cout<<hex_to_dec(cstr)<<endl;
	}

	file.close();
	return 0;
}