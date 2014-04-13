#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*Many persons are familiar with the Roman numerals for relatively small numbers.
The symbols I (capital i), V, X, L, C, D, and M represent the decimal values 1, 5, 10, 50,
100, 500 and 1000 respectively. To represent other values, these symbols, and multiples 
where necessary, are concatenated, with the smaller-valued symbols written further to the 
right. For example, the number 3 is represented as III, and the value 73 is represented as 
LXXIII. The exceptions to this rule occur for numbers having units values of 4 or 9, and 
for tens values of 40 or 90. For these cases, the Roman numeral representations are IV (4),
IX (9), XL (40), and XC (90). So the Roman numeral representations for 24, 39, 44, 49, and 
94 are XXIV, XXXIX, XLIV, XLIX, and XCIV, respectively. 

Write a program to convert a cardinal number to a Roman numeral.*/
int main(int argc,char* argv[])
{
	if( argc != 2)
	{
		cout<<"File name required as argument"<<endl;
		return -1;
	}

	fstream file;
	file.open(argv[1],ios::in);
	
	string r_str[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int i_str[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1};


	while(!file.eof())
	{
		string str;
		getline(file,str);
		if(str.length() == 0)
			continue;
		
		string result;
		int value = stoi(str);

		for(int i=0;i<13;i++)
		{
			while( value >= i_str[i])
			{
				value -= i_str[i];
				result += r_str[i];
			}
		}

		cout<<result<<endl;
	}

	file.close();
	return 0;
}