/*
	Mergesort example
	Bubblesort is O(n^2), Mergesort is O(nLog(n))
	
	Sept. 07, 2020
*/

#include <stdio.h>

void Print_Array(int size, int data[], char *array_tittle)
{
	printf("%s", array_tittle);
	for(int i =0; i < size; i++)
	{
		printf("%d \t", data[i]);
	}
}

void Merge(int arrayA[], int arrayB[], int merged[], int size) //array a and b are same size, c is twice their size
{
	int i = 0, j = 0, k = 0; //i will loop through arrayA, j through arrayB, k through merged
	while(i<size && j<size)
	{
		//increment the merged array with the smaller element between both arrays
		if(arrayA[i] < arrayB[j])
		{
			merged[k++] = arrayA[i++]; 
		}
		else
		{
			merged[k++] = arrayB[j++];
		}
	}
	//Clean-up: we've gotten through one or the other of the arrays, and the remaining elements 
	// have to be sorted. So we decide which of the piles we're finished with and then put them
	// in the merged array.
	while(i<size)
	{
		merged[k++] = arrayA[i++];
	}
	while(j<size)
	{
		merged[k++] = arrayB[j++];
	}
}

int main()
{
	int size = 5;
	int arrayA[5] = {67, 82, 83, 88, 99};
	int arrayB[5] = {58,69,72,81,88};
	int merged[10];
	Print_Array(size, arrayA, "My grades (a) \n");
	printf("\n\n");
	Print_Array(size, arrayB, "My grades (b) \n");
	printf("\n\n");
	Merge(arrayA, arrayB, merged, size);
	Print_Array(size*2, merged, "My sorted grades \n");

	return 0;
}