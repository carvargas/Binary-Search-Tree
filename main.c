/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/*string constant*/
#define STR_LEN 16

/*prototypes*/
void insertNode(node **tree, char *value);
int numNodes(node **tree);
int maxHeight(node **tree, int);
int leaf(node **tree);
int lHeight(node **tree, int);
int lStrings(node **tree, int);
int rHeight(node **tree, int);
int rStrings(node **tree, int);

int main(int argc, char *argv[])
{
	/*end program if there aren't three arguments*/
	if(argc != 3)
	{
		fprintf(stderr, "Not enough arguments!\n");
		return 0;
	}
	
	/*variables*/
	char *item;
	int lNum = 0;
	int rNum = 0;
	int mNum = 0;
	
	/*allocates memory space for string pointer*/
	item = (char*)malloc(STR_LEN * sizeof(char));
	
	/*file pointers*/
	FILE *fp;
	FILE *fo;
	
	/*tree is intially empty*/
	node *root = NULL;
	
	/*if file is unable to open, exit*/
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Input file could not be opened\n");
		return 0;
	}
	
	/*read strings in file until EOF*/
	while((feof(fp) == 0))
	{
		item = (char*)malloc(STR_LEN * sizeof(char));
		fscanf(fp, "%s", item);
		
		/*insert string into tree*/
		insertNode(&root, item);
	}
	
	/*if output file cannot be opened end program*/
	if((fo = fopen(argv[2], "w")) == NULL)
	{
		printf("Output file could not be opened\n");
		return 0;
	}
	
	/*print stats to output file*/
	fprintf(fo, "The total number of strings in the input file: %d\n", numNodes(&root));	
	
	/*to count the links instead of nodes, -1 represents no links in tree*/
	mNum = (maxHeight(&root, 0)-1);
	if(mNum < 0)
	{
		fprintf(fo, "The height of the binary search tree: 0\n");
	}
	else 
	{
		fprintf(fo, "The height of the binary search tree: %d\n", mNum);
	}
	
	fprintf(fo, "The number of leaves in the binary search tree: %d\n", leaf(&root));
	
	/*to count the links instead of nodes, -1 represents no links in left subtree*/
	lNum = (lHeight(&root, 0)-1);
	if(lNum < 0)
	{
		fprintf(fo, "The height of the left subtree of the root: 0\n");
	}
	else 
	{
		fprintf(fo, "The height of the left subtree of the root: %d\n", lNum);
	}
	
	fprintf(fo, "The number of strings in the left subtree of the root: %d\n", (lStrings(&root, 0)));
		
	/*to count the links instead of nodes, -1 represents no links in right subtree*/
	rNum = (rHeight(&root, 0)-1);
	if(rNum < 0)
	{
		fprintf(fo, "The height of the right subtree of the root: 0\n");
	}
	else 
	{
		fprintf(fo, "The height of the right subtree of the root: %d\n", rNum);
	}
	
	fprintf(fo, "The number of strings in the right subtree of the root: %d\n", (rStrings(&root, 0)));
	
	/*close files*/
	fclose(fp);
	fclose(fo);
	
	return 0;
}