/*
	Single Linked List of multiple elements - Abstract Data Type example program

	Sept. 18, 2020
*/

#include <stdio.h>
#include <stdlib.h> //for malloc()
#include <ctype.h>

typedef struct list
{
	int data; //This can be any type of data, even a complex struct
	struct list *next; //list inside of list linking to next
} list;

int Is_Empty(const list *l)
{
	//An empty list has its head pointer (or the beginning of the list pointer) null
	//Can also be used to know where is the end of the list (the tail) which has null as value
	return(l == NULL);
}

list *Create_List(int d) //can be any type of data
{
	//create the head of the list going to the heap by using malloc()
	//and create an element with the size of list (in bytes)
	list *head = malloc(sizeof(list)); 
	head -> data = d; //the data will be the d int value
	head -> next = NULL; //head points to null (so every element we initialize, has its next pointer or tail to null)
	return head; //When creating the list, we return the head found dynamically
}

//when bulding the list, we add to the front of the list
//A list is like a closed line, you can't put thing in the middle(like an array)
//That's why searching in a list is O(n) since it goes through every element
list *Add_To_Front(int d, list *h) //get the data we want and the head of the list
{
	list *head = Create_List(d); //create the list with tha data
	//what was the current head, is now going to point at next
	//Now the newly created element will be the new head of the list
	//So we had a list of X elements, we create a new one with its head
	//we link its next pointer to the old list, and the head is now the head of the whole list
	head -> next = h; 
	return head;
}

list *Array_To_List(int d[], int size) //converting an array of data to a list given the array and its size
{
	list *head = Create_List(d[0]); //create the list using the 1st element of the array
	for(int idx = 1; idx<size; idx++) //from 1 (2nd element) until the end of the array, we keep adding to the front of the list
	{
		head = Add_To_Front(d[idx], head);
	}
	return head;
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
		printf("%d, ", h->data); //print the element value (head pointing at data) (2nd)
		h = h -> next; //chain along the list, so the head point to the next value (3rd)
	}
}

int main()
{
	list list_of_int;
	list *head = NULL; //head starts as null so the list starts empty
	int data[6] = {2,3,5,7,8,9};
	head = Array_To_List(data, 6);
	Print_List(head, "multi element list from array");
	//notice that "2" is the first element, then "3" becomes the first element,
	//then 5...and so on until we get to 9	
	printf("\n\n");

	return 0;
}