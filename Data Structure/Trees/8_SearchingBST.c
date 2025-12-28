// Searching in Binary Search Tree

// Below Tree is BST, have to search 55(let, val) in this... 

//           50
//          / \ 
//         /   \ 
//        /     \ 
//       /       \ 
//      40       60
//     / \      /  \
//    /   \    /    \
//   20   45  55    70

// First will check, the val >,=,< to root element, here 55 > 50, so we will only search it inside right subtree...

//     60
//    / \
//   /   \
//  55   70

// same for this, will check, the val >,=,< to root element, here 55 < 60, so we will only search it inside left subtree...

//     55
//    / \
//   /   \
// NULL  NULL

// same for this, will check, the val >,=,< to root element, here 55 = 55, so that element exists in the BST...

// In worst case time complexity, comparison will be equal to height of the tree, here height of the tree is 3, so did 3 comparisons
