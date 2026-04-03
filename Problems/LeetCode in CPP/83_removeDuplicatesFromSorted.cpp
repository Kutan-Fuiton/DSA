#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; 
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2)));

    ListNode *root = sol.deleteDuplicates(head);

    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }
    return 0;
}