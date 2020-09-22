/*
	Program for converting a marathon distance from miles and yards to kilometers.
*/

#include <stdio.h>

int main()
{
	int miles = 26, yards = 385;
	double kilometers;
	kilometers = 1.609 * (miles + yards / 1760.0); //Here we use 1760.0 instead of 1760
	//because in C, if we do a division between a smallest int and a greater int, the result will be rounded to 0
	//So we go for an EXPLICIT CONVERSION which takes the the more extensive type and makes the whole expression be of that type.
	printf("The marathon distance in kilometers is %lf \n", kilometers);

	return 0;
}