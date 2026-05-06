#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        // counting no of nodes
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        // rotating by k steps
        for (int i = 0; i < k%count; i++){
            ListNode* ptr = head;

            while (ptr->next->next != nullptr) ptr = ptr->next;

            ptr->next->next = head;
            head = ptr->next;
            ptr->next = nullptr;
        }
        return head;
    }
};

int main(){
    Solution sol;
    // ListNode* root = new ListNode(0, new ListNode(1, new ListNode(2))); int k = 5;
    // ListNode* root = new ListNode(); int k = 1;
    ListNode* root = new ListNode(0, new ListNode(1, new ListNode(2))); int k = 0;

    ListNode* res = sol.rotateRight(root, k);

    while (res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}