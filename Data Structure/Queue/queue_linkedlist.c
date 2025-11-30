#include<stdio.h>
#include<stdlib.h>


struct Node * f = NULL;
struct Node * r = NULL;

struct Node {
    int data;
    struct Node* next;
};

void linkedLIstTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf(" %d -->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

void enqueue(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL){
        printf("Queue Overflow!\n");
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL){
            f = r = n;
        } else {
            r->next = n;
            r = n;
        }
        printf("Enqueued %d to queue\n", val);
    }
}

int dequeue(){
    int val = -1;
    struct Node * n = f;
    if (f == NULL){
        printf("Queue Underflow!\n");
    } else {
        f = f->next;
        val = n->data;
        free(n);
        printf("Dequeued %d from queue\n", val);
    }
    return val;
}

int main(){
    linkedLIstTraversal(f);
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    linkedLIstTraversal(f);
    dequeue();
    linkedLIstTraversal(f);

    return 0;
}