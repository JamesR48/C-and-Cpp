/*
	This is the "Peer-graded Assignment (Week 5)"
	Program that computes the average weight for a population of elephant seals read into an array.
	
	Sept. 09, 2020
	James M. Romero Q.
*/

#include <stdio.h> //Library for Input [fopen(), fscanf()] and Output [printf()] functions

//Calculate_Average() will calculate the average of all weight samples given the array with the data and its size.
double Calculate_Average( int data[], int size)
{
	int sum = 0; //This will add all the weight values in the array data
	for(int index = 0; index < size; index++) //Loop from 0 to 1000 (non inclusive)
	    {
	    	sum += data[index]; //Calculate the sum of all weight samples
	    }

	//return the average of weight samples as double, average = (sum of all values) / (number of values)
	//the size is casted to dobule by using the cast operator (double)
	return (sum/(double)size); 
}

//Get_Data() will open the text file with the weights and save its content into an array
void Get_Data()
{
	int value_count = 1000; //The weights file has 1000 samples
	double average = 0.0; //This is for saving the calculated average as a double

	//When working with files, you need to declare a pointer of type FILE.
	//This declaration is needed for communication between the file and the program.
	FILE *file_ptr;
	//fopen("filename", "mode") opens the filename pointed to using the given mode.
	//In this case, the mode was "r" that means read only.
	//The way the filename was writted means that the file must be in the same folder directory as this source code.   
	file_ptr = fopen("elephant_seal_data.txt", "r");

	//If fopen() returns a NULL value, print an error message and exit this function.
	if(file_ptr == NULL)
	{
		printf("There was an error opening file! \n");
		return;
	}
	
	int weights_array[value_count]; //The weights will be saved in this 1D array of 1000 elements. The weights are integers

	printf("\nThe weight data of the northern elephant seals is: \n\n");

	for(int index = 0; index < value_count; index++) //Loop from 0 to 1000 (non inclusive)
	{
		//fscanf() reads formatted input from a file.
		//In this case the format is %d (integer) and the file is file_ptr, which contains the weights text file.
		//The integer data is saved in an 1D array. The first weight in the file is saved in the array[0] position,
		//then the second weight is saved in the array[1] position...and so until the 1000th weight is saved in array[999]
	    fscanf(file_ptr, "%d", &weights_array[index]);
	    printf("%d ", weights_array[index]);
	}

	//The average is calculated in another function, just need to give it the array with the data and its size
	average = Calculate_Average(weights_array, value_count);

	//fclose() closes the opened file.
	//A file needs to be closed after a read or write operation to release the memory allocated by the program.
	fclose(file_ptr);

	printf("\n\nThe average weight from %d samples is: %lf \n", value_count, average);
}

//The main function
int main()
{
	Get_Data(); //Here we just call Get_Data()

	return 0;
}