#include<iostream>
#include<fstream>
#include<string>
#include<cstring>


using namespace std;
/*You are given two sorted list of numbers (ascending order).
The lists themselves are comma delimited and the two lists are semicolon delimited.
Print out the intersection of these two sets.*/
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

		int *array_x = new int[str.size()+ 1];
		int *array_y = new int[str.size()+ 1];
		char *tokptr,*cstr_x,*cstr_y;

		cstr_x = new char[str.size()+1];
		cstr_y = new char[str.size()+1];

		string str_x = str.substr(0,str.find(";"));
		
		string str_y = str.substr(str.find(";")+1);
		
		strcpy(cstr_x,str_x.c_str());
		strcpy(cstr_y,str_y.c_str());

		tokptr = strtok(cstr_x,",");
		int i =0;
		while( tokptr != NULL)
		{
			array_x[i] = atoi(tokptr);
			i++;
			tokptr = strtok(NULL,",");
		}
		array_x[i] = '\0';

		i = 0;
		tokptr = strtok(cstr_y,",");
		while( tokptr != NULL)
		{
			array_y[i] = atoi(tokptr);
			i++;
			tokptr = strtok(NULL,",");
		}
		array_y[i] = '\0';

		int j =0,z=0; 
		i =0;
		int *array_z = new int[str.size()+1];
		while(array_y[j] != '\0' && array_x[i] != '\0')
		{
			if( array_x[i] == array_y[j])
			{
				array_z[z] = array_y[j];
				i++;j++;z++;
			}
			else if( array_x[i] > array_y[j])
				j++;
			else
				i++;
		}

		array_z[z] = '\0';

		if(array_z[0] != '\0')
			cout<<array_z[0];
		for( int p = 1; array_z[0] != '\0' && array_z[p] != '\0';p++)
				cout<<","<<array_z[p];
		cout<<endl;

		free(array_x);
		free(array_y);
		free(array_z);
		free(cstr_x);
		free(cstr_y);
	}

	file.close();
	return 0;
}