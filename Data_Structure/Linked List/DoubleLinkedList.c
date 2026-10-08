//  NULL <-- |prev|data|next| <--> |prev|data|next| <--> |prev|data|next| <--> |prev|data|next| --> NULL
//           |    Node 1    |      |    Node 2    |      |    Node 3    |      |    Node 4    |

// This is double linked list, which have prev pointer, which points previous node


#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void print(struct Node * head){
    struct Node * ptr = head;
    while(ptr->next != NULL){
        printf(" %d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d --> ", ptr->data);
    printf(" NULL\n");
    while(ptr != NULL){
        printf(" %d -->", ptr->data);
        ptr = ptr->prev;
    }
    printf(" NULL\n");
}

void print_list(struct Node * head){
    struct Node * ptr = head;
    printf(" NULL <--");
    while(ptr->next != NULL){
        printf(" %d <-->", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d --> NULL", ptr->data);
}

int main() {
    struct Node * n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 10;
    n1->next = n2;
    n1->prev = NULL;

    n2->data = 20;
    n2->next = n3;
    n2->prev = n1;

    n3->data = 30;
    n3->next = n4;
    n3->prev = n2;

    n4->data = 40;
    n4->next = NULL;
    n4->prev = n3;

    print(n1);
    print_list(n1);

    
    return 0;
}