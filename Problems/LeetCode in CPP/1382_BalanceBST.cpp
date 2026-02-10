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

// --------HELPER FUNCTION------------
void inOrder(struct TreeNode * root){
    if (root != NULL){
        inOrder(root->left);
        printf("%d ", root->val);
        inOrder(root->right);
    }
}

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inord;
        inorderHelper(root, inord);
        return buildBST(inord, 0, inord.size() - 1);
    }

private:
    void inorderHelper(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        inorderHelper(root->left, result);
        result.push_back(root->val);
        inorderHelper(root->right, result);
    }

    TreeNode* buildBST(vector<int>& arr, int low, int high) {
        if (low > high) return nullptr;

        int mid = low + (high - low) / 2;
        TreeNode* node = new TreeNode(arr[mid]);

        node->left  = buildBST(arr, low, mid - 1);
        node->right = buildBST(arr, mid + 1, high);

        return node;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1, 
        new TreeNode (),
        new TreeNode(2,
            new TreeNode (),
            new TreeNode(3, 
                new TreeNode (),
                new TreeNode (4)
            )
        )
    );
    // TreeNode * root = new TreeNode ();

    inOrder(root);
    cout << endl;
    TreeNode* res = sol.balanceBST(root);
    inOrder(res);

    return 0;
}