/*
	File I/O: Double space input to output file example with a text file of homework scores

	Sept. 25, 2020.

	//////////// When opening the executable, make sure to write the 2 files names next to the executable name. 
							The 2nd file will be created with the provided name         ////////////////////////
*/

#include <stdio.h>
#include <stdlib.h> //for using exit() which allows to exit the program (like abort)

//Do a character for character print out
void Print_File(FILE *fptr)
{
	int c;
	rewind(fptr); //make sure we're at the beginning of the file
	//while we can get a character from the file pointed at fptr and isn't yet the end of the file
	while( (c = getc(fptr)) != EOF ) //EOF is equal to -1
	{ 
		putc(c, stdout); //we put the character out to the screen (standard out)
		//so this is reading and writing 1 character at a time (reading from input file and writing to character file)
	}
	//this while loop is very standard for processing files 1 character at a time (specially desirable if dealing with text)
}

//
void Double_Space(FILE *ifp, FILE *ofp)
{
	int c;
	rewind(ifp); //make sure we're at the beginning of the file
	//while we can get a character from the file pointed at fptr and isn't yet the end of the file
	while( (c = getc(ifp)) != EOF) //EOF is equal to -1
	{
		putc(c,ofp); //put the character into the output file
		//putchar(c); //for debugging: show the character c on screen
		if(c=='\n') //if the character is a new line ('\n')
		{
			putc('\n', ofp); //add a second new line ('\n')
			//so for every new line in the input file, put a 2nd new line into the output file (hence double spacing)
		}
	}
}

//main is getting arguments from the command line (argc and argv)
//argv notation can also be written as 'char **argv' without the "[]" since empty brackets [] are the same as a pointer
int main(int argc, char *argv[]) 
{ 
	FILE *ifp, *ofp; //file pointer to input and output files
	/*
		make user the user has not only an executable, but also an input and output file meaning
		that argc has to show up as 3.

		//////////// When opening the executable, make sure to write the 2 files names next to the executable name. 
							The 2nd file will be created with the provided name         ////////////////////////
	*/
	if(argc != 3) 
	{
		printf(" Need executable inputfile outputfile \n");
		exit(1);
	}

	ifp = fopen(argv[1], "r+"); //open the input file for read and write (r+)
	ofp = fopen(argv[2], "w+"); //open the output file for write and read (w+)
	printf(" my %s file as read is \n\n", argv[1]); //argv[1] is 1st file's name
	Print_File(ifp);
	printf("\n");
	Double_Space(ifp, ofp);
	printf(" my %s file double spaced is \n\n", argv[2]); //argv[2] is 2nd file's name
	Print_File(ofp);
	printf("\n");
	fclose(ifp); //must always close file, but in this case exiting the program leads to automatically close the file
	fclose(ofp);

	return 0;
}