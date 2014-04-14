#include<iostream>
#include<string>
#include<fstream>
#include<sstream>


using namespace std;

/*Assume that someone dictates you a sequence of numbers and you need to write it down.
For brevity, he dictates it as follows: first says the number of consecutive identical 
numbers and then says the number itself. E.g. The sequence 1 1 3 3 3 2 2 2 2 14 14 14 11 
11 11 2 will be dictated as "Two times one, three times three, four times two, three times 
fourteen, three times eleven, one time two", so you will write down the sequence 2 1 3 3 4 
2 3 14 3 11 1 2. The challenge is to write the program which compresses the given sequence 
using this approach*/

void compress_digits(string str)
{
	stringstream ss(str);

	string res;
	ss >> res;
	int count = 1;
	string last = res;
	bool flag = true;

	while(ss >> res)
	{
		if( res.compare(last) == 0)
			count++;
		else
		{
			if(flag)
			{
				cout<<count<<" "<<last;
				flag = false;
			}
			else
				cout<<" "<<count<<" "<<last;

			count = 1;
			last = res;
		}
	}

	if(res.size() != 0)
	{
		if(flag)
			cout<<count<<" "<<last;
		else
			cout<<" "<<count<<" "<<last;
	}
	cout<<endl;
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
		compress_digits(str);
	}

	file.close();
	return 0;
}