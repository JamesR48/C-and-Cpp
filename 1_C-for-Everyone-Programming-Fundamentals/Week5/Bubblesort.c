/*
	Bubblesort example

	Sept. 07, 2020
*/

/*
	Bubblesort is considered inefficient for very large arrays.
*/
#include <stdio.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print_Array(int size, int data[], char *array_title)
{
	printf("%s", array_title);
	for(int i = 0; i < size; i++)
	{
		printf("%d \t", data[i]);
	}
}

void Bubble(int size, int data[])
{
	int i, j;
	int go_on; //this is for stopping the progam in middle of the loop to see how the process executes 

	for(i = 0; i < size; i ++)
	{
		Print_Array(size, data, "\n Inside Bubblesort \n"); //print how the array looks each time through
		printf(" i = %d, input any int to continue: ", i);
		scanf("%d", &go_on); //In order to continue the execution, you must enter any integer number (like a breakpoint)
		for(j = size - 1; j > i; j --)
		{
			//Bubblesort will place the largest element in the array off to the "extreme right"
			if(data[j-1] > data[j]) //If 2 elements are out of order, we swap them
			{
				Swap(&data[j-1], &data[j]);
			}
		}
	}
}

int main()
{
	int size = 5;
	int grades[5] = {78, 67, 92, 83, 88};

	Print_Array(size, grades, "My grades: \n\n");
	Bubble(size, grades);
	Print_Array(size, grades, "My sorted grades: \n\n");

	return 0;
}