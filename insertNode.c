/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void insertNode(node **tree, char *value)
{
	/*if node is empty*/
	if(*tree == NULL)
	{
		/*allocate memory for node*/
		*tree = (struct tree*)malloc(sizeof(struct tree));
		
		/*if space was allocated successfully*/
		if(*tree != NULL)
		{
			/*put string into node*/
			(*tree)->key = value;
			
			/*new node's children are set to empty*/
			(*tree)->leftChild = NULL;
			(*tree)->rightChild = NULL; 
		}
		
		/*if space was allocated unsuccessfully*/
		else
		{
			fprintf(stderr, "%s not inserted. No memory.\n", *value);
		}
	}
	
	/*if node is not empty*/
	else
	{
		/*value is less than value in current node*/
		if((strcmp(value, (*tree)->key) < 0))
		{
			/*insert value into left subtree*/
			insertNode(&((*tree)->leftChild), value);
		}
		
		/*value is greater than value in current node*/
		else 
		{
			/*insert value into right subtree*/
			insertNode(&((*tree)->rightChild), value);
		}

	}
	}