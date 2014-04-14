#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

/*CHALLENGE DESCRIPTION:

You are given a list of numbers which is supplemented with positions that have to be
swapped.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. 
Input example is the following

1 2 3 4 5 6 7 8 9 : 0-8
1 2 3 4 5 6 7 8 9 10 : 0-1, 1-3
As you can see a colon separates numbers with positions. 
Positions start with 0. 
You have to process positions left to right. In the example above (2nd line) first you 
process 0-1, then 1-3.*/
void swap_c(int *cstr,int a, int b)
{
	for(int i = a,j=b; i<=b,j>=a,i<j;i++,j--)
	{
		int c = cstr[i];
		cstr[i] = cstr[j];
		cstr[j] = c;
	}
}


void swap_numbers(string str)
{
	string num_list = str.substr(0,str.find(':'));
	int *new_array = new int[num_list.length()+1];
	stringstream ss(num_list);
	string tmp;
	int k =0;
	while(ss >> tmp)
		new_array[k++] = atoi(tmp.c_str());

	string swap_indexes = str.substr(str.find(':')+1);
	replace(swap_indexes.begin(),swap_indexes.end(),'-',' ');
	replace(swap_indexes.begin(),swap_indexes.end(),',',' ');
	stringstream ns(swap_indexes);
	string op1,op2;
	while(ns >> op1)
	{
		ns>>op2;
		int a = stoi(op1);
		int b = stoi(op2);
		swap_c(new_array,a,b);
	}

	for(int i =0;i <k;i++)
		cout<<new_array[i]<<" ";
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
		swap_numbers(str);
		
	}

	file.close();
	return 0;
}