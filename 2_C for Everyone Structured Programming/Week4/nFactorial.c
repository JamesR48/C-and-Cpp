/*
	Recursive vs iterative factorial

	sept.04, 2020
*/

#include <stdio.h>

//long int allows to work up to 20 factorial
//after 20, you get "integer overflow", getting incorrect results since long ints are 64 bits (8 bytes) on most machines
long int factorial(int n) 
{
	long f = 1;
	for(int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

long int recursive_factorial(int n)
{
	if(n==1)
	{
		retun 1;
	}
	else
	{
		return (recursive_factorial(n-1) * n);		
	}
}

int main()
{
	int howMany = 4;
	printf("Iterative 4!: %ld || Recursive 4!: %ld \n", factorial(howMany), recursive_factorial(howMany));
	return 0;
}