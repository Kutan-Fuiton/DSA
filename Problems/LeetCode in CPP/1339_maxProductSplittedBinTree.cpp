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

class Solution {
public:
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        long long totalSum = 0;
        long long maxProd = 0;
        
        totalSum = getTotalSum(root);
        
        findMaxProduct(root, totalSum, maxProd);
        
        return maxProd % MOD;
    }
    
private:
    long long getTotalSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + getTotalSum(node->left) + getTotalSum(node->right);
    }
    
    long long findMaxProduct(TreeNode* node, long long totalSum, long long& maxProd) {
        if (!node) return 0;
        
        long long leftSum = findMaxProduct(node->left, totalSum, maxProd);
        long long rightSum = findMaxProduct(node->right, totalSum, maxProd);
        long long subtreeSum = node->val + leftSum + rightSum;
        
        if (subtreeSum != totalSum) {
            maxProd = max(maxProd, subtreeSum * (totalSum - subtreeSum));
        }
        
        return subtreeSum;
    }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(1,
        nullptr,
        new TreeNode(2,
            new TreeNode(3),
            new TreeNode(4,
                new TreeNode (5),
                new TreeNode (6)
            )
        )
    );

    cout << sol.maxProduct(root) << endl;
    // cout << sol.sum(root, 0) << endl;

    return 0;
}