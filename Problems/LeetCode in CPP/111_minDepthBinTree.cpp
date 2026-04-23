#include<iostream>
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        
        if (root->left == nullptr) return 1 + minDepth(root->right);
        if (root->right == nullptr) return 1 + minDepth(root->left);
        
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << sol.minDepth(root) << endl;
    return 0;
}