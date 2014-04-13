#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;
/*An Armstrong number is an n-digit number that is equal to the sum of the n'th powers
of its digits. Determine if the input numbers are Armstrong numbers*/
bool arm_yes_or_no(char *str)
{
	int value = atoi(str);
	int exp = strlen(str);
	int arm_value = 0;
	int number = value;
	int rem;

	while(number != 0)
	{
		rem = number % 10;
		number = number/10;
		arm_value += pow(float(rem),exp);
	}
	
	
	return value == arm_value;

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
		cout<<(arm_yes_or_no(cstr) ? "True":"False")<<endl;
	}

	file.close();
	return 0;
}