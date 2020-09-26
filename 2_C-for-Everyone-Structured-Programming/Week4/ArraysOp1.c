/*
	Peer-graded Assignment: Week 4 Assignment: Arrays
	Option 1:
	Open and read a file of integers into an array that is created with the first integer 
	telling you how many to read. So  4  9  11  12  15  would mean create an int array size
	4 and read in the remaining 4 values into data[]. Then compute their average as a double
	and their max  as an int.  Print all this out neatly to the screen and to an output file
	named answer-hw3.

	Sept. 26, 2020
	James M. Romero Q.
*/

#include <stdio.h> //For Input and Output functions
#include <stdlib.h> //For exit()

//In this function we get the first character of a file and save it in an int variable
void Get_Array_Size(FILE *ifptr, int *size)
{
	rewind(ifptr); //We go to the beginning of the file
	fscanf(ifptr, "%d", size); //We read the file and save it's 1st character into an int variable
	printf(" Array size: %d \n", *size); //Print the saved size	
}

//This function populates a given int array with the file's data (excluding the first character)
void Create_Array(FILE *ifptr, int array[], int size)
{
	printf(" Array data: ");
	for(int idx = 0; idx < size; idx++)
	{
		//Loop through the file and pupulate the array with its data (starting from the 2nd character of file's data)
		fscanf(ifptr, "%d", &array[idx]); 
		//print the array data to the screen
		printf("%d ", array[idx]);
	}
	printf("\n");
}

//This function calculates and returns the array's values average as a double	
double Array_Average(int array[], int size)
{
	double sum = 0.0; //Declare and initialize a double variable for storing the array value's sum
	for(int idx = 0; idx < size; idx++)
	{
		sum += array[idx]; //loop through the array values and add them all
	}
	return sum/size; //return the average (total sum/number of elements)
}

//This function returns the array's maximum value as an int
int Array_Max(int array[], int size)
{
	//Create an int flag variable that'll be used to compare the array elements
	int max = array[0]; //the flag will be initialized to the beginning of the array

	for(int idx = 0; idx < size; idx++) //loop through the array elements
	{
		//compare the array elements, if the current maximum is less than any other element
		if(max < array[idx])
		{
			max = array[idx]; //the new maximum will now be the largest element found
		}
	}

	return max; //return the found maximum
}

/*
	the main function gets two arguments:
	- argc is the count of words written in the command line when the application starts
	- argv is an array of strings (words) written in the command line when the application starts
*/
int main(int argc, char *argv[])
{
	FILE *inputFilePtr, *outputFilePtr; //declare 2 file pointers for the input and output files respectively
	int size; //declare an int variable that will store the size of the array

	//The program expects the user to write 3 file names: the executable file, the input file, and the output file
	if(argc != 3)
	{
		printf("\n Need the name of the executable, the name of the input file, and the name of the output file\n");
		exit(1); //if there're not 3 file names when the application starts, abort the execution
	}

	inputFilePtr = fopen(argv[1], "r"); //Open the 1st file as "read only"
	outputFilePtr = fopen(argv[2], "w+"); //Open the 2nd file as "write + read"

	printf("\n %s is the file to read from \n\n", argv[1]); //argv[1] is 1st (input) file's name
	printf(" %s is the file to write on \n\n", argv[2]); //argv[2] is 2nd (output) file's name
	
	Get_Array_Size(inputFilePtr, &size); //get the array size given the 1st file's data
	
	int array[size]; //declare an array of that found size

	Create_Array(inputFilePtr, array, size); //populate the array with the 1st file's data (excluding its 1st character)

	printf(" Average is: %lf \n", Array_Average(array, size)); //print the average of array values to the screen
	//write the average of array values in the output file
	fprintf(outputFilePtr, " Average is: %lf \n", Array_Average(array, size)); 

	printf(" Maximum is: %d \n", Array_Max(array, size)); //print the maximum value of the array to the screen
	//write the maximum value of the array in the output file
	fprintf(outputFilePtr, " Maximum is: %d \n", Array_Max(array, size));

	//close both input and output files
	fclose(inputFilePtr);
	fclose(outputFilePtr);


	return 0;
}