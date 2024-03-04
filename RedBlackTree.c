#include <stdio.h>
#include <stdlib.h>
// Structure for a node of the Red-Black Tree
struct Node {
	int data;
 char color; // 'R' for red, 'B' for black
 struct Node* parent;
 struct Node* left;
 struct Node* right;
};
// Function to create a new node with given data
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 	newNode->data = data;
 	newNode->color = 'R'; // New nodes are always red
	newNode->parent = NULL;
 	newNode->left = NULL;
 	newNode->right = NULL;
 	return newNode;
}
// Function to perform left rotation on a node
void leftRotate(struct Node** root, struct Node* x) {
 	struct Node* y = x->right;
 	x->right = y->left;
 	if (y->left != NULL)
 		y->left->parent = x;
 		y->parent = x->parent;
 		if (x->parent == NULL)
 			*root = y;
 		else if (x == x->parent->left)
 			x->parent->left = y;
 		else
 			x->parent->right = y;
 			y->left = x;
 			x->parent = y;
}
// Function to perform right rotation on a node
void rightRotate(struct Node** root, struct Node* y) {
 	struct Node* x = y->left;
 	y->left = x->right;
 	if (x->right != NULL)
 		x->right->parent = y;
 		x->parent = y->parent;
 	if (y->parent == NULL)
 		*root = x;
 	else if (y == y->parent->left)
 		y->parent->left = x;
 	else
 		y->parent->right = x;
 	x->right = y;
 	y->parent = x;
}
// Function to fix the Red-Black Tree after insertion
void fixInsert(struct Node** root, struct Node* z) {
 	while (z->parent != NULL && z->parent->color == 'R') {
 		if (z->parent == z->parent->parent->left) {
 			struct Node* y = z->parent->parent->right;
 		if (y != NULL && y->color == 'R') {
 			z->parent->color = 'B';
 			y->color = 'B';
 			z->parent->parent->color = 'R';
 			z = z->parent->parent;
	} else {
 		if (z == z->parent->right) {
 			z = z->parent;
 			leftRotate(root, z);
 		}
 		z->parent->color = 'B';
 		z->parent->parent->color = 'R';
 		rightRotate(root, z->parent->parent);
 }
} else {
 // Symmetric case
 // Implementation is similar with "left" and "right" exchanged
 	struct Node* y = z->parent->parent->left;
 	if (y != NULL && y->color == 'R') {
 		z->parent->color = 'B';
 		y->color = 'B';
 		z->parent->parent->color = 'R';
 		z = z->parent->parent;
 	} else {
 		if (z == z->parent->left) {
 			z = z->parent;
 			rightRotate(root, z);
 	}
 	z->parent->color = 'B';
 	z->parent->parent->color = 'R';
 	leftRotate(root, z->parent->parent);
 	}
 	}
 }
 	(*root)->color = 'B';
}
// Function to insert a value into the Red-Black Tree
void insert(struct Node** root, int data) {
 // Standard BST insertion
 	struct Node* z = createNode(data);
 	struct Node* y = NULL;
 	struct Node* x = *root;
 	while (x != NULL) {
 		y = x;
 		if (z->data < x->data)
 			x = x->left;
 		else
 			x = x->right;
 	}
 	z->parent = y;
 	if (y == NULL)
 		*root = z;
 	else if (z->data < y->data)
 		y->left = z;
 	else
 		y->right = z;
 // Fix the Red-Black Tree properties after insertion
 	fixInsert(root, z);
}
// Function to print the Red-Black Tree (in-order)
void inOrderTraversal(struct Node* root) {
 	if (root != NULL) {
 		inOrderTraversal(root->left);
 		printf("%d (%c) ", root->data, root->color);
 		inOrderTraversal(root->right);
 	}
}
// Function to print the Red-Black Tree (pre-order)
void preOrderTraversal(struct Node* root) {
 	if (root != NULL) {
 		printf("%d (%c) ", root->data, root->color);
 		preOrderTraversal(root->left);
 		preOrderTraversal(root->right);
 	}
}
// Function to print the Red-Black Tree (post-order)
void postOrderTraversal(struct Node* root) {
 	if (root != NULL) {
 		postOrderTraversal(root->left);
 		postOrderTraversal(root->right);
 		printf("%d (%c) ", root->data, root->color);
 	}
}
// Driver program for testing the Red-Black Tree implementation
int main() {
 	struct Node* root = NULL;
 // Insert values into the Red-Black Tree
 	int values[] = {10, 20, 30, 15, 25, 5};
 	int numValues = sizeof(values) / sizeof(values[0]);
 	for (int i = 0; i < numValues; i++) {
 		insert(&root, values[i]);
 	}
 // Print the Red-Black Tree traversals
 	printf("In-Order Traversal: ");
 	inOrderTraversal(root);
 	printf("\n");
 	printf("Pre-Order Traversal: ");
 	preOrderTraversal(root);
 	printf("\n");
 	printf("Post-Order Traversal: ");
 	postOrderTraversal(root);
 	printf("\n");
 	return 0;
}