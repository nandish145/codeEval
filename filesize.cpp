#include<iostream>
#include<fstream>
#include<string>

using namespace std;
/*Print the size of a file in bytes.*/
int main(int argc,char* argv[])
{
	if( argc != 2)
	{
		cout<<"File name required as argument"<<endl;
		return -1;
	}

	fstream file;
	file.open(argv[1],ios::in);
	file.seekg(0,ios::end);
	cout<<file.tellg()<<endl;
	file.close();
	return 0;
}