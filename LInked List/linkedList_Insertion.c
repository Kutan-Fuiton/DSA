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
    ptr->data = data;

    ptr->next = head;
    return ptr;
}


// A function which returns a node pointer which is basically a structure pointer --> takes argument as the head pointer, data to be inserted and the index position where the node to be inserted --> dynamically allocates memory for a new node -->making the temporary node (structure node pointer) and assign the head, so that it can traverse with reference head --> then a while loop will execute from 0 to index - 2, which is to iterate the temporary node over the chain of nodes, i.e., linked list to the index i-1 --> after temp node getting to index - 1 position, extra node's data will be assign the data given by argument, and its next will point to temp node's next, and that temp node will point to extra node --> then returns the new node pointer which will be the new head of the linked list (will return the same thing in every case, that is head)
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}



struct Node * insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL){
        p = p->next;
    }
    p-> next = ptr;
    ptr->next = NULL;
    return head;
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

    printf("Linked list before insertion\n");
    linkedLIstTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    head = insertAtEnd(head, 56);
    printf("Linked list after insertion\n");
    linkedLIstTraversal(head);

    
    return 0;
}