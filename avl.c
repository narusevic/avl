#include "avl.h"

int height(Node* n)
{
	if (n == NULL)
	{
		return 0;
	}
	return n->height;
}

Node* leftRotate(Node* n)
{
	Node* x = n->right;
	Node* T = x->left;

	x->left = n;
	n->right = T;

	n->height = (height(n->left) > height(n->right) ? height(n->left) : height(n->right)) + 1;
	x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;

	return x;
}

Node* rightRotate(Node* n)
{
	Node* x = n->left;
	Node* T = x->right;

	x->right = n;
	n->left = T;

	n->height = (height(n->left) > height(n->right) ? n->left->height : n->right->height) + 1;
	x->height = (height(x->left) > height(x->right) ? x->left->height : x->right->height) + 1;

	return x;
}

int countBalance(Node* n)
{
	return (n != NULL ? (height(n->left) - height(n->right)) : 0);
}

Node* balance(Node* n, int isDelete)
{
	int balanceFactor = countBalance(n);

	//left left
	if (balanceFactor > 1 && countBalance(n->left) >= (isDelete ? 0 : countBalance(n->right)))
	{
		return rightRotate(n);
	}
	//right right
	if (balanceFactor < -1 && countBalance(n->right) >= (isDelete ? 0 : countBalance(n->left)))
	{
		return leftRotate(n);
	}
	//left right
	if (balanceFactor > 1 && countBalance(n->left) < (isDelete ? 0 : countBalance(n->right)))
	{
		n->left = leftRotate(n->left);
		return rightRotate(n);
	}
	//right left
	if (balanceFactor < -1 && countBalance(n->right) < (isDelete ? 0 : countBalance(n->left)))
	{
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}

	return n;
}

Node* newNode(Node* n, int val, void* data)
{
	n = (Node*)malloc(sizeof(Node));

	n->value = val;
	n->data = data;
	n->height = 1;
	n->left = NULL;
	n->right = NULL;

	return n;
}

Node* insertNode(Node* n, int val, void* data, int* err)
{
	if (n == NULL)
	{
		return newNode(n, val, data);
	}

	if (val < n->value)
	{
		n->left = insertNode(n->left, val, data, err);
	}
	else if (val > n->value)
	{
		n->right = insertNode(n->right, val, data, err);
	}
	else
	{
		*err = 1;
		return n;
	}

	n->height = (height(n->left) > height(n->right) ? height(n->left) : height(n->right)) + 1;
		
	return balance(n, 0);
}

Node* deleteNode(Node* n, int val, int* err)
{
	*err = 1;
   	if (n == NULL)
	{
		return n;
	}
    
	if (val < n->value)
	{
		deleteNode(n->left, val, err);
	}
	else if (val > n->value)
	{
		deleteNode(n->right, val, err);  
	}
	else
	{
		*err = 0;
		if (n->left == NULL && n->right == NULL)
        	{
            		n = NULL;
            		free(n);
		}
		else if(n->left == NULL || n->right == NULL)
		{
			Node* temp = (n->left != NULL ? n->left : n->right);
			*n = *temp;
			n = (n->left != NULL ? n->left : n->right);
			free(temp);
		}
		else
		{
			Node* temp = n->right;
		    
			while (temp->left != NULL)
		    	{
		        	temp = temp->left;                
		    	}
		    
		    	n->value = temp->value;
		    
		    	n->right = deleteNode(n->right, temp->value, err);
		}
    	}
    
	if (n == NULL)
	{
		return n;    
	}
    
	n->height = (height(n->left) > height(n->right) ? height(n->left) : height(n->right)) + 1;
	
	return balance(n, 1);    
}

void preTraversal(int values[], Node* n, int* index)
{
	if (n != NULL)
	{		
		values[*index] = n->value;
		(*index)++;
		
		preTraversal(values, n->left, index);
		preTraversal(values, n->right, index);
	}
}

void preOrder(int values[], Node* n)
{
	int i = 0;
	preTraversal(values, n, &i);
}

void inTraversal(int values[], Node* n, int* index)
{
	if (n != NULL)
	{				
		inTraversal(values, n->left, index);
		
		values[*index] = n->value;
		(*index)++;
		
		inTraversal(values, n->right, index);
	}
}

void inOrder(int values[], Node* n)
{
	int i = 0;
	inTraversal(values, n, &i);
}

void postTraversal(int values[], Node* n, int* index)
{
	if (n != NULL)
	{		
		postTraversal(values, n->left, index);		
		postTraversal(values, n->right, index);
				
		values[*index] = n->value;
		(*index)++;
	}
}

void postOrder(int values[], Node* n)
{
	int i = 0;
	postTraversal(values, n, &i);
}

Node* findNode(Node* n, int val)
{
	Node* current = n;
	if (current == NULL)
	{
		return NULL;
	}
	
	if (val < current->value)
	{
		current = findNode(n->left, val);
	}
	else if (val > current->value)
	{
		current = findNode(n->right, val);		
	}
	else
	{
		return current;
	}
}

int avlSize(Node* n)
{
	if (n != NULL)
	{				
		return (avlSize(n->left) + avlSize(n->right) + 1);
	}
	
	return 0;
}
