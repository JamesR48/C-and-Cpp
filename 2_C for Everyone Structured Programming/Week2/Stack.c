/*
	Stack ADT example.
	Using a stack to reverse a string.

	Sept. 16, 2020.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack
{
	char string[MAX_LEN];
	int top;
} stack;

void reset(stack *stk)
{
	stk -> top = EMPTY;
}

void push(char c, stack *stk)
{
	stk -> top++;
	stk -> string[stk -> top] = c;
}

char pop(stack *stk)
{
	//In this case we'll return the character at the top of the stack and erase it from the stack
	return(stk -> string[stk -> top--]);
}

char top(const stack *stk) //use const since we don't want to affect the stack
{
	//In this case we'll just return the character at the top of the stack
	return(stk -> string[stk -> top]);
}

int Is_Empty(const stack *stk)
{
	//0 is false, 1 is true
	return(stk -> top == EMPTY);
}

int Is_Full(const stack *stk)
{
	//0 is false, 1 is true
	return(stk -> top == FULL);
}

int main()
{
	stack stack_of_char;
	char *str = "i am otto am i";
	char str_back[20];
	int index = 0;
	reset(&stack_of_char);
	printf(" Original is: %s \n", str);
	while(str[index] != '\0') // '\0' means the end of the string character
	{
		printf("\t %c \n", str[index]);
		push(str[index++], &stack_of_char);
	}
	index = 0;
	while(!Is_Empty(&stack_of_char) && index < 20)
	{
		str_back[index++] = pop(&stack_of_char); 
	}
	printf(" Reverse is: %s \n\n", str_back);

	return 0;
}