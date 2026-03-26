#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return dummy.next;
    }
};

int main(){
    Solution sol; 

    ListNode *root1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *root2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode *root3 = sol.mergeTwoLists(root1, root2);

    while (root3 != nullptr){
        cout << root3->val << " ";
        root3 = root3->next;
    }
    cout << endl;

    return 0;
}