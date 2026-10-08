// Binary Search Tree (BST)


// It is a type of binary tree. But is it a BST? Both are different, less see the properties of BST...
//      7
//     / \ 
//    11  6

// Properties of BST:- 
// 1. All nodes of the left subtree are lesser than root.
// 2. All nodes of the right subtree are greater than root.
// 3. Left and Right Subtrees are also BST.
// 4. There are no duplicates nodes.

// So above tree is not BST...

//          9
//         / \ 
//        /   \ 
//       /     \ 
//      4      11
//     / \       \
//    /   \       \
//   2     7      15
//        / \     /
//       5   8   14

// Continuing the Properties of BST:-
// 5. InOrder Traversal of BST, gives an ascending sorted array

// So above tree is a Binary Search Tree (BST)...

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

void inOrder(struct node * root){
    if (root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

int main() {
    struct node * p = createNode(5); 
    struct node * p1 = createNode(3); 
    struct node * p2 = createNode(6); 
    struct node * p3 = createNode(1); 
    struct node * p4 = createNode(4); 

    // Finally it will look like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1; 
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p); 
    printf("\n%d", isBST(p));   
    
    return 0;
}