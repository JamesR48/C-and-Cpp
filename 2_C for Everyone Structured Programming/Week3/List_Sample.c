/*
	Single Linked List of 1 element - Abstract Data Type example program

	Sept. 18, 2020
*/

#include <stdio.h>
#include <stdlib.h> //for malloc()
#include <ctype.h>

typedef struct list
{
	int data; //This can be any type of data, even a complex struct
	struct list *next;
} list;

int Is_Empty(const list *l)
{
	//An empty list has its head pointer (or the beginning of the list pointer) null
	//Can also be used to know where is the end of the list (the tail) which has null as value
	return(l == NULL);
}

void Print_List(list *h, char *title)
{
	printf("%s \n", title); //title of the list
	/*
		We're going down the list:
		1st - test on the sentinel and keep iterating until the end of the list
		2nd - do something based on the data (in this case printing it)
		3rd - advance the pointer and repeat until you get to the empty list
		(in case of a recursive approach, the base case would be testing whether something is null)
	*/
	while(h != NULL) //ask if the head is empty, in which case we're done (1st)
	{
		printf("%d: \t", h->data); //print the element value (head pointing at data) (2nd)
		h = h -> next; //chain along the list, so the head point to the next value (3rd)
	}
}

int main()
{
	list list_of_int;
	list *head = NULL; //head starts as null so the list starts empty
	//create the list using malloc()
	//malloc() goes off to the heap, grabs sizeof list memory (in bytes)
	head = malloc(sizeof(list)); 
	printf("sizeof(list) = %lu \n", sizeof(list)); //print sizeof(list) with unsigned long (we are printing bytes)
	head -> data = 5; //create a 1 element list where data is equal to 5
	head -> next = NULL; //next points at null since the list has only 1 element, otherwise errors may appear
	Print_List(head, "single element list example");
	printf("\n\n");

	return 0;
}