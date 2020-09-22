/*
	This is the "Peer-graded Assignment: Fix D. P's mistake (week 3)"
	Use the sin() function in the math library and write out an input's absolute value over an interval.

	Sept. 03, 2020
	Corrected by James M. Romero Q.
*/

#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

int main(void)
{ 
	double interval;
	int i;
	for(i = 0; i <30; i++)
	{
 		interval = i/10.0;
 		//fabs() is for doubles, abs() for ints
 		printf("sin( %lf ) = %lf \n", interval, fabs(sin(interval)));
	}

	printf("\n+++++++\n");
	return 0;
}