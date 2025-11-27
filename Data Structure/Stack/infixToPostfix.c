#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
    int size;
    int top;
    char* arr;
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

int stackTop(struct Stack* ptr){
    return ptr->arr[ptr->top];
}

int precedence(char ch){
    if (ch == '*' || ch == '/'){
        return 3;
    } else if(ch == '+' || ch == '-'){
        return 2;
    } else {
        return 0;
    }
}

int isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){return 1;}else{return 0;}
}

char * InToPo(char * infix){
    struct Stack * sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc((sp->size) * sizeof(char));
    char * postfix = (char *)malloc(strlen(infix)+1 * sizeof(char));
    int i = 0;  // Track Infix Traversal
    int j = 0;  // Track Postfix addition
    while (infix[i]!='\0'){
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            if (precedence(infix[i])>precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            } else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char * exp = "a-b";
    printf("postfix is %s", InToPo(exp));

    return 0;
}