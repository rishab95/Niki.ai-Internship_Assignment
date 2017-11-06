#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

using namespace std;


// Function that multiplies 2 matrices Fibonacci and Matrix of size 2*2, and puts the multiplication result back to Fibonacci[][]
void multiply(long long int Fibonacci[2][2], long long int Matrix[2][2])
{
	long long int f00 =  ((Fibonacci[0][0]*Matrix[0][0]) % MOD + (Fibonacci[0][1]*Matrix[1][0]) % MOD) % MOD;
	long long int f01 =  ((Fibonacci[0][0]*Matrix[0][1]) % MOD + (Fibonacci[0][1]*Matrix[1][1]) % MOD) % MOD;
	long long int f10 =  ((Fibonacci[1][0]*Matrix[0][0]) % MOD + (Fibonacci[1][1]*Matrix[1][0]) % MOD) % MOD;
	long long int f11 =  ((Fibonacci[1][0]*Matrix[0][1]) % MOD + (Fibonacci[1][1]*Matrix[1][1]) % MOD) % MOD;

	Fibonacci[0][0] = f00;
	Fibonacci[0][1] = f01;
	Fibonacci[1][0] = f10;
	Fibonacci[1][1] = f11;
}

//  Helper function that calculates Fibonacci[][] raise to the power n and puts the result in Fibonacci[][]
void power(long long int Fibonacci[2][2], long long int n)
{
	if( n == 0 || n == 1)
		return;
	long long int Matrix[2][2] = {{1,1},{1,0}};

	power(Fibonacci, n/2);
	multiply(Fibonacci, Fibonacci);

	if (n%2 != 0)
 		multiply(Fibonacci, Matrix);
}

// function that returns the desired output
long long int no_two_zeros_adjacent(long long int n)
{
	long long int Fibonacci[2][2] = {{1,1},{1,0}};
	if (n == 0)
		return 0;
	if (n == 1)
		return 2;
	if (n == 2)
		return 3;
	power(Fibonacci, n-2);

	return (Fibonacci[0][0]*3+Fibonacci[0][1]*2)%MOD;
}


int main()
{
	long long int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		long long int input = (pow(10,14)+110);
		cin >> input;
		cout << no_two_zeros_adjacent(input) << endl;
	}
	return 0;
}
