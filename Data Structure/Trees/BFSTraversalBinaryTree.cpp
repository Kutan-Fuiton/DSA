// BFS Traversal in Binary Tree

// As we know BFS traversal is also level order traversal of binary tree also carried out with the help of queue

// let the tree is:- 

//         3
//        / \ 
//       9  20
//          / \ 
//         15  7


// So we have to initiate a queue which will stores node... let q

// q = |     |

// at first have to push root(3) into queue,

// q = |  3  |

// inside while loop until the queue have some element

// --------- first iteration ---------

// if queue have some element, then will proceed, will create a temporary node and will store the front value of queue in it.
// here, temp = 3  ---> temp node = root node and then pop out one element from queue

// q = |     |

// print that temp node and then if left node exist, then push the left node to queue, and if right node exist, then push the right node to queue, here as both exists

// q = |  9  |  20  |

// --------- second iteration ---------
// if queue have some element, then will proceed, will create a temporary node and will store the front value of queue in it.
// here, temp = 9  ---> temp node = root->left node and then pop out one element from queue

// q = |     |  20  |

// print that temp node and then if left node exist, then push the left node to queue, and if right node exist, then push the right node to queue, here as both exists

// 9 dont have any left or right child, so will simply go to next iteration...

// --------- third iteration ---------
// if queue have some element, then will proceed, will create a temporary node and will store the front value of queue in it.
// here, temp = 20  ---> temp node = root->right node and then pop out one element from queue

// q = |     |     |

// print that temp node and then if left node exist, then push the left node to queue, and if right node exist, then push the right node to queue, here as both exists

// q = |     |     |  15  |  7  |

// --------- fourth iteration ---------
// similarly, 15 will be printed

// q = |     |     |      |  7  |

// --------- fifth iteration ---------
// similarly, 7 will be printed

// q = |     |     |      |     |

// as queue becomes empty, it exits the loop, and all traversal done already


// so output will show like 3 9 20 15 7


#include<iostream>
#include<vector>
#include<queue>
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
    void bfs(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode (20, new TreeNode(15), new TreeNode(7)));

    sol.bfs(root);
    
    return 0;
}