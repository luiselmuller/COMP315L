//Code Taken from https://www.tutorialspoint.com/binary-search-tree-search-and-insertion-operations-in-cplusplus

#include<stdio.h>
#include<stdlib.h>
struct node {
    int key;
    struct node* left, * right;
};
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void traversetree(struct node* root) {
    if (root != NULL) {
        traversetree(root->left);
        printf("%d \t", root->key);
        traversetree(root->right);
    }
}
struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}
struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}