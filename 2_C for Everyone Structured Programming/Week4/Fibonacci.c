/*
	Iterative vs Recursive fibonacci code
	F(0) = 0, F(1) = 1
	F(n) = F(n-1) + F(n-2)

	sept. 04, 2020
*/

#include <stdio.h>

long int Fibonacci(int n)
{
	long int f2 = 0, f1 = 1, f_old;
	for(int i = 0; i< n; i++)
	{
		f_old = f2;
		f2 = f2 + f1;
		f1 = f_old;
	}
	return f2;
}

long int Recursive_Fibonacci(int n)
{
	if(n<=1)
	{
		return n;
	}
	else
	{
		return( Recursive_Fibonacci(n-1) + Recursive_Fibonacci(n-2) );
	}
}

int main()
{
	int term = 5;
	printf("Iterative fibonacci 5th term is: %ld || Recursive is: %ld \n",Fibonacci(term), Recursive_Fibonacci(term));
	return 0;
}