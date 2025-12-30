// Deletion in Binary Search Tree

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


// there could be three cases,
// Case 1:- The node is a leaf node
// Case 2:- The node is a non leaf node
// Case 3:- The node is the root node [here deleting root node doesnt mean only top node, it will applicable to other nodes which
//                                    have its own subtree going down]
// Case 4:- If there is no node that is to be deleted


// Case 1:-  Deleting 1
//           check 1 < 8, so left subtree...
//           check 1 < 3, so again left subtree...
//           check 1 = 1, so this node will get deleted... 
//           There will be no change in any other thing, everything will go as it is...

// Case 2:-  Deleting 6
//           check 6 < 8, so left subtree...
//           check 6 > 3, so again left subtree...
//           check 6 = 6, now we cant delete this node normally, cuzz this node have further children connected... 
// have to check inorder pre and inorder post of 6... now what is that, so let do the inorder traversal first...
// InOrder Traversal:- 1 3 4 6 7 8 10 13 14
// Now you can see the deleted element 6, so 4 is inorder pre of 6, and 7 is inorder post of 6...
// So we can replace 6 with inorder pre (4) or inorder post (7)...
// if we replace 6 with 7, then also in left subtree 4 < 7... and if we replace 6 with 4, then also in right subtree 7 > 4

// Case 3:- Deleting 8 
//          First, Search for node
//          Second, Search for InOrder pre or InOrder post [7 & 10 here]
//          Third, keep doing until the tree has no empty nodes
//          nOrder Traversal:- 1 3 4 6 7 8 10 13 14


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

// code for finding inorderpredecessor of root node
struct node * inOrderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node * deleteNode(struct node *root, int val){
    struct node* iPre;
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    // Search for the node that to be deleted
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data){
        root->right = deleteNode(root->right, val);
    } 

    // Deletion strategy, here (val = root->data)
    else {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main() {
    struct node * p = createNode(5); 
    struct node * p1 = createNode(3); 
    struct node * p2 = createNode(7); 
    struct node * p3 = createNode(1); 
    struct node * p4 = createNode(4); 
    struct node * p5 = createNode(6); 
    struct node * p6 = createNode(8); 

    // Finally it will look like this:
    //        5
    //       / \
    //      /   \
    //     /     \
    //    3       7
    //   / \     / \
    //  1   4   6   8

    // Linking the root node with left and right children
    p->left = p1; 
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    inOrder(p);
    deleteNode(p, 5);
    printf("\n");
    printf("Root is %d \n", p->data);
    printf("left root is %d \n", p->left->data);
    printf("right root is %d \n", p->right->data);
    printf("left root of left root is %d \n", p->left->left->data);
    // printf("right root of left root is %d \n", p->left->right->data);
    printf("left root of right root is %d \n", p->right->left->data);
    printf("right root of right root is %d \n", p->right->right->data);
    inOrder(p);
    
    return 0;
}











