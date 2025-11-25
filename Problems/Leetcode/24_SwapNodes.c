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


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode *p = head;
    head = head->next;
    struct ListNode *prev = NULL;

    while (p != NULL && p->next != NULL){
        struct ListNode * q = p->next;
        p->next = q->next;
        q->next = p;
        if (prev != NULL){
            prev->next = q;            
        }
        prev = p;
        p = p->next;
    }
    return head;
}

int main() {
    struct ListNode * head = numToList(12345);

    print(head);

    head = swapPairs(head);

    print(head);
    
    return 0;
}