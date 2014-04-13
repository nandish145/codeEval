#include<iostream>
#include<string>
#include<fstream>

using namespace std;
/*There is a game where each player picks a number from 1 to 9, writes it on a paper and
gives to a guide. A player wins if his number is the lowest unique.
We may have 10-20 players in our game.*/
int lowest_unique_number(string str)
{
	int sz = str.length() - str.length()/2;
	int *array = new int[sz];

	int j =0;
	for(int i =0;i<str.length();i++)
	{
		if( str[i] <= '9' && str[i] >= '1')
		{	array[j] = str[i] - 48;
			j++;
		}
	}

	int *count_array = new int[10];

	for(int i =0;i<10;i++)
		count_array[i] =0;

	for(int i =0;i < sz;i++)
		count_array[array[i]]++;

	

	for(int i =1;i<sz;i++)
		if( count_array[i] == 1)
		{	
			delete count_array;
			for( int j =0; j < sz;j++)
				if( array[j] == i)
				{
					delete array;
					return j+1;
				}
		}
	delete array;
	delete count_array;
	return 0;
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
		cout<<lowest_unique_number(str)<<endl;
	}

	file.close();
	return 0;
}