/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>

/*Binary tree structure*/
typedef struct tree {
	char *key; /*node value*/
	struct tree *leftChild; /*pointer to left subtree*/
	struct tree *rightChild;/*pointer to right subtree*/
}node;/*synonym for struct tree*/