#include <stdio.h>

//extern is for saying that "an item should exist throughout the execution of the code and is available for any function"
// So, its "globlal"
extern int reps = 0; 

void F()
{
	//static means that variable "called" is initialized to 0, but everytime it's called after that,
	// the value is going to be whatever its last exited value is.
	static int called = 0; 
	printf("F called %d \n", called);
	called++;
	reps += called;
}

int main()
{ 
	//auto is "automatic", and means that whenever we enter this function, "i" will get put on a block and gets used.
	auto int i = 1;
	//const isn't a storage class, const means that a value cannot be changed.
	const int Limit = 10;
	for(i = 1; i<Limit; i++)
	{
		printf("i local = %d, reps global = %d \n", i, reps);
		F();
	}
	return 0;
}