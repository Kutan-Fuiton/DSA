#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedLIstTraversal(struct Node *head){
    struct Node * ptr = head;
    do{
        printf(" %d -->", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf(" HEAD\n");
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    // Alocate memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 4;
    head->next = second;

    // Link second and third node
    second->data = 3;
    second->next = third;

    // Link third and fourth node
    third->data = 6;
    third->next = fourth;

    // link fourth and head node
    fourth->data = 1;
    fourth->next = head;

    // // Terminate the list at the fifth node
    // fifth->data = 32;
    // fifth->next = NULL;

    printf("Circular Linked list before insertion\n");
    linkedLIstTraversal(head);

    head = insertAtFirst(head, 80);

    printf("Circular Linked list after insertion\n");
    linkedLIstTraversal(head);

    return 0;
}