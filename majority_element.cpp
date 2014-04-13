#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
using namespace std;

/*The major element in a sequence with the length of L is the element which appears in a 
sequence more than L/2 times. The challenge is to find that element in a sequence.*/

int majority_element(string str,int &elem)
{
	char *cstr = new char[str.length() +1];
	strcpy(cstr,str.c_str());

	char *tokptr;
	
	vector<int> v;

	tokptr = strtok(cstr,",");
	while(tokptr!= NULL)
	{
		v.push_back(atoi(tokptr));
		tokptr = strtok(NULL,",");
	}

	int count = 1;
	int majority_element = v[0];
	for( auto it = v.begin()+1;it != v.end();it++)
	{
		if( *it == majority_element)
			count++;
		else
			count--;
		if(count == 0)
		{
			majority_element = *it;
			count = 1;
		}
	}
	count = 0;
	for( auto it = v.begin(); it!= v.end();it++)
		if( *it == majority_element)
			count++;

	if(count > v.size()/2)
	{
		elem = majority_element;
		return 0;
	}
	return -1;
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
		
		int elem;
		
		if (majority_element(str,elem) == 0)
			cout<<elem<<endl;
		else
			cout<<"None"<<endl;
	}

	file.close();
	return 0;
}