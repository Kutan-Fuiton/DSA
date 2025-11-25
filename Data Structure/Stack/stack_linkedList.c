// stack using linked List
// |7 |
// |15|
// |18|
// |28|
// ____

// LinkedList:-
// 7 -> 15 -> 18 -> 28 -> NULL



#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// changes the representation of linked list a little bit...
void linkedLIstTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf(" %d -->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

int isEmpty(struct Node * top){
    if (top == NULL){return 1;} else {return 0;}
}

int isFull(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL){return 1;}else{return 0;}
}

struct Node * push(struct Node * top, int x){
    if (isFull(top)){
        printf("Stack Overflow!\n");
    } else {
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node ** top){
    if (isEmpty(*top)){
        printf("Stack Underflow!");
    } else {
        struct Node * n = *top;
        *top = (*top)->next;
        int val = n->data;
        free(n);
        return val;
    }
}

int peek(struct Node * top, int pos){
    struct Node * ptr = top;
    for (int i = 0; (i < pos-1 && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if (ptr != NULL){
        return ptr->data;
    } else {
        printf("peek operation failed!\n");
        return -1;
    }
}

int stackTop(struct Node * head){
    return head->data;
}

int stackBottom(struct Node * head){
    struct Node * ptr = head;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){
    struct Node * top = NULL;

    // top = push(top, 78);
    // top = push(top, 7);
    // top = push(top, 8);
    // top = push(top, 9);
    // top = push(top, 23);
    // top = push(top, 47);

    linkedLIstTraversal(top);

    printf("element which is peeked: %d\n", peek(top, 2));
    printf("Top of the stack is %d\n", stackTop(top));
    printf("Bottom of the stack is %d\n", stackBottom(top));
    printf("popped %d from linked list\n", pop(&top)); // --> Here's the catch, we need to send address of top variable, just because the change of top variable happening inside the function but change is not returned in the function, but we have to reflect it inside the main, so for that will send address to the function, without sending the pointer directly...
    
    linkedLIstTraversal(top);
    return 0;
}
