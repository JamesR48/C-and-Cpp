/*
	Studying the use of pointers values

	Sept. 05, 2020
*/

#include <stdio.h>

int main()
{
	const int SIZE = 5;
	int grades[5] = {78, 67, 92, 83, 88};
	double sum = 0.0;
	double *ptr_to_sum = &sum; //the &sum means address of sum
	int idx;

	printf("My grades are: \n");
	for(idx = 0; idx < SIZE; idx++)
	{
		printf("%d, \t", grades[idx]);
	}
	printf("\n");
	for(idx = 0; idx<SIZE; idx++)
	{
		sum = sum + grades[idx];
	}
	printf("My average is %.2f \n\n", sum/SIZE);
	//%p diplays pointer address in hexadecimal
	//so %lu will print it as a long unsigned (ordinary decimal number non-negative)
	//%lf will print the value stored in that address, dereferencing with *ptr_to_sum
	printf("Sum is at %p, or %lu and is %lf \n", ptr_to_sum, ptr_to_sum, *ptr_to_sum);
	//here "grades" is the base address of the grades array, grades+5 is the address of the 5th element
	//the offset is 20 because each element in grades is an integer stored in 4 contiguous bytes
	printf("Grades are at %lu to %lu \n", grades, grades+5);

	return 0;
}