#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
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

struct ListNode* reverseList(struct ListNode * head){
    struct ListNode * prev = NULL;
    struct ListNode * curr = head;
    struct ListNode * next = NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(struct ListNode* head) {
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode * reverse = slow->next;
    slow->next = NULL;
    reverse = reverseList(reverse);

    struct ListNode * ptr1 = head;
    struct ListNode * ptr2 = reverse;
    while (ptr2 != NULL){
        struct ListNode * temp1 = ptr1->next;
        struct ListNode * temp2 = ptr2->next;
        ptr1->next = ptr2;
        ptr2->next = temp1;
        ptr1 = temp1;
        ptr2 = temp2;
    }
}

int main() {
    struct ListNode * head = numToList(12345);

    // struct ListNode * reversehead = reverseList(head);
    // print(reversehead);

    print(head);
    reorderList(head);
    print(head);
    
    return 0;
}