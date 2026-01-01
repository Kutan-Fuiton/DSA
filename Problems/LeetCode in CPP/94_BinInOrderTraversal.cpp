#include<iostream>
#include<vector>
#include<algorithm>
#include <iterator>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root != nullptr){
            res = inorderTraversal(root->left);
            vector<int> right = inorderTraversal(root->right);
            res.push_back(root->val);
            res.insert(res.end(), right.cbegin(), right.cend());
        }
        return res;
    }   
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode (
        1, 
        nullptr, 
        new TreeNode(
            2, 
            new TreeNode(3), 
            nullptr
        )
    );

    vector<int> res = sol.inorderTraversal(root);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}