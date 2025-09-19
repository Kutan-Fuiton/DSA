// Let's take expression: ([7-9}-7)
// If we represent in string array in C
// | ( | [ | 7 | - | } | - | 7 | ) | \0 |
// | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8  |
// Indexes of the array are shown below the characters.


#include<stdio.h>
#include<stdlib.h>

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

void push(struct Stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Overflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stackTop(struct Stack* ptr){
    return ptr->arr[ptr->top];
}

int match(char a, char b){
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

int parenthesisMatch(char * exp){
    struct Stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char popped_ch;

    for(int i = 0; exp[i]!='\0'; i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (isEmpty(sp)) return 0;
            popped_ch = pop(sp);
            if(!match(stackTop(sp), popped_ch )){
                return 0;
            }
        }
    }
    if(isEmpty(sp)) return 1;
    else return 0;

}

int main() {
    // char * exp = "8*(9";
    char * exp = "[4-6]((8){(9-8)})";

    if(parenthesisMatch(exp)){
        printf("The Paranthesis is Matching");
    }else{
        printf("The Paranthesis is not Matching");
    }

    return 0;
}