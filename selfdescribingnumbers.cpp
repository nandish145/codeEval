#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<cmath>


using namespace std;
/*A number is a self-describing number when (assuming digit positions 
are labeled 0 to N-1), the digit in each position is equal to the number of 
times that that digit appears in the number.*/
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
		char *cstr = new char[str.size()+1];
		int *array = new int[str.size()];
		strcpy(cstr,str.c_str());

		unordered_map<int,int> mymap;

		for(int i = 0; i< str.size();i++)
		{
			int digit = cstr[i] - 48;
			array[i] = digit;
			auto it = mymap.find(digit);
			if( it != mymap.end())
				(*it).second +=1;
			else
				mymap.insert(make_pair(digit,1));
		}
		
		bool flag = false;
		for(int i =0;i< str.size();i++)
		{
			auto it = mymap.find(i);
			if( it == mymap.end() && array[i] == 0)
				continue;
			else if( it != mymap.end() && (*it).second == array[i])
				continue;
			else
			{
				flag = true;
				cout<<0<<endl;
				break;
			}
		}
		if(flag)
			continue;

		cout<<1<<endl;
	}	
	file.close();
	return 0;
}