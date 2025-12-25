// A. Preorder Traversal:-  

//                           4                     
//                           |                             
//                -----------------------           
//                |                     |           
//                1                     6   
//                |
//        -----------------                  
//        |               |                   
//        5               2     

// ROOT --> LEFT --> RIGHT
// 4 -> [1 -> [5] -> [2]] -> 6      ------>  4 1 5 2 6


// B. Postorder Traversal:-  

//                           4                     
//                           |                             
//                -----------------------           
//                |                     |           
//                1                     6   
//                |
//        -----------------                  
//        |               |                   
//        5               2     

// LEFT --> RIGHT --> ROOT
// [] -> 6 -> 4
// [[5] -> [2] -> 1] -> 6 -> 4      ------> 5 2 1 6 4


// C. Inorder Traversal:-  

//                           4                     
//                           |                             
//                -----------------------           
//                |                     |           
//                1                     6   
//                |
//        -----------------                  
//        |               |                   
//        5               2     

// LEFT --> ROOT --> RIGHT
// [] -> 4 -> 6
// [[5] -> 1 -> [2]] -> 4 -> 6      ------> 5 1 2 4 6

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

void preOrder(struct node * root){
    if (root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node * root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node * root){
    if (root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct node * p = createNode(4); 
    struct node * p1 = createNode(1); 
    struct node * p2 = createNode(6); 
    struct node * p3 = createNode(5); 
    struct node * p4 = createNode(2); 


    // Linking the root node with left and right children
    p->left = p1; 
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);   // 4 1 5 2 6
    printf("\n");
    postOrder(p);  // 5 2 1 6 4
    printf("\n");
    inOrder(p);    // 5 1 2 4 6
    
    return 0;
}