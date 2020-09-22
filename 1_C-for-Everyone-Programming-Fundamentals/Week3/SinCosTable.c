/*
	program that  prints a table of values for sine and cosine between (0, 1).

	Spet. 03, 2020
	James M. Romero Q.
*/

#include <stdio.h> //For using input and output functions, in this case printf()
#include <math.h> //For using mathematical functions, in this case sin() and cos()

int main()
{
	float values = 0.0; //definition and initialization as float type of the values that will be calculated
	
	for(int index = 0; index <= 10; index++) //for-loop with range from 0 to 10 (inclusive)
	{
		values = index/10.0; // we get the values as float dividing the loop index by 10.0
		// so we're calculating the sine and cosine of the values 0.0, 0.1, 0.2, 0.3,...,1.0 

		//the %.1f means that we print a float value with just 1 digit after the decimal separator (i.e. 0.1, 0.2,...etc)
		// %lf is for printing double values, which are the ones returned by the sin() and cos() functions
		printf("Sin(%.1f) = %lf || Cos(%.1f) = %lf \n", values, sin(values), values, cos(values));
		printf(" ------------------------------------------ \n");
	}

	return 0;
}