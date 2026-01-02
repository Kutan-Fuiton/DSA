#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         vector<int> temp = inorderTraversal(root);
//         for (int i = 0; i < temp.size()-1; i++){
//             if (temp[i] >= temp[i+1]) return false;
//         }
//         return true;
//     }

// private:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (root != nullptr){
//             res = inorderTraversal(root->left);
//             vector<int> right = inorderTraversal(root->right);
//             res.push_back(root->val);
//             res.insert(res.end(), right.cbegin(), right.cend());
//         }
//         return res;
//     }  
// };
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        static TreeNode *prev = nullptr;
        if (root != nullptr){
            if (!isValidBST(root->left)) return false;
            if (prev != nullptr && root->val <= prev->val) return false;
            prev = root;
            return isValidBST(root->right);
        } else {
            return true;
        }
    } 
};

int main(){
    Solution sol;
    // TreeNode *root = new TreeNode (
    //     1, 
    //     nullptr, 
    //     new TreeNode(
    //         2, 
    //         new TreeNode(3), 
    //         nullptr
    //     )
    // );
    TreeNode *root = new TreeNode (5, 
        new TreeNode(1), 
        new TreeNode(7,
            new TreeNode(4),
            new TreeNode(8)
        )
    );

    cout << sol.isValidBST(root) << endl;

    return 0;
}