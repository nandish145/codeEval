#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<unordered_map>
#include<list>

using namespace std;

/*You're building a new social platform and you want to store user's working experience.
You've decided to calculate the total experience in years for each user based on the time
periods entered by users. Using this approach you need to be sure that you're taking into
account overlapping time periods in order to retrieve an actual working experience in 
years. E.g. 
Jan 2010-Dec 2010 
Jan 2010-Dec 2010 
Two jobs with 12 months of experience each, but the actual work experience is 1 year, 
because of overlapping time periods. The challenge is to calculate the actual working 
experience based on the list of time intervals.*/

int convert_month_to_num(string month)
{
	unordered_map<string,int> mymap;

	mymap.insert(make_pair("Jan",1));
	mymap.insert(make_pair("Feb",2));
	mymap.insert(make_pair("Mar",3));
	mymap.insert(make_pair("Apr",4));
	mymap.insert(make_pair("May",5));
	mymap.insert(make_pair("Jun",6));
	mymap.insert(make_pair("Jul",7));
	mymap.insert(make_pair("Aug",8));
	mymap.insert(make_pair("Sep",9));
	mymap.insert(make_pair("Oct",10));
	mymap.insert(make_pair("Nov",11));
	mymap.insert(make_pair("Dec",12));

	return mymap[month];
}

int working_experience(string str)
{
	char *cstr = new char[str.length()+1];
	strcpy(cstr,str.c_str());

	struct interval
	{
		int m1,y1,m2,y2;
	};

	list<struct interval> v;
	char *tokptr;

	tokptr = strtok(cstr,";");

	while( tokptr != NULL)
	{
		string intrvl = string(tokptr);
		if( intrvl[0] == ' ') intrvl = intrvl.substr(1);
		string strtm = intrvl.substr(0,intrvl.find('-'));
		string endm = intrvl.substr(intrvl.find('-')+1);

		int y1 = stoi(strtm.substr(strtm.find(' ')+1));
		int y2 = stoi(endm.substr(strtm.find(' ')+1));

		int m1 =  convert_month_to_num(strtm.substr(0,strtm.find(' ')));
		int m2 =  convert_month_to_num(endm.substr(0,strtm.find(' ')));

		struct interval tmp;
		tmp.m1 = m1, tmp.m2 = m2, tmp.y1 = y1, tmp.y2 = y2;

		bool used = false;
		for( auto it = v.begin(); it!= v.end();it++)
		{
			if( tmp.y2 < it->y1)
			{
				v.insert(it,tmp);
					
				used = true;break;
			}
			else if( tmp.y2 == it->y1)
			{
				if( tmp.m2 < it->m1)
					v.insert(it,tmp);
				else
				{
					it->y1 = tmp.y1,it->m1 = tmp.m1;
				}
				used = true;break;
			}
			else if(tmp.y1 < it->y1 && tmp.y2 <= it->y2)
			{
				it->y1 = tmp.y1;
				it->m1 = tmp.m1;

				if( tmp.y2 == it->y2 && tmp.m2 > it->m2)
					it->m2 = tmp.m2;
				used = true;break;
			}
			else if( tmp.y1 == it->y1 && tmp.y2 <= it->y2)
			{
				if( tmp.m1 < it->m1)
					it->m1 = tmp.m1;
				if( tmp.y2 == it->y2 && tmp.m2 > it->m2)
					it->m2 = tmp.m2;
				used = true;break;
			}
			else if( tmp.y1 > it->y1 && tmp.y2 <= it->y2)
			{
				if( tmp.y2 == it->y2 && tmp.m2 > it->m2)
					it->m2 = tmp.m2;
				used = true;
				break;
			}
			else if(tmp.y1 > it->y1 && tmp.y1 <= it-> y2 && tmp.y2 > it->y2)
			{
				if( tmp.m1 > it->m2)
					continue;

				it->y2 = tmp.y2, it->m2 = tmp.m2;
				used = true;break;
			}
			else if( tmp.y1 == it->y1 && tmp.y2 == it->y2)
			{
				if( tmp.m1 < it->m1) it->m1 = tmp.m1;
				if( tmp.m2 > it->m2) it->m2 = tmp.m2;
				used = true;break;
			}
			else if(tmp.y1 < it->y1 && tmp.y2 > it->y2)
			{
				it->y1 = tmp.y1;
				it->m1 = tmp.m1;
				it->y2 = tmp.y2;
				it->m2 = tmp.m2;
				used = true;break;
			}
			else if(tmp.y1 == it->y1 && tmp.y2 > it->y2)
			{
				it->m1 = (tmp.m1 < it->m1) ? tmp.m1: it->m1;
				it->y2 = tmp.y2;
				it->m2 = tmp.m2;
				used = true;break;
			}
			else if(tmp.y1 < it->y1 && tmp.y2 == it->y2)
			{
				it->y1 = tmp.y1;
				it->m1 = tmp.m1;
				it->m2 = (tmp.m2 > it->m2) ? tmp.m2: it->m2;
				used = true;break;
			}
		}

		if(!used)
			v.push_back(tmp);

		tokptr = strtok(NULL,";");
	}

	int i =0;
	for(auto x = v.begin(); x!= v.end();x++)
	{
		i++; auto y = v.begin();
		for( advance(y,i); y != v.end();)
		{
			if( x->y2 < y->y1)
			{
				y++;
			}
			else if( x-> y2 == y->y1)
			{
				if( x->m2 < y->m1)
					y++;
				else
				{
					x->m2 = y->m2;
					x->y2 = y->y2;
					y = v.erase(y);
				}
			}
			else if( x->y2 > y->y1)
			{
				if( x->y2 > y->y2)
				{
					y = v.erase(y);
				}
				else if( x->y2 == y->y2)
				{
					x->m2 = (x->m2 > y->m2)? x->m2:y->m2;
					y = v.erase(y);
				}
				else
				{
					x->y2 = y->y2;
					x->m2 = y->m2;
					y = v.erase(y);
				}

			}

		}
	}
	

	int months =0;
	for( auto it = v.begin(); it != v.end(); it++)
	{
		if( it->y2 == it->y1)
			months += it->m2 - it->m1+1;
		else
		{
			months += (it->y2 - it->y1) * 12;
			if( it->m1 < it->m2)
				months += ( it->m2 - it->m1+1);
			else if( it-> m1 > it-> m2)
				months -= ( it->m1 - it->m2-1);
		}
	}

	return months/12;
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
		cout<<working_experience(str)<<endl;
	}

	file.close();
	return 0;
}