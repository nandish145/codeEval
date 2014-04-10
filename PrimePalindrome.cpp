#include<iostream>
#include<cmath>

using namespace std;

bool check_palindrome(int index)
{
	char str[5];
	sprintf(str,"%d",index);

	char *start,*end;
	start = str;
	end = str;

	while(*end)
		end++;
	end--;

	while(start < end)
	{
		if(*start == *end)
		{
			start++;
			end--;
		}
		else
			return false;
	}

	return true;
}


int main(int argc,char *argv[])
{
	int max = 1000;
	bool prime_array[1000];

	for(int i =2;i<1000;i++)
		prime_array[i] = true;

	prime_array[0] = prime_array[1] = false;

	float sq = sqrt(float(max));
	for(int i = 2; i<= sq ; i++)
	{
		for(int j = 2; j < 1000;j++)
		{
			if( j == i)
				continue;
			else if( j%i == 0)
				prime_array[j] = false;
		}
	}

	for( int i = 999; i>=2;i--)
	{
		if( prime_array[i] && check_palindrome(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}

	return 0;
}