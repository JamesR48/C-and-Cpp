/*
	This is the "Peer-graded Assignment: Write a program that prints the sine function for an input x between (0, 1) of Week 2"
	
	Program that can output the sine of a value between 0 and 1 (non inclusive).

	Sept. 02, 2020
	James M. Romero Q.
*/

#include <stdio.h>
#include <math.h>
//math.h is included since it contains the mathematical functions that we'll need for this program

int main()
{
	int value = 0; // variable declaration and initialization
	printf("Please write a number (as an int) for calculating its sine: \n >> ");
	scanf("%d", &value);
	//sin() gives the resulting sine value of a given number as a double.
	printf("the sine of %d is %lf \n", value, sin(value));

	return 0;
}