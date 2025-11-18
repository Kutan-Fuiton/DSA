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

// 1. Deleting the first node:


// 2. Deleting a node in between:
int delete(struct Node* head, int index){
    struct Node * p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    struct Node * q = p->next;
    int del_val = q->data;
    p->next = q->next;
    free(q);

    return del_val;
}


// 3. Delete the last node:
int deletete(struct Node* head){
    struct Node * p = head;
    while (p != NULL){
        p = p->next;
    }
}


// 4. Delete a node with a given value:



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

    int val = delete(head, 2);

    printf("Linked list after insertion\n");
    linkedLIstTraversal(head);
    
    printf("The deleted value is %d\n", val);

    return 0;
}