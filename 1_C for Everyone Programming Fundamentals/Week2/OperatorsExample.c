/*
	Program for testing some operators and understanding the way they work.

	Sept. 02, 2020
	James M. Romero Q.
*/

#include <stdio.h>

int main()
{
	int a=3, b=4;
	printf("3*5: %d \n",3*5);
	printf("3*5+2: %d \n",3*5+2);
	printf("3*(5+2): %d \n",3*(5+2));
	printf("5modulo3: %d \n",5%3);
	printf("3modulo5: %d \n",3%5);
	printf("-5modulo3: %d \n",-5%3);
	printf("5<7+2: %d \n",5<7+2);
	printf("7<5+2: %d \n",7<5+2);
	printf("(5<7)+2: %d \n",(5<7)+2);
	printf("8==-8: %d \n",8==-8);
	printf("8==-(-8)): %d \n",8==-(-8));
	printf("8==+8: %d \n",8==+8);
	printf("3/5 (int): %d \n",3/5);
	printf("3.0/5 (double): %lf \n",3.0/5);
	printf("3/5.0 (double): %lf \n",3/5.0);
	printf("4/3 (int): %d \n",4/3);
	printf("++a + b++: %d \n",++a+b++);
	return 0;
}