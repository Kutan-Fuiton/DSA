// A. Why do we need AVL Trees?

// Imagine if i say u to make BST with 1, 7, 11, 21
// Due to lazyness, u can make it like this

//       21
//      /
//     11
//    /
//   7
//  /
// 1

// this is not efficent tree, it still need to check 4 times which is actually n times, so its better to make a list instead of this... BST used to reduce this time only...

// Almost all the operations in a binary search tree are of order O(h) where h is the height of the tree
// If we dont plan our tree properly, this height can get as high as n where n is the number of nodes in a BST (skewed tree)
// To gurantee an upper bound of O(log n) for all these operations, we use balanced trees

// B. What is an AVL Tree?
// -- Height balanced binary search trees
// -- Height differenece bwtween heights of left and right subtrees for every node is less than or equal 1
// -- Balanced factor = Height of right subtree - Height of left subtree
// -- Can be -1, 0, or 1 for a node to be balances in a Binary search tree 
// -- Can be -1, 0 or 1 for all nodes of an AVL tree

//                   J
//                  / \
//                 /   \
//                /     \
//               /       \
//              /         \
//        (-1) F           P (+1)
//            / \         / \
//           /   \       /   \
//          /     \     /     \
//    (-1) D       G   L (1)   V (-1)
//        /       (0)   \  (0)/ \ 
//       C (0)           N   S   X
//                     (0)  / \  (0)
//                         Q   U
//                        (0)  (0)


// Balance factor calculated as every leaf nodes will be 0 cuzz height 0
// Node D's right subtree 0 height and left subtree 1, so BF -1
// Node F's right subtree 1 height and left subtree 2, so BF -1
// Node S's right subtree 1 height and left subtree 1, so BF 0
// Node V's right subtree 1 height and left subtree 2, so BF -1
// Node L's right subtree 1 height and left subtree 0, so BF +1
// Node P's right subtree 3 height and left subtree 2, so BF +1
// Node J's right subtree 4 height and left subtree 3, so BF +1

//  Each nodes will be of BF -1, 0 or +1




// C. Rotation in AVL Trees:-


// 1. LL rotation in an AVL Tree -- inserted on left of left 

// we will find |BF| of nodes

//    7 (1)
//   /
//  5 (0)

// That means, its an AVL tree, now if 4 wants to get inserted in this tree...

//       7 (2)
//      /
//     5 (1)
//    /
//   4 (0)

// balance factor disturbed and 7 got disturbed especially cuzz |BF| > 1, so they try to apply ll rotation in this to create a happy balanced tree... 
// the root node as pivot, a rotation need in clock wise direction to create happy tree...

//       7 (2)                  5(0)
//      /                       /  \ 
//     5 (1)          --->    4(0) 7(0)
//    /
//   4 (0)

// now it became an ll rotated happy avl tree


// 2. RR rotation in an AVL Tree -- inserted on right of right 

// we will find |BF| of nodes

//    7 (1)
//     \
//      9 (0)

// That means, its an AVL tree, now if 11 wants to get inserted in this tree...

//       7 (2)
//        \
//         9 (1)
//          \
//           11 (0)

// balance factor disturbed and 7 got disturbed especially cuzz |BF| > 1, so they try to apply rr rotation in this to create a happy balanced tree... 
// the root node as pivot, a rotation need in anti-clock wise direction to create happy tree...

//       7 (2)                    9(0)
//        \                      /   \
//         9 (1)      ---->     7(0) 11(0)
//          \
//           11 (0)

// now it became an rr rotated happy avl tree


// 3. LR rotation in an AVL Tree -- inserted on right of left 

// we will find |BF| of nodes

//     7 (1)
//    /
//   4(0)

// That means, its an AVL tree, now if 5 wants to get inserted in this tree...

//     7 (2)
//    /
//   4(1)
//    \
//     5(0)

// balance factor disturbed and 7 got disturbed especially cuzz |BF| > 1, so they try to apply lr rotation in this to create a happy balanced tree... 
// first, the second root node (4) as pivot, a rotation need in anti-clock wise direction
// second, the root node as pivot (7), a rotation need in clock wise direction to get a happy avl tree

//     7 (2)                    7(2)                     5(0)
//    /                        /                        /   \
//   4(1)         --->        5(1)            -->      4(0)  7(0)
//    \                      / 
//     5(0)                 4(0)

// now it became an lr rotated happy avl tree


// 4. RL rotation in an AVL Tree -- inserted on left of right 

// we will find |BF| of nodes

//    7 (1)
//     \
//     11 (0)

// That means, its an AVL tree, now if 10 wants to get inserted in this tree...

//       7 (2)
//        \
//        11 (1)
//        /
//       10 (0)

// balance factor disturbed and 7 got disturbed especially cuzz |BF| > 1, so they try to apply rl rotation in this to create a happy balanced tree...
// first, the second root node (11) as pivot, a rotation need in clock wise direction
// second, the root node as pivot (7), a rotation need in anti-clock wise direction to get a happy avl tree

//       7 (2)                    7 (2)                    10(0)
//        \                        \                       /   \
//        11 (1)      ---->        10 (1)        ---->    7(0) 11(0) 
//        /                          \
//       10 (0)                      11 (0)

// now it became an rl rotated happy avl tree



// #######
// That means rotate operations are 2:-
// -- Left Rotate wrt a node