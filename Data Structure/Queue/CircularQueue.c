// Drawbacks of linear queue using Arrays:
// --> Space is not utilized efficiently. Once the queue is full, even if there are empty spaces at the front due to dequeued elements, new elements cannot be added.

// General idea of Circular Queue:
// Indices:-  ... | size-1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7  | ... | size-1 | 0 | 1 | 2 | 3 | 4 | 5  | 6 | 7  | ... | size-1 | ...
//                    ^                          ^                    ^                                                ^
//                    f                          r                    f                                                f
// in the upper representation, there are not multiple f, there is only one f and one r, but the array is considered circularly, so after size-1, it goes back to 0 index.

// Indices:-  ... | size-1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... | size - 2 | size-1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... | size - 2 | size-1 | ...
//                    ^                                          ^          ^                                                      ^
//                    f                                          r          f                                                      f
// At this point, the circular queue is full, because if we try to add one more element, r will overlap with f, which indicates that the queue is empty. So that means, we have to stop one position before f to indicate that the queue is full.

// Indices:-  ... | size-1 |   |   |   | 3 | 4 | 5 | 6 | ... | size - 2 | size-1 |   |   |   | 3 | 4 | 5 | 6 | ... | size - 2 | size-1 | ...
//                                   ^                                      ^              ^                                                      
//                                   f                                      r              f                                                      
// f position is always empty, u can move r upto position before f

// Less try another clear representation:

//          f    r
//          \/   \/
//           7   0   1
//           6       2
//           5   4   3

// Always front and rear in circular queue is 0.


#include<stdio.h>
#include<stdlib.h>

struct CircularQueue {
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct CircularQueue *q){
    if ((q->r+1) % q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *q){
    if (q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue* q, int val) {
    if (isFull(q)){
        printf("Queue Overflow!\n");
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued %d to queue\n", val);
    }
}

int dequeue(struct CircularQueue* q){
    int a = - 1;
    if (isEmpty(q)){
        printf("Queue Underflow! ");
    } else {
        q->f = (q->f+1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    struct CircularQueue * q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->size = 4;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size * sizeof(int));
    
    if (isEmpty(q)){printf("Queue is empty\n");}
    if (isFull(q)){printf("Queue is full\n");}

    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 13);
    // enqueue(q, 14);

    if (isEmpty(q)){printf("Queue is empty\n");}
    if (isFull(q)){printf("Queue is full\n");}
    
    // Dequeue few elements
    printf("Dequeued %d from queue\n", dequeue(q));
    printf("Dequeued %d from queue\n", dequeue(q));
    printf("Dequeued %d from queue\n", dequeue(q));
    
    if (isEmpty(q)){printf("Queue is empty\n");}
    if (isFull(q)){printf("Queue is full\n");}

    return 0;
}