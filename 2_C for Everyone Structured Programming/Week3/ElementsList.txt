/*
	Peer-graded Assignment: Week 3 Assignment: Working with lists
	Choose one of the following two options and upload your program as a text file.
	
	- Option 2 (Natural or Social Science Focus)
	Develop a struct that can store an atomic element, such as Hydrogen -H -at.wt 1.008.
	Create from input at the terminal the first ten elements in the periodic table as a
	linked list with this struct as data. Print out this information to the screen in a
	nicely readable form. The struct should have three members = one stores the name of
	the element, a second stores it atomic symbol, and a third stores its weight.

	Sept. 22, 2020
	James M. Romero Q.
*/

#include <stdio.h> //contains Input/Output functions (printf, scanf)
#include <stdlib.h> //contains malloc() 

//A list that will store atomic elements
typedef struct list 
{
	char *element_name; //string for an element's name
	char *atomic_symbol; //string for an element's symbol
	double element_weight; //double for an element's weight value
	struct list *next; //pointer linking next element
} list;

//Create a list with a single element and return it
list *Create_List(char *ename, char *symbol, double weight)
{
	//the list is created as a pointer to allocated memory by malloc() with the size of list
	list *head = malloc(sizeof(list));
	head -> element_name = ename; //the element name of the list is the string passed
	head -> atomic_symbol = symbol; //the atomic symbol of the list is the string passed
	head -> element_weight = weight; //the atomic weight of the list is the string passed
	head -> next = NULL; //the pointer is null since we're just creating the list
	return head;
}

//Add new elements to the front of the list and return it
list *Add_To_Front(char *ename, char *symbol, double weight, list *h)
{
	list *head = Create_List(ename, symbol, weight); //we create the new element of the list
	head -> next = h; //the new element points to the previous one
	return head;
}

/*
	Create a full single linked list from arrays of data and return it
	- A 2D array of strings is passed for both element names and atomic symbols
	- In 2D arrays, the size of the 2nd array must be specified
	- A 1D array is passed for element atomic weights
	- The three arrays has the same number of elements
*/
list *Array_To_List(char ename[][30], char symbol[][5], double weight[], int size)
{
	//create a new list with the first element of each array
	list *head = Create_List(ename[0], symbol[0], weight[0]);
	for(int idx = 1; idx<size; idx++) //loop through all array elements beginning from the 2nd one
	{
		/*
			Add all the array elements to the list beginning with the 2nd one since the 1st one was
			used to create the list
		*/
		head = Add_To_Front(ename[idx], symbol[idx], weight[idx], head);
	}
	return head;
}

//Prints all the list elements and a given title (constant string)
void Print_List(list *head, char *title)
{
	printf("%s \n", title);

	while(head != NULL) //Loop while we don't reach the end of the list
	{
		
		//Prints the list elements in the format: "Element name (symbol) weights (value with 3 significant figures)"
		printf(" Element %s (%s) weights %.3lf \n", head->element_name, head->atomic_symbol, head->element_weight);
		head = head -> next; //The head pointer of the list points to the next element
	}
}

int main()
{
	list *elements_list = NULL; //Define a list and initialize it as empty

	/*
		2D arrays are used for arrays of strings:
		- The 1st dimension has total elements in the array
		- The 2nd dimension has the maximum lenght minus 1 of a single string (because of the '\0' character at the end)
	*/
	char elementName[10][30]; //Define an string array for the element's names (max 29 characters)
	char elementSymbol[10][5]; //Define an string array for the element's atomic symbols (max 4 characters)
	double elementWeight[10]; //Define a double array for the element's atomic weight

	printf("Please insert the required information for 10 atomic elements: \n");

	for(int idx = 0; idx < 10; idx++) //Loop through all the arrays positions
	{
		printf("Insert the element #%d name: ", idx+1);
		scanf("%s", &elementName[idx]); //store the given string in the names array
		printf("Insert the element #%d atomic symbol: ", idx+1);
		scanf("%s", &elementSymbol[idx]); //store the given string in the symbols array
		printf("Insert the element #%d atomic weight (with 3 significant figures as 1.234): ", idx+1);
		scanf("%lf", &elementWeight[idx]); //store the given double in the weights array
		printf("\n");	
	}

	//Add all the arrays data to the list
	elements_list = Array_To_List(elementName, elementSymbol, elementWeight, 10);
	//Print the resulting list (the last elements inserted will show first)
	Print_List(elements_list, "Atomic Elements: ");
	printf("\n\n");

	return 0;
}