// Insertion in Binary Search Tree

// This is a binary search tree

//          8
//         / \ 
//        /   \ 
//       /     \  
//      3      10
//     / \       \
//    /   \       \
//   1     6      14
//        / \     /
//       4   7   13

// usually when we say to insert something in binary search tree, we dont need index, cuzz we know how bst works and it doesnt have any duplicates...

// For example:- inserting 9 to this tree...

// First check:- whether it is equal to root, greater than root or less than root, here 9 > 8, so greater than root, that means 9 will be inserted in right subtree...
// Second check:- whether it is equal to root, greater than root or less than root, here 9 < 10, so less than subroot, that means 9 will be inserted in left subtree of that tree... here right subtree of the 10 is null, so as soon as it reached null, instead of null we will point it into node value 9 and that's how it will get entered...

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

void insert(struct node* root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data){
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }else {
        prev->right = new;
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

    insert(p, 12);
    
    return 0;
}
