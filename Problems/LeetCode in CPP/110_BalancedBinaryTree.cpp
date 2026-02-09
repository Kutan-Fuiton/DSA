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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        if (abs(height(root->right) - height(root->left)) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        } else {
            return false;
        }
    }

private:
    int height(TreeNode* root){
        if (root == nullptr){
            return -1;
        } else {
            return 1 + max(height(root->left), height(root->right));
        }
    }
};

int main(){
    Solution sol;
    // TreeNode* root = new TreeNode(1, 
    //     new TreeNode(2,
    //         new TreeNode(3, 
    //             new TreeNode (4),
    //             new TreeNode (4)
    //         ),
    //         new TreeNode (3)
    //     ),
    //     new TreeNode (2)
    // );
    TreeNode * root = new TreeNode ();

    cout << sol.isBalanced(root) << endl;

    return 0;
}