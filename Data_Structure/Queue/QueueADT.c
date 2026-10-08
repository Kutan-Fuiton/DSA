// Queue ADT Implementation in C

// 1A ------>  Queue is empty: f = r = -1
// Values :-      |   |   |   |   |   |   |   |   | ... |        |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... | size-1 |
//            ^ ^
//            f r


// 1B ------>  Queue is empty: f = r = size - 1
// Values :-      |   |   |   |   |   |   |   |   | ... |        |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... | size-1 |
//                                                          ^ ^
//                                                          f r


// 1C ------>  Queue is empty: f = r
// Values :-      |   |   |   |   |   |   |   |   | ... |        |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... | size-1 |
//                             ^ ^
//                             f r


// 2 ------>  Queue is started filling/insertion of elements/enqueue:  f = -1; r = 4, here r will be on the last element inserted
// Values :-      | 4 | 5 | 6 | 2 | 1 |   |   |   | ... |        |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... | size-1 |
//            ^                     ^
//            f                     r


// 3 ------>  Queue is full:  f = -1; r = size - 1, here r will be on the last element of the array
// Values :-      | 4 | 5 | 6 | 2 | 1 | 32 | 5 | 22 | ... |   55   |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5  | 6 | 7  | ... | size-1 |
//            ^                                               ^
//            f                                               r


// 4 ------>  Queue is started clearing from the first/deletion of elements/dequeue:  f = 3; r = size - 1, here r will be on the last element of the array and f will be on the last element deleted, right after f, the array will start having valid elements
// Values :-      |   |   |   |   | 1 | 32 | 5 | 22 | ... |   55   |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5  | 6 | 7  | ... | size-1 |
//                              ^                             ^
//                              f                             r


// 5 ------>  Queue is started filling and also some started deleting/both enqueue and dequeue:  f = 2; r = 6, here r will be on the last element inserted and f will be on the last element deleted, right after f, the array will start having valid elements
// Values :-      |   |   |   | 2 | 1 | 32 | 5 |    | ... |        |
// Indices:-   -1 | 0 | 1 | 2 | 3 | 4 | 5  | 6 | 7  | ... | size-1 |
//                          ^                ^
//                          f                r


// Initialising the queue data structure with size, front(f), rear(r) and array to store elements.
// at first the front and rear are at -1 position indicating that the queue is empty. -1 is an invalid index.




#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};

int main() {
    // This is normal representation
    // struct Queue q;
    // q.size = 100;
    // q.f = q.r = -1;
    // q.arr = (int*)malloc(q.size * sizeof(int));

    // This is pointer representation
    struct Queue * q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
    
    return 0;
}