// DEqueue is basically Double Ended Queue where insertion and deletion can be done from both front and rear ends. it follows both FIFO and LIFO principles. That's it...

#include<stdio.h>
#include<stdlib.h>

struct Deque {
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct Deque *q){
    if (q->f == -1 && q->r == q->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Deque *q){
    if (q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueueL(struct Deque* q, int val) {
    if (isFull(q)){
        printf("Deque Overflow!\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued %d to Deque\n", val);
    }
}

void enqueueF(struct Deque* q, int val) {
    if (isFull(q)){
        printf("Deque Overflow!\n");
    } 
    else if (q->f == -1) {
        printf("Cannot enqueue at front in current implementation!\n");
    } else {
        q->arr[q->f] = val;
        q->f--;
        printf("Enqueued %d to Deque\n", val);
    }
}

int dequeueF(struct Deque* q){
    int a = - 1;
    if (isEmpty(q)){
        printf("Deque Underflow!\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int dequeueL(struct Deque* q){
    int a = - 1;
    if (isEmpty(q)){
        printf("Deque Underflow!\n");
    } else {
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

int main() {
    struct Deque * q = (struct Deque*)malloc(sizeof(struct Deque));
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    if (isEmpty(q)){printf("Deque is empty\n");}
    if (isFull(q)){printf("Deque is full\n");}

    // 1. Enqueue few elements into Last
    enqueueL(q, 1);
    enqueueL(q, 2);
    enqueueL(q, 3);
    enqueueL(q, 4);

    if (isEmpty(q)){printf("Deque is empty\n");}
    if (isFull(q)){printf("Deque is full\n");}
    printf("--------------------------\n");
    
    // 2. Dequeue few elements from First
    printf("dequeued %d from Deque\n", dequeueF(q));
    printf("dequeued %d from Deque\n", dequeueF(q));
    
    if (isEmpty(q)){printf("Deque is empty\n");}
    if (isFull(q)){printf("Deque is full\n");}
    printf("--------------------------\n");
    
    // 3. Enqueue few elements into First
    enqueueF(q, 1);
    enqueueF(q, 2);
    
    if (isEmpty(q)){printf("Deque is empty\n");}
    if (isFull(q)){printf("Deque is full\n");}
    printf("--------------------------\n");
    
    // 4. Dequeue few elements from Last
    printf("dequeued %d from Deque\n", dequeueL(q));
    printf("dequeued %d from Deque\n", dequeueL(q));
    
    if (isEmpty(q)){printf("Deque is empty\n");}
    if (isFull(q)){printf("Deque is full\n");}
    printf("--------------------------\n");

    // 5. Enqueue few elements into Last
    enqueueL(q, 3);
    enqueueL(q, 4);

    if (isEmpty(q)){printf("Deque is empty\n");}
    if (isFull(q)){printf("Deque is full\n");}

    return 0;
}