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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> prev = {root};
        int num;
        int MAX = root->val;
        int pass = 1;
        int idx = 2;
        int i_max = 1;
        cout << "max : " << MAX << "; " << "count : " << MAX << "; " << i_max << ": "; 
        for (const TreeNode* n : prev){
            cout << n->val << " ";
        }
        cout << endl;
        while (pass){
            vector<TreeNode*> curr;
            int count = 0;
            for (TreeNode* n : prev){
                if (n->left != nullptr) {
                    count += n->left->val;
                    curr.push_back(n->left);
                }
                if (n->right != nullptr) {
                    count += n->right->val;
                    curr.push_back(n->right);
                }
            }
            if (curr.empty()) pass = 0;
            else {
                cout << "max : " << MAX << "; " << "count : " << count << "; " << idx << ": "; 
                if (count > MAX){
                    i_max = idx;
                    MAX = count;
                }
                prev.clear();
                prev.insert(prev.begin(), curr.cbegin(), curr.cend());
                for (const TreeNode* n : prev){
                    cout << n->val << " ";
                }
                cout << endl;
                idx++;
            }
        }
        return i_max;
    }
};

int main(){
    Solution Sol;
    TreeNode *root = new TreeNode(1,
        new TreeNode(7,
            new TreeNode(7),
            new TreeNode(3)
        ),
        new TreeNode()
    );

    cout << Sol.maxLevelSum(root) << endl;

    vector<TreeNode*> nodes = {root, root->left, root->right};

    for (const TreeNode* n : nodes){
        cout << n->val << endl;
    }

    return 0;
}