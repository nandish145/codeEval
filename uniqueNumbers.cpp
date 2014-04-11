#include<iostream>
#include<fstream>
#include<string>
#include<cstring>


using namespace std;
/*You are given a sorted list of numbers with duplicates. 
Print out the sorted list with duplicates removed.*/
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

		int *array = new int[str.size()+ 1];
		char *tokptr,*cstr;
		cstr = new char[str.size()+1];
		strcpy(cstr,str.c_str());
		tokptr = strtok(cstr,",");
		int i =0;
		while( tokptr != NULL)
		{
			array[i] = atoi(tokptr);
			i++;
			tokptr = strtok(NULL,",");
		}
		array[i] = '\0';
		cout<<array[0];

		for( int j = 1; array[j] != '\0';j++)
			if( array[j] != array[j-1])
				cout<<","<<array[j];

		cout<<endl;
		free(array);
		free(cstr);
	}

	file.close();
	return 0;
}