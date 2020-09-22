/*
	Uses of Macros

	Sept. 12, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEPHANT_SEAL_WEIGHT_MALE 8800
#define MIN_ELEPHANT_SEAL_WEIGHT_MALE 4400
//Female range is 880-2000 lbs

//Produce a macro that randomly generates a male weight
#define RANGE 4400
#define POPULATION 1000
#define WEIGHT_OVER rand() % RANGE
#define WEIGHT WEIGHT_OVER + MIN_ELEPHANT_SEAL_WEIGHT_MALE
#define FILL for(i = 0; i<POPULATION; i++) \
				data[i] = WEIGHT
// The \ in the macro means that the macro is defined in two separated lines (multiline macros)

void Print_Data(int d[], int size)
{
	for(int index = 0; index<size; index++)
	{
		printf("%d\t", d[index]);
		if((index+1)%10==0)
		{
			printf("\n");
		}
	}
}

int main()
{
	int i; //This is for the foor-loop in the macro FILL
	int data[POPULATION];
	srand(time(0));
	FILL;
	Print_Data(data, POPULATION);
	printf("\n\n");

	return 0;
}