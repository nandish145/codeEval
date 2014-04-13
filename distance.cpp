#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<cmath>

using namespace std;
/*You have coordinates of 2 points and need to find the distance between them.*/
int distance(string str)
{
	char *cstr = new char[str.length()+1];
	strcpy(cstr,str.c_str());

	char *tokptr = strtok(cstr,"(, )");
	int x1 = atoi(tokptr);
	
	tokptr = strtok(NULL,"(, )");
	int y1 = atoi(tokptr);

	tokptr = strtok(NULL,"(, )");
	int x2 = atoi(tokptr);

	tokptr = strtok(NULL,"(, )");
	int y2 = atoi(tokptr);

	return sqrt(pow(double(x1-x2),2)+pow(double(y1-y2),2));
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
		cout<<distance(str)<<endl;
	}

	file.close();
	return 0;
}