#include <stdio.h>
#include <stdlib.h>
#include <avl.h>

struct zmogus{
	char* vardas;		
	int height;		
};

int main()
{
	/*
	* implementation:
	* avl root = NULL; 
	* 
	* operations:
	* root = insertNode(root, value);           where value is your key
	* root = deleteNode(root, value);  
	* avl newNode = findNode(root, value);
	* 
	* int size = avlSize(root);
	* int array[size];d                          where array is where you want to store values
	* preOrder(array, root);					
	* inOrder(array, root);
	* postOrder(array, root);
	*/
	
	/*struct zmogus lukas;
	char *name;
	name = "Lukas";
	lukas.vardas = name;
	lukas.height = 173;
	
	avl root = NULL; 
	
	int err = 0, err2 = 0;

	root = insertNode(root, 9, "abc", &err);
	root = insertNode(root, 5, "bde", &err);
	root = insertNode(root, 10, "c", &err);
	root = insertNode(root, 0, "d", &err);
	root = insertNode(root, 6, "e", &err);
	root = insertNode(root, 11, "f", &err);
	root = insertNode(root, -1, "g", &err);
	root = insertNode(root, 1, &lukas, &err);
	root = insertNode(root, 2, "i", &err); 
	root = insertNode(root, 2, "i", &err);   

	printf("%d\n", err);

	root = deleteNode(root, 10, &err2);

	printf("%d\n", err2);

	root = deleteNode(root, 10, &err2);

	printf("%d\n", err2);

	int size = avlSize(root);
	int array1[size];
	int array2[size];
	int array3[size];

	preOrder(array1, root);
	inOrder(array2, root);
	postOrder(array3, root);

	avl newNode = findNode(root, 1);    
	struct zmogus* z;
	z = newNode->data;

	printf("%d %s\n", z->height, z->vardas);

	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", array3[i]);
	}

	return 0;*/

	avl root = NULL;
	int err;

	root = insertNode(root, 8, "aaa", &err);
	root = insertNode(root, 4, "bbb", &err);
	root = insertNode(root, 12, "c", &err);
	root = insertNode(root, -2, "ddd", &err);
	root = insertNode(root, 0, "eeeee", &err);
	root = insertNode(root, 7, "ffff", &err);
	root = insertNode(root, 3, "i", &err);
	root = insertNode(root, 10, "ggg", &err);
	root = insertNode(root, 1, "aaa",&err);
	root = insertNode(root, 3, "i", &err);
}
