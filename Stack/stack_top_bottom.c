#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int* arr;
};

int isEmpty(struct Stack* ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Stack* ptr){
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Overflow! Cannot pop from the stack\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack* ptr, int i){
    int arrayInd = ptr->top - i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    } else {
        return ptr->arr[arrayInd];
    }
}

int stackTop(struct Stack* ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct Stack* ptr){
    return ptr->arr[0];
}


int main() {
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 1); // 11
    push(sp, 23); // 10
    push(sp, 44); // 9
    push(sp, 96); // 8
    push(sp, 76); // 7
    push(sp, 46); // 6
    push(sp, 55); // 5
    push(sp, 63); // 4
    push(sp, 36); // 3
    push(sp, 6); // 2
    push(sp, 75); // 1

    printf("The topmost value of this stack is %d\n", stackTop(sp));
    printf("The bottommost value of this stack is %d\n", stackBottom(sp));
    
    return 0;
}