/*
	Program for converting an user's marathon distance from miles and yards to kilometers.
*/

#include <stdio.h>

int main()
{
	int miles, yards; //in a normal machine, an int is 4 bytes, so you can get +- 2 billion 
	double kilometers;
	printf("Insert the miles in Int: \n >> ");
	scanf("%d", &miles);
	printf("Insert the yards in Int: \n >> ");
	scanf("%d", &yards);
	kilometers = 1.609 * (miles + yards / 1760.0); //Here we use 1760.0 instead of 1760
	//because in C, if we do a division between a smallest int and a greater int, the result will be rounded to 0
	//So we go for an EXPLICIT CONVERSION which takes the the more extensive type and makes the whole expression be of that type.
	printf("Your marathon distance in kilometers is %lf \n", kilometers);

	return 0;
}