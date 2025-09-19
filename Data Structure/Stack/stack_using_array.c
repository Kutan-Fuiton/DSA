#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int* arr;
};

// Time complexity of isEmpty and isFull is O(1)
int isEmpty(struct Stack* ptr){
    if (ptr->top == -1){
        printf("Stack is empty\n");
        return 1;
    }
    else{
        printf("Stack is not empty\n");
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


int main() {
    // struct Stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size * sizeof(int));

    struct Stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

    // Pushing an element manually
    // s->arr[0] = 7;
    // s->top++;

    // Check if stack is empty
    // if(isEmpty(s)){
    //     printf("Stack is empty\n");
    // }
    // else{
    //     printf("Stack is not empty\n");
    // }
    isEmpty(s);
    
    return 0;
}