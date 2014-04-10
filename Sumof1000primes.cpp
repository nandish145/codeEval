#include<iostream>
#include<cstdlib>

using namespace std;
/*Write a program to determine the sum of the first 1000 prime numbers.*/
int main(int argc,char *argv[])
{
	int prime_count = 1;
	int max_primes = 1000;
	int current_number = 3;
	int primes[1000];
	int prime_sum = 2;

	//First prime
	primes[0] = 2;

	
	
	for(current_number; current_number != -1 && prime_count < max_primes; current_number++)
	{
		float sq = sqrt(float(current_number));
		bool prime_flag = true;
		for(int i = 2; i<= int(sq);i++)
		{
			if( (current_number % i) == 0)
			{
				prime_flag = false;
				break;
			}
		}
		if( prime_flag)
		{
			primes[prime_count] = current_number;
			prime_sum += current_number;
			prime_count++;
		}
	}

	cout<<prime_sum<<endl;

	return 0;
}
	
			