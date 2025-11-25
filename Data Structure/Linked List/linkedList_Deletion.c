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

// 1. Deleting the first node: A function which returns a node pointer which is basically a structure pointer --> make a temporary node and assign head node to it temporarily --> then assignt the head's next to head, then current head will change to next node of the head --> now, you can delete the temporary node where the previous head node was stored, i.e., u can free that pointer --> then returns the new head of the linked list...
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


// 2. Deleting at a given Index: A function which returns a node pointer which is basically a structure pointer --> make a temporary node and assign head node to it temporarily --> make another temporary node and assign head's next node to it temporarily --> then a for loop will execute from i = 0 to before index - 1, i.e., index - 2 --> in that iteration, the p and q both will move forward till i reached index - 2 --> at that moment, q will be on the node that will be deleted, and p will be on node before that deleted node --> now, p's next will point to q's next and will free the q --> then returns the head of the linked list...
struct Node * deleteAtIndex(struct Node* head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index - 1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}


// 3. Delete the last node: Deleting at a given Index: A function which returns a node pointer which is basically a structure pointer --> make a temporary node and assign head node to it temporarily --> make another temporary node and assign head's next node to it temporarily --> then a while loop will execute untill the q's next point to null --> at that moment, q will be on the node that will be deleted which is last node, and p will be on node before last node --> now, p's next will point to NULL and will free the q --> then returns the head of the linked list...
struct Node * deleteLast(struct Node* head){
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}


// 4. Delete a node with a given value: A function which returns a node pointer which is basically a structure pointer --> make a temporary node and assign head node to it temporarily --> make another temporary node and assign head's next node to it temporarily --> then a while loop will execute until it encounter the q's data as the give value and also have to check, whether the q's next node reached to null or not (beacause if the value isnt in the linked list, the loop will iterate for eternity) --> in that iteration, the p and q both will move forward till the condition become false --> at that moment, q will be on the node that will be deleted, and p will be on node before that deleted node --> but here's a catch, if q reached the last node, then it's next will become null and the condition will become false, but we will not about last node's value is equal to given value or not, so for that, a if condition will given after the while loop, to check whether q's data is equal to value or not, if its yess --> now, p's next will point to q's next and will free the q --> then returns the head of the linked list...
struct Node * deleteAtValue(struct Node* head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }

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
    head->data = 7;
    head->next = second;

    // Link second and third node
    second->data = 11;
    second->next = third;

    // Link third and fourth node
    third->data = 41;
    third->next = fourth;

    // Link fourth and fifth node
    fourth->data = 66;
    fourth->next = fifth;

    // Terminate the list at the fifth node
    fifth->data = 32;
    fifth->next = NULL;

    printf("Linked list before insertion\n");
    linkedLIstTraversal(head);

    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteLast(head);
    // head = deleteAtValue(head, 66);

    printf("Linked list after insertion\n");
    linkedLIstTraversal(head);

    return 0;
}