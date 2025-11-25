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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode * grpPrev = dummy;
    struct ListNode * ptr = head;
    // struct ListNode * curr = head;
    int count = 1;

    while(ptr != NULL){
        if (count == left){
            struct ListNode * curr = ptr;
            struct ListNode * perm = ptr;
            struct ListNode * prev = NULL;
            struct ListNode * tempNext = NULL;
            for (int i = 0; i <= right - left; i++){
                curr = ptr->next;
                ptr->next = prev;
                prev = ptr;
                ptr = curr; 
            }
            grpPrev->next = prev;
            perm->next = ptr;
            break;
        }
        grpPrev = grpPrev->next;
        ptr = (ptr->next != NULL)?ptr->next:NULL;
        count++;
    }
    return dummy->next;
}

int main (){
    struct ListNode * head = numToList(5);
    // printf("%d", length (head));

    print(head);

    head = reverseBetween(head, 1, 1);

    print(head);
    
    return 0;
}


