#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

/*You have a string of words and digits divided by comma. 
Write a program which separates words with digits. You shouldn't change the order
elements.*/

void mixed_content(string str)
{
	//replace(str.begin(),str.end(),',',' ');

	char *tokptr;
	char *cstr = new char[str.length()+1];
	strcpy(cstr,str.c_str());


	//stringstream ss(str);
	string res;
	vector<string> vs;
	vector<int> vi;

	tokptr = strtok(cstr,",");

	while(tokptr != NULL)
	{
		string res = string(tokptr);

		bool str_flag= false;
		for(int i = 0;i<res.length();i++)
			if( (res[i] >= 65 && res[i] <= 92) || (res[i] >= 97 && res[i] <= 122))
				str_flag = true;

		if(str_flag)
			vs.push_back(res);
		else
			vi.push_back(stoi(res));

		tokptr = strtok(NULL,",");
	}
	

	/*while( ss >> res)
	{
		if( res.c_str()[0] >= 48 && res.c_str()[0] <= 57)
			vi.push_back(stoi(res));
		else
			vs.push_back(res);
	}*/

	bool flag = false;
	if( vs.size() != 0)
	{
		cout<<vs[0];
		flag = true;
	}

	for( int i =1; i< vs.size();i++)
		cout<<","<<vs[i];

	if(flag && vi.size() != 0)
		cout<<"|";

	if( vi.size() != 0)
	{
		cout<<vi[0];
	}

	for( int i =1; i< vi.size();i++)
		cout<<","<<vi[i];

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
		mixed_content(str);
	}

	file.close();
	return 0;
}