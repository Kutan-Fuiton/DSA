// Left-Left Insertion  -- Kinda Same for Right Right Insertion

//         11 (1)
//        /  \
//       /    \ 
//      9 (0) 18 (0)
//     / \ 
//    /   \ 
//   5(0) 10(0)

// Now gonna insert 4 in this tree, will first insert normal as in BST
// Ofc will destroy the balance factor

//         11 (2)                                      9 
//        /  \                                        / \ 
//       /    \                                      /   \ 
//      9 (1) 18 (0)                                5    11
//     / \                   ------->              /     / \   
//    /   \                                       4     10 18
//   5(1) 10(0)
//  /
// 4 (0)

// element at the top is first element starting from 4 is imbalanced, so will rotate wrt 11, 
// which rotation? as it is inserted on left of left, so ll rotation, that means clockwise rotation around 11




// Right-Left Insertion  -- Kinda Same for Left-Right Insertion

//        7(1)
//       / \ 
//      /   \ 
//     1(0)  10(1)
//            \
//            17(0)

// Now gonna insert 16 in this tree, will first insert normal as in BST
// Ofc it will destroy the balance factor... FIB -> First Imbalance Node

//        7(2)                                             7                             7
//       / \                                              / \                           / \ 
//      /   \                                            1  10                         /   \ 
//     1(0)  10(2)  --> FIB                                   \                       1    16
//            \                        ------------>          16       ---------->        /  \ 
//            17(1)  --> child of FIB                           \                        10  17 
//            /          in path of                             17
//           16(0)       inserted node

// 10 is the First Imbalance Node, and 17 is the child of First Imbalance Node in the path of insertion
// as it is inserted in the left of right...
// first clockwise rotation will be wrt child of FIB
// second anti-clockwise rotation will be wrt FIB





