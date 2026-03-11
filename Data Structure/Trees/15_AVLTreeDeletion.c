#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node * left;
    struct Node * right;
    int height;    // ---> only for checking the balance factor
};

// ----------- UTILITY FUNCTIONS ----------------

int getHeight(struct Node *n){
    if (n == NULL) return 0;
    return n->height;
}

int max(int a, int b){
    return a > b ? a : b;
}

struct Node *createNode(int key){
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node * n){
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

void preOrder(struct Node * root){
    if (root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//  ------------END------------

//       y                                x
//      / \        ------------->        / \ 
//     /   \       (Right Rotate)       /   \ 
//    x    T3                          T1    y
//   / \            (Left Rotate)           / \ 
//  /   \          <-------------          /   \ 
// T1   T2                                T2   T3 

struct Node * rightRotate(struct Node *y){
    struct Node * x = y->left;
    struct Node * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node * leftRotate(struct Node *x){
    struct Node * y = x->right;
    struct Node * T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct Node *insert(struct Node* node, int key){
    // normal BST insertion
    if (node == NULL)
        return  createNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // setting the balancefactor
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
 
    // Left Left Case
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}

struct Node* delete(struct Node* root, int key) {

    // Normal BST deletion
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);

    else if(key > root->key)
        root->right = delete(root->right, key);

    else {   
        if((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;
            if(temp == NULL) {   //  no child node
                temp = root;
                root = NULL;
            }
            else                 //  one child node
                *root = *temp;

            free(temp);          // delete root, or left of root or right of root node
        }
        else {                   // Two child node and in this verse, we doing that inorder successor stuff

            // finding the leftmost element of right subtree
            struct Node* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;

            // root becomes that temp
            root->key = temp->key;

            // and delete that temp node from there
            root->right = delete(root->right, temp->key);
        }
    }

    // If ballenceFactor get disturbed then just have to do avl tree thing
    if(root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    if(bf > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if(bf < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if(bf > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(bf < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main (){
    struct Node * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    
    printf("\n");
    
    root = delete(root, 2);
    root = delete(root, 6);
    preOrder(root);
    return 0;
}