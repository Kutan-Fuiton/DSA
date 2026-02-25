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
    int sumRootToLeaf(TreeNode* root) {
        return temp(root, 0);
    }

    int temp(TreeNode* root, int curr){
        if (root == nullptr) return 0; // if null nodes

        curr = (curr * 2) + root->val;

        if (root->left == nullptr && root->right == nullptr) return curr;  // if leaf nodes

        return temp(root->left, curr)+temp(root->right, curr);
    }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(1, new TreeNode(1), new TreeNode());
    // TreeNode *root = new TreeNode(1, 
    //     new TreeNode(0,
    //         new TreeNode(0),
    //         new TreeNode(1)
    //     ),
    //     new TreeNode(1,
    //         new TreeNode(0),
    //         new TreeNode(1)
    //     )
    // );
    
    cout << sol.sumRootToLeaf(root) << endl;

    return 0;
}