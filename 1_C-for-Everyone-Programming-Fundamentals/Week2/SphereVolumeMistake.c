/*
	This is the "Peer-graded Assignment: Fix Dr. P’s mistake (week 2)"
	Calculate the volume of a sphere as a double using ints.

	Sept. 02, 2020
	Corrected by James M. Romero Q.
*/

#include<stdio.h>

#define PI 3.14159

int main(void)
{ 
 double radius;
 printf("Enter radius:");	
 scanf("%lf", &radius);
printf("volume is : %lf \n\n", 4*PI*radius*radius*radius/3 );

return 0;
}