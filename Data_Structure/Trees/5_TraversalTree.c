// In linear data structure, traversal means, either iterating or moving from left to right or right to left, like in array, we can traverse from right to left or left to right...

// But in non linear data structure, we have different types of traversal:-


// A. Preorder Traversal:-                         |                               7
// First root --> left subtree --> right subtree   |                               |
//                                                 |                     -----------------------
// B. Postorder Traversal:-                        |                     |                     | 
// left subtree --> right subtree --> Root         |                     2                     3 
//                                                 |                     |                     | 
// C. Inorder Traversal:-                          |             ---------                     ---------
// left subtree --> Root --> right subtree         |             |                                     |
//                                                 |             1                                     4


// A. Preorder Traversal:- 


// 7 [left subtree] [right subtree] 

// now have to do preorder traversal of left subtree and right subtree assuming them as a whole tree
// like for example here, left subtree :- 2[left subtree of left subtree][right subtree of left subtree] ---> here right part NULL
//             and here, right subtree :- 3[left subtree of right subtree][right subtree of right subtree] --> here left part NULL

// so they will become, left subtree:- 2[left subtree of left subtree]
//                     right subtree:- 3[right subtree of right subtree]

// Now the left subtree of left subtree is 1 [left part] [right part]   --> both part NULL --> so it will become only 1
// Now the right subtree of right subtree is 4 [left part] [right part]   --> both part NULL --> so it will become only 4

// so it became:- 7 [2 [1]] [3 [4]]       --> brackets are nothing just for concept and used as a seperation, if we remove the brackets

// 7 2 1 3 4  ---> this is the pre order traversal of the tree


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
    struct node * p = createNode(2); // root node
    struct node * p1 = createNode(1); // 2nd node
    struct node * p2 = createNode(4); // 3rd node

    // Linking the root node with left and right children
    p->left = p1; 
    p->right = p2;
    
    return 0;
}