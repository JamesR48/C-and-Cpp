/*
	Enumerated types example

	Sept. 12, 2020
*/

#include <stdio.h>

enum day{ Sun, Mon, Tue, Wed, Thu, Fri, Sat };
typedef enum day day;

void Print_Day(day d)
{
	switch(d)
	{
		case Sun: printf("Sunday");
			break;
		case Mon: printf("Monday");
			break;
		case Tue: printf("Tuesday");
			break;
		case Wed: printf("Wednesday");
			break;
		case Thu: printf("Thursday");
			break;
		case Fri: printf("Friday");
			break;
		case Sat: printf("Saturday");
			break;
		default: printf("%d is an error", d); //will print an int based on the day index
			break;
	}
} 

day Next_Day(day d)
{
	return(d+1%7);
}

int main()
{
	day today = Fri;
	Print_Day(today);
	printf("\n\n");
	Print_Day(7);
	printf("\n\n");
	Print_Day(Next_Day(today));
	printf("\n\n");

	return 0;
}