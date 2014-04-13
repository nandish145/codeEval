#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;
/*Credits: This problem appeared in the Facebook Hacker Cup 2013 Hackathon. 

When John was a little kid he didn't have much to do. There was no internet,
no Facebook, and no programs to hack on. So he did the only thing he could... 
he evaluated the beauty of strings in a quest to discover the most beautiful string in the
world. 

Given a string s, little Johnny defined the beauty of the string as the sum of the beauty
of the letters in it. The beauty of each letter is an integer between 1 and 26, inclusive,
and no two letters have the same beauty. Johnny doesn't care about whether letters are 
uppercase or lowercase, so that doesn't affect the beauty of a letter. (Uppercase 'F' is 
exactly as beautiful as lowercase 'f', for example.) 

You're a student writing a report on the youth of this famous hacker. You found the string
that Johnny considered most beautiful. What is the maximum possible beauty of this string?
*/
struct pr
{
	char ch;
	int count;
};

bool compare(struct pr a,struct pr b)
{
	return a.count < b.count;
}

int string_value(char *str)
{
	unordered_map<char,int> mymap;

	for(int i = 0; i< strlen(str);i++)
	{
		if( str[i] <= 'Z' && str[i] >= 'A')
				str[i] += 32;

		if( str[i] <= 'z' && str[i] >= 'a')
		{
			auto it = mymap.find(str[i]);
			if(  it == mymap.end())
				mymap.insert(make_pair(str[i],1));
			else
				(*it).second++;
		}

	}

	vector<struct pr> myvector;

	for( auto it = mymap.begin(); it != mymap.end(); it++)
	{
		struct pr temp;
		temp.ch = it->first;
		temp.count = it->second;
		myvector.push_back(temp);
	}

	if( myvector.empty())
		return -1;

	int value = 0;
	int multiplier = 26;

	make_heap(myvector.begin(),myvector.end(),&compare);


	while(!myvector.empty())
	{	
		pop_heap(myvector.begin(),myvector.end(),&compare);
		value += (myvector.back().count * multiplier);
		myvector.pop_back();
		multiplier--;
	}

	return value;
}

int find_beautiful_string_value(string str)
{
	char* cstr =  new char[str.length()+1];
	strcpy(cstr,str.c_str());

	return string_value(cstr);
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
		cout<<find_beautiful_string_value(str)<<endl;
	}

	file.close();
	return 0;
}