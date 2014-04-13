#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

/*There is a board (matrix). Every cell of the board contains one integer, which is 0 initially. 

The next operations can be applied to the Query Board: 
SetRow i x: it means that all values in the cells on row "i" have been changed to value "x" after this operation. 
SetCol j x: it means that all values in the cells on column "j" have been changed to value "x" after this operation. 
QueryRow i: it means that you should output the sum of values on row "i". 
QueryCol j: it means that you should output the sum of values on column "j". 

The board's dimensions are 256x256 
"i" and "j" are integers from 0 to 255 
"x" is an integer from 0 to 31 */
int find_operation(string str, vector<vector<short int>> &v, int &sum)
{
	string sRow = "SetRow";
	string sCol = "SetCol";
	string qCol = "QueryCol";
	string qRow = "QueryRow";
	string::size_type sz;

	if(sRow.compare(0,6,str,0,6) == 0)
	{
		str = str.substr(str.find(' ')+1);
		int row = stoi(str,&sz);
		int value = stoi(str.substr(sz+1));

		for(int i = 0; i< 256;i++)
			v[row][i] = value;
	}
	else if(sCol.compare(0,6,str,0,6) == 0)
	{
		str = str.substr(str.find(' ')+1);
		int col = stoi(str,&sz);
		int value = stoi(str.substr(sz+1));

		for(int i = 0; i< 256;i++)
			v[i][col] = value;
	}
	else if(qCol.compare(0,8,str,0,8) == 0)
	{
		str = str.substr(str.find(' ')+1);
		int col = stoi(str);
		sum =0;

		for(int i = 0; i< 256;i++)
			sum += v[i][col];

		return 1;
	}
	else
	{
		str = str.substr(str.find(' ')+1);
		int row = stoi(str);
		sum =0;

		for(int i = 0; i< 256;i++)
			sum += v[row][i];

		return 1;
	}

	return 0;
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
		int sum =0;
		if(find_operation(str,v,sum))
			cout<<sum<<endl;
	}

	file.close();
	return 0;
}