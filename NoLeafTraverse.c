#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {
	int data;
	struct BinaryTree *right, *left;
}Tree;

Tree *NodeCreator (int data)
{
	Tree *NewNode = (Tree*)malloc(sizeof(Tree));
	NewNode->data = data;
	NewNode->left = NewNode->right = NULL;
	return NewNode;
}

Tree *TreeInsert (Tree *root,int data)
{
	if (root == NULL)
		return NodeCreator(data);
	else
	{
		if(data <= root->data)
			root->left = TreeInsert(root->left,data);
		else
			root->right = TreeInsert(root->right,data);
	}
	return root;
}

void NoLeafTraverse (Tree *root)
{
	if(root->left)
	{
		NoLeafTraverse(root->left);
	}
	if (root->right)
	{
		NoLeafTraverse(root->right);
		printf("%d ",root->data);
	}
}

void InorderTraverse (Tree *root)
{
	if(root)
	{
		InorderTraverse(root->left);
		printf("%i ",root->data);
		InorderTraverse(root->right);
	}
}

int main ()
{
	Tree *root = NULL;
	
	root = TreeInsert(root,50);
	root = TreeInsert(root,10);
	root = TreeInsert(root,20);
	root = TreeInsert(root,15);
	root = TreeInsert(root,60);
	root = TreeInsert(root,70);
	root = TreeInsert(root,30);
	
	NoLeafTraverse(root);
	printf("\n");
	InorderTraverse(root);
	
	return 2;
}
