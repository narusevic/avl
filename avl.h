// 686

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int value;
	void* data;
	int height;
	struct node * left;
	struct node * right;
};

typedef struct node * avl;
typedef struct node Node;

Node* insertNode(Node*, int, void*, int*); // err == 1, if already exists
Node* deleteNode(Node*, int, int*); //err == 1, Node with key n, not found
Node* findNode(Node*, int); // returns NULL if not found
int avlSize(Node*); // counts all nodes
void preOrder(int[], Node*);
void inOrder(int[], Node*);
void postOrder(int[], Node*);

#endif

