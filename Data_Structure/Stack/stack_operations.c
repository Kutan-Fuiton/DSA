// Cannot Push if stack is full
// Cannot Pop if stack is empty
// s->top, here arrow operator is used because s is a pointer to structure. If s was a structure variable then we would have used dot operator like s.top. arrow operator is basically derefencing and then dot operator.


// Push Operation  ---->>> push(value)
// 1. Check if stack is full [using isFull function], so that we do not overflow the stack [stack overflow condition]
// 2. If not full, then increment the top variable to point to next index
// 3. Add the element to the array at that index
// 4. Nothing is returned

// Pop Operation  ---->>> pop()
// 1. Check if stack is empty [using isEmpty function], so that we do not underflow the stack [stack underflow condition]
// 2. If not empty, then access the element at index top from the array
// 3. Decrement the top variable to point to the previous index 
// 4. Return the popped element


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

// Time complexity of push and pop is O(1)
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


int main() {
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 1);
    push(sp, 23);
    push(sp, 44);
    push(sp, 96);
    push(sp, 76);
    push(sp, 46);
    push(sp, 55);
    push(sp, 63);
    push(sp, 36);
    push(sp, 6); // --> Pusher 10th element
    push(sp, 46); // --> Stack Overflow! Cannot push 46 to the stack
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // --> Last In First Out
    printf("Popped %d from the stack\n", pop(sp)); // --> Last In First Out
    printf("Popped %d from the stack\n", pop(sp)); // --> Last In First Out
    printf("Popped %d from the stack\n", pop(sp)); // --> Last In First Out
    
    return 0;
}