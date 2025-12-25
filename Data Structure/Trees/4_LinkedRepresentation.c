#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node * createNode(int val){
    struct node * p = (struct node *) malloc(sizeof(struct node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main() {
    // // constructing the root node
    // struct node * p = (struct node *) malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;
    
    // // constructing the second node
    // struct node * p1 = (struct node *) malloc(sizeof(struct node));
    // p->data = 1;
    // p->left = NULL;
    // p->right = NULL;
    
    // // constructing the third node
    // struct node * p2 = (struct node *) malloc(sizeof(struct node));
    // p->data = 4;
    // p->left = NULL;
    // p->right = NULL;

    // // Linking the root node with left and right children
    // p->left = p1; 
    // p->right = p2;

    // Instead of creating so many lines for each node, we better make a function in the name of createNode with data as argument...


    
    struct node * p = createNode(2); // root node
    struct node * p1 = createNode(1); // 2nd node
    struct node * p2 = createNode(4); // 3rd node

    // Linking the root node with left and right children
    p->left = p1; 
    p->right = p2;
    
    return 0;
}