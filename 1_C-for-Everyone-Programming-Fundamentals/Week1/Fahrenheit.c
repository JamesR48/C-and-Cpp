/*
	Program that converts Fahrenheit to Celsius degrees.
	C = (F-32)/1.8
*/

#include <stdio.h>

int main()
{
	int fahrenheit, celsius;
	printf("Insert Fahrenheit degrees as an Int: \n >> ");
	scanf("%d",&fahrenheit);
	celsius = (fahrenheit - 32)/1.8; //This expression evaluates as a double because of the 1.8
	//So the division makes an EXPLICIT CONVERSION from int to double
	//Then a SILENT CONVERSION occurs, because the expression gives a double but celsius is an int variable
	printf("%d degrees fahrenheit are %d degrees celsius. \n", fahrenheit, celsius);

	return 0;
}