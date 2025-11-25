#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void print(struct Node * head){
    while(head != NULL){
        printf(" %d -->", head->data);
        head = head->next;
    }
    printf(" NULL\n");
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

    struct Node * head1 = second;
    print(head1->next);
    
    return 0;
}