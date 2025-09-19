// Stack Abstract Data Type (ADT) implementation in C. Stack is a linear data structure / collection of items that follows the Last In First Out (LIFO) principle. An element can be pushed in this basket type container and popped out from it. We have different methods to implement stack like using arrays, linked lists etc. Here we are implementing stack using arrays. basic operations of stack are push, pop, peek, isEmpty, isFull and display.

// 1. Fixed Size Array Creation
// 2. Top Element

// Actual pointing in stack is done by top variable. Initially it is -1 because stack is empty. The  first element will be pushed at index 0 and then top will be incremented to 0. So, top always points to the last pushed element in stack. That's how it goes on.

#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int* arr;
};

int main() {
    struct Stack s;
    s.size = 80;
    s.top = -1;
    s.arr = (int*)malloc(s.size * sizeof(int));

    
    return 0;
}