/*
		ADT Binary Tree example

		Sept. 20, 2020
*/

#include <stdio.h>
#include <stdlib.h>

typedef char DATA;
struct node
{
		DATA d; //data is just a char in a tree node
		struct node *left; //tree branches
		struct node *right;
};
typedef struct node NODE;
//a binary tree will be a pointer to a node
//so you'll be able to look at a binary tree by a pointer to its root
typedef NODE *BTREE; 

//This is a way to traverse the tree (there are more like post-order and pre-order)
void InOrder(BTREE root)
{
	//For the in-order traversal, we check if the root is null
	if(root != NULL)
	{
		//If there's a root, we recur to the left
		InOrder(root->left);
		//we print the current data being pointed at
		printf("%c ", root->d);
		//then recur to the right
		InOrder(root->right);
		//so all the left is gonna be done before the right, that's why its called "in-order" traversal
	}
}

// Post-order traversal
void PostOrder(BTREE root)
{
    if (root != NULL) {
        PostOrder(root -> left);
        PostOrder(root -> right);
        printf("%c ", root -> d);
   }
}

//Create a node
BTREE New_Node()
{
	//allocating off of malloc which goes to the heap
	//getting as much memory as needed to represent a node
	return(malloc(sizeof(NODE))); //the value returned is a pointer value to this much memory
}

//initialize data
BTREE Init_Node(DATA d1, BTREE p1, BTREE p2)
{
		BTREE t;
		t = New_Node();
		t->d = d1;
		t->left = p1;
		t->right = p2;
		return t;
}

//create the whole tree
BTREE Create_Tree(DATA a[], int i, int size)
{
		if(i >= size) //check if we're done with the size of the array
		{
			return NULL;
		}
		else
		{
			//we create a node with every data in the array, a left pointer and a right pointer
			//the mapping (2*i+1 or 2*i+2) is because the tree bifurcates by factors of 2
			return(
				Init_Node(a[i], Create_Tree(a, 2*i+1, size), Create_Tree(a, 2*i+2, size))
				);
		}
}

int main()
{
	char d[] = {'a', 'b', 'c', 'd', 'e'};
	BTREE tree;
	tree = Create_Tree(d, 0, 5);
	printf("\n");
	printf("In-Order: ");
	InOrder(tree);
	printf("\n");
	printf("Post-Order: ");
	PostOrder(tree);
	printf("\n");
	//In-order: d b e a c
	//Post-order: d e b c a
	/*
			 a
		    / \
	       b   c
	      / \   
		 d   e 
	*/
	return 0;
}