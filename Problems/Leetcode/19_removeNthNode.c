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



struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head->next == NULL && n == 1){
        head = NULL;
    } else {
        struct ListNode * z = head;
        int index = 0;
        while (z->next != NULL){
            z = z->next;
            index++;
        }

        index = (index + 1) - n;
        if (index == 0){
            struct ListNode * p = head;
            head = head->next;
            free(p);
        } else {
            struct ListNode * p = head;
            struct ListNode * q = head->next;
            for (int i = 0; i < index - 1; i++){
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
            free(q);
        }
    }
    return head;
}

int main() {
    struct ListNode * head = numToList(12);
    int n = 2;

    print(head);

    head = removeNthFromEnd(head, n);

    print(head);

    return 0;
}