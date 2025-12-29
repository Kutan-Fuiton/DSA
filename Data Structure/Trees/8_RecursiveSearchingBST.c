// Searching in Binary Search Tree

// Below Tree is BST, have to search 55(let, val) in this... 

//           50
//          / \ 
//         /   \ 
//        /     \ 
//       /       \ 
//      40       60
//     / \      /  \
//    /   \    /    \
//   20   45  55    70

// First will check, the val >,=,< to root element, here 55 > 50, so we will only search it inside right subtree...

//     60
//    / \
//   /   \
//  55   70

// same for this, will check, the val >,=,< to root element, here 55 < 60, so we will only search it inside left subtree...

//     55
//    / \
//   /   \
// NULL  NULL

// same for this, will check, the val >,=,< to root element, here 55 = 55, so that element exists in the BST...

// In worst case, comparison will be equal to height of the tree, here height of the tree is 3, so did 3 comparisons

// Time complexity of binary search tree best case:- O(logn) and worst case:- O(n), worst case is O(n) when its a left or right skewed tree

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

struct node * search (struct node * root, int key){
    if (root == NULL){
        return NULL;
    }
    
    if (key == root->data){
        return root;
    }
    else if (key < root->data){
        return search (root->left, key);
    }
    else {
        return search (root->right, key);
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

    struct node* n = search(p, 5);
    if(n!=NULL){
        printf("Found: %d", n->data);
    }else{
        printf("Element Not Found!");
    }
    
    return 0;
}
