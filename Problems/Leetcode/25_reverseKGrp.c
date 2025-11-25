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

int length(struct ListNode * head){
    struct ListNode * ptr = head;
    int count = 0;
    while (ptr->next != NULL){
        ptr = ptr->next;
        count++;
    }
    return count + 1;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int len = length(head);
    
    if (head == NULL || k <= 1 || k > len) {
        return head;
    }

    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* groupPrev = dummy;
    struct ListNode* curr = head;

    for (int i = 0; i < len / k; i++) {
        struct ListNode* tail = curr; 
        struct ListNode* prev = NULL;
        struct ListNode* tempNext = NULL;

        for (int j = 0; j < k; j++) {
            tempNext = curr->next;  
            curr->next = prev;     
            prev = curr;            
            curr = tempNext;        
        }
        groupPrev->next = prev; 
        groupPrev = tail; 
        if (i == (len/k)-1){
            groupPrev->next = curr;
        }
    }

    return dummy->next;
}

int main (){
    struct ListNode * head = numToList(123);
    // printf("%d", length (head));

    print(head);

    head = reverseKGroup(head, 2);

    print(head);
    
    return 0;
}