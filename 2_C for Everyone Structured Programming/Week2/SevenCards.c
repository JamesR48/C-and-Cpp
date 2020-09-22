/*
	Week 2 Honors Assignment:
	Use a struct to define a card as an enumerated member that is its suit value and a short
	that is its pips value. Write a function that randomly shuffles the deck. Then deal out
	7 card hands and evaluate the probability that a hand has no pair, one pair, two pair,
	three of a kind, full house and 4 of a kind. Use at least 1 million randomly generated hands.

	Sept. 17, 2020
	James M. Romero Q.
*/

#include <stdio.h>

typedef enum suit {C, D, H, S} suit; //Clubs, Diamond, Hearts, Spades

typedef struct card
{
	short int pips; //1 to 13, 13 is king, 1 is ace
	suit st;
}card; 

int main()
{
	card deck[52]; //define a deck consisting of 52 cards

	return 0;
}