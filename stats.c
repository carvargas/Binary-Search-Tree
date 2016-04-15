/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include "struct.h"

/*counts number of strings in tree*/
int numNodes(node **tree)
{
	/*if node is empty*/
    if(*tree == NULL)
	{
		return 0;
	}
    
	/*if left and right children are empty*/
	else if( (*tree)->leftChild == NULL && (*tree)->rightChild == NULL)
	{
			/*add 1 for parent node*/
			return 1;
	}
	
	/*if children are not empty, call function and add until empty node reached*/
	else
	{
		return(1 + (numNodes(&((*tree)->leftChild)) + numNodes(&((*tree)->rightChild))));
	}
}

/*finds height of binary tree*/
int maxHeight(node **tree, int count) 
{
	/*if node is empty*/
	if (*tree == NULL) 
	{
		/*if node is a root*/
		if (count == 0)
		{
			return -1;
		}
		
		/*if node is a leaf*/
		else
		{
			return 0;
		}
	}
	
	/*if node is not empty*/
	else
	{
		count++;
		
		/*height of each subtree*/
		int leftH = maxHeight(&((*tree)->leftChild), count);
		int rightH = maxHeight(&((*tree)->rightChild), count);
 
		/*returns largest*/
		if (leftH > rightH) 
		{
			return(leftH+1);
		}
		
		else 
		{
			return(rightH+1);
		}
	}
} 

/*counts number of leaves*/
int leaf(node **tree)
{
	/*if node is empty*/
	if(*tree == NULL)  
	{		
		return 0;
	}
	
	/*if left and right subtrees are empty*/
	if((*tree)->leftChild == NULL && (*tree)->rightChild == NULL)    
	{		
		/*add 1 for parent node*/
		return 1;         
	}
	
	/*add number of leaves from left and right subtrees*/
	else
	{
		return leaf(&((*tree)->leftChild)) + leaf(&((*tree)->rightChild));     
	}		
}

/*finds height of left subtree*/
int lHeight(node **tree, int count) 
{
	/*if node is empty*/
	if (*tree == NULL) 
	{
		/*if node is a root*/
		if (count == 0)
		{
			return -1;
		}
		
		/*if node is a leaf*/
		else
		{
			return 0;
		}
	}
	
	/*if node is the root*/
	if(count == 0)
	{
		count++;
		return(lHeight(&((*tree)->leftChild), count));
	}
	
	/*height of left and right children in left subtree*/
	int leftH = maxHeight(&((*tree)->leftChild), count);
	int rightH = maxHeight(&((*tree)->rightChild), count);
 
	/*returns largest*/
	if (leftH > rightH) 
	{
		return(leftH+1);
	}
	
	else 
	{
		return(rightH+1);
	}
}

/*counts number of strings in left subtree*/
int lStrings(node **tree, int count) 
{  
	/*if node is empty*/
	if(*tree == NULL)  
	{		
		return 0;
	}

	/*if node is the root*/
	if(count == 0)
	{
		count++;
		return(lStrings(&((*tree)->leftChild), count));
	}
	
	/*number of strings in left subtree*/
	int leftH = lStrings(&((*tree)->leftChild), count);
	int rightH = lStrings(&((*tree)->rightChild), count);

	/*if node is not the root*/
	if(count > 0)
	{
		return(((leftH)+(rightH))+1);
	}
}

/*finds height of right subtree*/
int rHeight(node **tree, int count) 
{
	/*if node is empty*/
	if (*tree == NULL) 
	{
		/*if node is a root*/
		if (count == 0)
		{
			return -1;
		}
		
		/*if node is a leaf*/
		else
		{
			return 0;
		}
	}
	
	/*if node is the root*/
	if(count == 0)
	{
		count++;
		return(rHeight(&((*tree)->rightChild), count));
	}
	
	/*height of left and right children in right subtree*/
	int leftH = maxHeight(&((*tree)->leftChild), count);
	int rightH = maxHeight(&((*tree)->rightChild), count);
 
	/*returns largest*/
	if (leftH > rightH) 
	{
		return(leftH+1);
	}
	
	else 
	{
		return(rightH+1);
	}
}

/*finds number of strings in right subtree*/
int rStrings(node **tree, int count) 
{  
	/*if node is empty*/
	if(*tree == NULL)  
	{		
		return 0;
	}

	/*if node is the root*/
	if(count == 0)
	{
		count++;
		return(lStrings(&((*tree)->rightChild), count));
	}
	
	/*number of strings in right subtree*/
	int leftH = rStrings(&((*tree)->leftChild), count);
	int rightH = rStrings(&((*tree)->rightChild), count);
	
	/*if node is not the root*/
	if(count > 0)
	{
		return(((leftH)+(rightH))+1);
	}
}