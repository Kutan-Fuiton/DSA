/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
using namespace std;

class Solution {
private:
    int counter = 0;

    // I want this function to return total summation of all node values in this subtree, and total no of nodes in this subtree
    // {total_sum, total_count}
    pair<int, int> BottomUpSearch(TreeNode* root){
        if (!root) return {0, 0};

        auto left = BottomUpSearch(root->left);
        auto right = BottomUpSearch(root->right);

        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;

        if (root->val == (totalSum / totalCount)) counter++;

        return {totalSum, totalCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        counter  = 0;
        BottomUpSearch(root);
        return counter;
    }
};