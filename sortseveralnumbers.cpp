#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;
/*Write a program which sorts numbers.*/
void sort_nums(string str)
{
	vector<double> v;

	char *cstr = new char[str.length()+1];
	strcpy(cstr,str.c_str());
	char *tokptr;

	tokptr = strtok(cstr," ");

	while(tokptr != NULL)
	{
		double tmp = stod(string(tokptr));
		v.push_back(tmp);
		tokptr = strtok(NULL," ");
	}
	cout<<endl;
	sort(v.begin(),v.end());

	for( auto it = v.begin();it != v.end();it++)
		cout<<fixed<<setprecision(3)<<*it<<" ";
	cout<<endl;

	return;
}

int main(int argc,char* argv[])
{
	if( argc != 2)
	{
		cout<<"File name required as argument"<<endl;
		return -1;
	}

	vector<vector<short int>> v;

	for(int i =0;i< 256;i++)
		v.push_back(vector<short int>());
	for(int i =0;i< 256;i++)
		for(int j =0;j<256;j++)
			v[i].push_back(0);

	fstream file;
	file.open(argv[1],ios::in);
	
	
	while(!file.eof())
	{
		string str;
		getline(file,str);
		if(str.length() == 0)
			continue;
		sort_nums(str);
	}

	file.close();
	return 0;
}