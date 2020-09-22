/*
	Mergesort with power of 2 as size example
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

void Mergesort(int key[], int size) //size is a power of 2: 2, 4, 8, 16...
{
	//key: item that's being sorted on
	int j, k;
	int w[size];
	//k is multiplied by a power of 2
	//	So first we compare pairs, then we compare 2 pairs, then 3 pairs...
	//  until finishing all keys.
	for(k = 1; k < size; k *= 2) 
	{
		for(j = 0; j < size-k; j += 2 * k)
		{
			Merge(key+j, key+j+k, w+j, k);
		}
		for(j = 0; j < size; j++)
		{
			key[j] = w[j];
		}
	}
}

int main()
{
	int size = 8;
	int array[8] = {99,82,74,85,92,67,76,49}; //keys array
	Print_Array(size, array, "My grades \n");
	printf("\n\n");
	Mergesort(array, size);
	Print_Array(size, array, "My sorted grades \n");
	printf("\n\n");

	return 0;
}