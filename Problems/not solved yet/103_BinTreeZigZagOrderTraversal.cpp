#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> prev = {root};
        int pass = 1;
        int reverse = 0;
        int idx = 2;
        while (pass){
            vector<TreeNode*> curr;
            vector<int> nums;
            for (const TreeNode * n : prev){
                if (n->left != nullptr) {
                    nums.push_back(n->left->val);
                    curr.push_back(n->left);
                }
                if (n->right != nullptr) {
                    nums.push_back(n->right->val);
                    curr.push_back(n->right);
                }
            }
            if (curr.empty()) pass = 0;
            else {
                prev.clear();
                prev.insert(prev.begin(), curr.cbegin(), curr.cend());
                idx++;
            }
        }
    }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(1,
        new TreeNode(7,
            new TreeNode(7),
            new TreeNode(3)
        ),
        new TreeNode()
    );

    vector<vector<int>> res = sol.zigzagLevelOrder(root);

    for (int i = 0; i < res.size(); i++){       
        for (int j = 0; j < res[i].size(); j++){
            cout << res.size() << " ";
        }
        cout << endl;
    }

    vector<TreeNode*> nodes = {root, root->left, root->right};

    for (const TreeNode* n : nodes){
        cout << n->val << endl;
    }

    return 0;
}