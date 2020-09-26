/*
	File I/O example with a text file of homework scores

	Sept. 24, 2020.

	//////////// NOTE: compile using the gcc -std=c99 flag since the data array has variable size //////////////////////////////
*/

#include <stdio.h>

#define MAX_HW 20 //Assume we don't have more than 20 scores in the file

/*
	size is a pointer since we're going to find out how many elements are in the file and
	update size's value according to that
*/
void Read_Data(FILE *ptr, int d[], int *size)
{
	*size = 0;
	/*
		So, we want to find out the real size of the file, that's why we update size's value to 0
		and then start going through the file asking if it have X quantity of data, if it fails (return 1)
		means we got to the end of the file, so we stop the loop there.
		fscanf() returns the number of values read.
	*/
	while(fscanf(ptr, "%d", &d[*size]) == 1)
	{
		(*size)++;
	}
}

void Print_Data(int d[], int size)
{
	for(int idx = 0; idx<size; idx++)
	{
		printf(" %d ", d[idx]);
		if((idx+1)%10 == 0)
		{
			printf("\n");
		}
	}
}

double Average(int d[], int size)
{
	double avg = 0.0;

	for(int idx = 0; idx<size; idx++)
	{
		avg += d[idx];
	}

	return(avg/size); 
}

int main()
{
	int size = MAX_HW; 
	FILE *ifp; //file pointer
	//int data[size] = {100, 0}; //initializes with the 1st score being 100 and the other 19 being 0
	int data[size];

	ifp = fopen("myhw.txt", "r"); //open the file "myhw" for read only assuming is in the same folder as this code
	//pass a pointer to size since we want to change its value in case the file has less data
	Read_Data(ifp, data, &size); 
	printf(" My %d homework scores are: \n", size);
	Print_Data(data, size);
	printf("\n");
	printf(" Average score was: %10f \n", Average(data, size));
	printf("\n");
	fclose(ifp); //must always close file, but in this case exiting the program leads to automatically close the file

	return 0;
}