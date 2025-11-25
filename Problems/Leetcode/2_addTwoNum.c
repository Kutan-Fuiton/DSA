#include<stdio.h>
#include<stdlib.h>

// structure not to be pushed in leetcode
struct ListNode {
    int val;
    struct ListNode *next;
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */

// Helper Functions 0 --> not to be pushed in leetcode
void print(struct ListNode * head){
    while(head != NULL){
        printf(" %d -->", head->val);
        head = head->next;
    }
    printf(" NULL\n");
}
// Helper Functions 0 --> not to be pushed in leetcode 
struct ListNode * insertFront(struct ListNode * head, int val){
    struct ListNode * ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->next = head;
    ptr->val = val;
    head = ptr;
    return head;
}
// Helper Functions 0 --> not to be pushed in leetcode
struct ListNode * numToList(int num){
    struct ListNode * head = NULL;
    int temp = num;
    if (num != 0){
        while(temp != 0){
            head = insertFront(head, temp%10);
            temp = temp/10;
        }
    }
    else{
        head = insertFront(head, 0);
    }
    return head;
}


// Helper Functions 1
struct ListNode * insertFront(struct ListNode * head, int val){
    struct ListNode * ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->next = head;
    ptr->val = val;
    head = ptr;
    return head;
}


// Helper functions 2
struct ListNode * insertEnd(struct ListNode *head, int val){
    struct ListNode *ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = val;
    struct ListNode *p = head;
    while (p->next != NULL)
        p = p->next;
    p-> next = ptr;
    ptr->next = NULL;
    return head;
}


// Actual Logic
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0){
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        result = (result == NULL) ? insertFront(result, sum % 10) : insertEnd(result, sum % 10);
        carry = sum / 10;
    }
    return result;
}


int main(){
    struct ListNode * l1 = numToList(567);
    printf("l1 Linked List:-  \n");
    print(l1);
    struct ListNode * l2 = numToList(549);
    printf("l2 Linked List:-  \n");
    print(l2);

    struct ListNode * l3 = addTwoNumbers(l1, l2);
    printf("l3 Linked List:-  \n");
    print(l3);

    return 0;
}