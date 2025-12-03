#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct {
    int size;
    int f;
    int r;
    int* arr;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->size = k + 1;
    obj->f = obj->r = 0;
    obj->arr = (int*)malloc(obj->size * sizeof(int));
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->r == obj->f){
        return true;
    } else {
        return false;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->r + 1) % obj->size == obj->f){
        return true;
    } else {
        return false;
    }
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)){
        return false;
    } else {
        obj->r = (obj->r + 1) % obj->size;
        obj->arr[obj->r] = value;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)){
        return false;
    } else {
        obj->f = (obj->f + 1) % obj->size;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)){
        return -1;
    } else {
        return obj->arr[(obj->f + 1) % obj->size];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)){
        return -1;
    } else {
        return obj->arr[obj->r];
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/

int main() {
    MyCircularQueue* q = myCircularQueueCreate(3);
    
    myCircularQueueEnQueue(q, 1);
    myCircularQueueEnQueue(q, 2);
    printf("F:%d R:%d\n", myCircularQueueFront(q), myCircularQueueRear(q));
    
    myCircularQueueDeQueue(q);
    printf("After dequeue: F:%d Full:%d\n", myCircularQueueFront(q), myCircularQueueIsFull(q));
    
    myCircularQueueFree(q);
    return 0;
}