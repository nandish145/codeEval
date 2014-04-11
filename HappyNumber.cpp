#include<iostream>
#include<fstream>
#include<string>
#include<unordered_set>
#include<cmath>


using namespace std;
/*A happy number is defined by the following process. 
Starting with any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers,
while those that do not end in 1 are unhappy numbers.*/
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
		char last;
		if(str.length() == 0)
			continue;

		unordered_set<int> myset;

		int number = atoi(str.c_str());

		if( number == 1)
		{
			cout<<1<<endl;
			continue;
		}
		if( number == 0)
		{
			cout<<0<<endl;
			continue;
		}

		while(myset.find(number) == myset.end())
		{
			myset.insert(number);

			int new_number=0;
			int rem;

			while(number != 0)
			{
				rem = number % 10;
				number = number /10;
				new_number += pow((double)rem,2); 
			}

			number = new_number;

			if( number == 1)
				break;
		}

		if( number == 1)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}

	file.close();
	return 0;
}