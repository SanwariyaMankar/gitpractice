#include <stdio.h>
#include <stdlib.h>
 
// A binary tree node has data, pointer to left child
// and a pointer to right child
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
// Given a binary tree, print its nodes in inorder

 void preorder(struct node* node) {
 if (node != NULL) {
 printf("%d ", node->data);
 postorder(node->left);
 postorder(node->right);
 }
}void postorder(struct node* node) {
 if (node != NULL) {
 preorder(node->left);
 preorder(node->right);
 printf("%d ", node->data);
 }
}void traverse(struct node* node)
 {
 if (node != NULL) {
 if (node->data % 2 == 1) {
 preorder(node);
 }
 else {
 postorder(node);
 }
 }
}

// Driver code
int main()
{
    struct node* root = newNode(19);
    root->left = newNode(7);
    root->right = newNode(9);
    root->left->left = newNode(1);
    root->left->right = newNode(13);
    root->left->left->left=newNode(23);
    root->left->left->right=newNode(25);
    root->right->left=newNode(24);
    root->right->right=newNode(21);
 
    // Function call
    printf("Inorder traversal of binary tree is \n");
    traverse(root);
 
    getchar();
    return 0;
}
