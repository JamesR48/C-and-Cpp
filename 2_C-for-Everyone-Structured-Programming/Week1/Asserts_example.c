/*
	Asserts example

	Sept. 12, 2020
*/

#define NDEBUG //must be BEFORE assert.h
//it turns off the asserts when compiled with the NDEBUG flag
//We can also use NDBUG right in the compiler like "gcc -NDEBUG file.c"
#include <stdio.h>
#include <assert.h>
#include <ctype.h>


int main()
{
	//assert(0); //0 means false, so assert will fail, the printf() will not work, the program just fails
	//The error will tell the exact line were the assert failed and aborted
	//With the NDEBUG falg, the printf() works even if the assert fails
	//So you can write the code with asserts to test it works properly, and then turn them off with the NDEBUG flag
	//printf("Program runs! \n");

	/* ANOTHER EXAMPLE */
	double x,y;
	while(1) //infinite loop
	{
		printf("Read in 2 floats: \n");
		scanf("%lf %lf", &x, &y);
		assert(y != 0); //since we don't want to divide by 0
		printf("when divided x/y = %lf \n", x/y);
	}

	return 0;
}