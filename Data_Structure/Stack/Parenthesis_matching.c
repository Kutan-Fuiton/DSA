// Let's take expression: 3*2-(8+1)
// If we represent in string array in C
// | 3 | * | 2 | - | ( | 8 | + | 1 | ) | \0 |
// | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9  |
// Indexes of the array are shown below the characters
// Now, we will traverse the array from index 0 to index 8 (i.e till we reach '\0')
// Whenever we encounter an opening parenthesis '(', we will push it in stack   
// Whenever we encounter a closing parenthesis ')', we will pop an element from the stack
// In the end, if stack is empty, then we can say that parenthesis are balanced

// Conditions for balanced parenthesis
// 1. While popping, if stack is already empty, then parenthesis are not balanced
// 2. In the end, if stack is not empty, then also parenthesis are not balanced

// For Example: (**(*(**)***)
// First opening paranthesis traversed and push it in stack, second opening paranthesis traversed and push it in stack, third opening paranthesis traversed and push it in stack, first closing paranthesis traversed and pop an element from stack, second closing paranthesis traversed and pop an element from stack. In the end, one opening paranthesis is still remaining in stack. So, parenthesis are not balanced

// Homework Example: 7-(8(3*9)+11+12))-8)
// i) Whether the parenthesis are balanced or not?
// ii) How many push pop operation needed to be done?
// iii) Time Complexity: Worst case and best case complexity




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

int parenthesisMatch(char * exp){
    struct Stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for(int i = 0; exp[i]!='\0'; i++){
        if (exp[i] == '('){
            push(sp, exp[i]);
        }
        else if (exp[i] == ')'){
            if (isEmpty(sp)) return 0;
            pop(sp);
        }
    }
    if(isEmpty(sp)) return 1;
    else return 0;

}

int main() {
    // char * exp = "8*(9";
    char * exp = "7-(8(3*9)+11+12))-8)";

    if(parenthesisMatch(exp)){
        printf("The Paranthesis is Matching");
    }else{
        printf("The Paranthesis is not Matching");
    }

    return 0;
}



























