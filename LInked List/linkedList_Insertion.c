#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedLIstTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("ELement: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// A function which returns a node pointer which is basically a structure pointer --> takes argument as the head pointer and data to be inserted --> dynamically allocates memory for a new node, sets its next to the current head and sets its data to the given data --> then returns the new node pointer which will be the new head of the linked list
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


// A function which returns a node pointer which is basically a structure pointer --> takes argument as the head pointer and data to be inserted --> dynamically allocates memory for a new node, sets its next to the current head and sets its data to the given data --> then returns the new node pointer which will be the new head of the linked list
struct Node * insertAtFirst(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index-1){
        p = p->next;
        i++;
    }
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Alocate memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 1;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    linkedLIstTraversal(head);

    
    return 0;
}