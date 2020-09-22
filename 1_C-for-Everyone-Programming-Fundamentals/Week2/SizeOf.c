/*
	Fundamental types and sizeof
	
	Sept. 02, 2020
	James M. Romero Q.
*/

#include <stdio.h>

int main()
{
	/* In C certain things could be system dependent since C attempts 
	  to be efficient in relation to the underlying computer. 
	  So it's not attempting to have universally the same semantics because
	  some computers have very big word sizes and some computers that small
	  words size, and C wants to run efficiently on a computer that has an 
	  int size of 2 bytes, as well as supercomputer with 16 bytes int */

	// You can ensure that your system has sizes that are appropiate for your computation using sizeof()
	char ch = 'c';
	printf("\nOn my system\n");
	printf("int is %lu bytes\n", sizeof(int));
	printf("long int is %lu bytes\n", sizeof(long int));
	printf("char is %lu bytes\n", sizeof(ch));
	printf("float is %lu bytes\n", sizeof(float));
	printf("double is %lu bytes\n", sizeof(double));
	printf("long double is %lu bytes\n", sizeof(long double));
	//printf("This is a ring bell \a");
	return 0;
}