/*
	Program for calculating a circle area given it's radius.
*/

#include <stdio.h>

#define PI 3.14159 //define a pre-processor token (constant) called PI, which have 6 significant figures (a normal double)

int main()
{
	double radius, area;
	printf("Let's calculate the area of a circle\n What is the radius? > ");
	scanf("%lf", &radius); //%lf is a long float (double). &radius is the address of radius
	area = PI * radius * radius; // circleArea = PI*radius^2
	printf("\n The area is %lf squared meters \n ",area);

	return 0;
}