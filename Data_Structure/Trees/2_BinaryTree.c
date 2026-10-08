// Binary Tree is a tree which has atmost 2 children

// Degree of a node represents no of direct child of that node...
// Degree of a tree is the highest degree of a node among all the nodes present in the tree...
// In Binary Tree, we have atmost 2 degree nodes... i.e., degree <= 2

// This is a binary tree representation u can say

//               Node               |               Node      |  
//                |                 |                |        |
//                |                 |                |        |
//        |---------------|         |        |--------        |
//        |               |         |        |                |   
//        |               |         |        |                |    
//      Node 1          Node 2      |      Node 1             |  

// This is a not a binary tree

//               Node               |              
//                |                 |            
//                |                 |          
//        |---------------|         |        
//        |       |       |         |      
//        |       |       |         |     
//      Node1   Node2   Node3       |   

// Array, Stack, Queue, linkedlist are linear data structure whereas tree is non linear data structure
// Tree is ideal for representating heirarchical data


// Types of Binary Tree:-

// 1. Full or Strict Binary Tree:- All Nodes have either 0 or 2 children

//               Node               |
//                |                 |
//                |                 |      
//        -----------------         |    
//        |               |         |  
//        |               |         |    
//      Node 1          Node 2      |
//        |                         |    
//        |                         |    
//    ---------                     |
//    |       |                     |
//    |       |                     |
//  node3   node4                   |


// 2. Perfect Binary Tree:- Internal nodes have 2 children + all leaf nodes are on same level

//               Node               |
//                |                 |
//                |                 |      
//        -----------------         |    
//        |               |         |  
//        |               |         |    
//      Node 1          Node 2      |
//        |               |         |    
//        |               |         |    
//    ---------       ---------     |
//    |       |       |       |     |
//    |       |       |       |     |
//  node3   node4   node5   node6   |

// 3. Complete Binary Tree:- All levels are completely filled except possibly the last level... and also in last level, it must have its keys as left as possible, that means it should aligned it to left 

//               Node               |               Node               |
//                |                 |                |                 |
//                |                 |                |                 |      
//        -----------------         |        -----------------         |    
//        |               |         |        |               |         |  
//        |               |         |        |               |         |    
//      Node 1          Node 2      |      Node 1          Node 2      |
//        |               |         |        |               |         |    
//        |               |         |        |               |         |    
//    ---------       -----         |    -----           -----         |
//    |       |       |             |    |               |             |
//    |       |       |             |    |               |             |
//  node3   node4   node5           |  node3           node4           |

// below are not complete binary tree

//               Node               |               Node               |
//                |                 |                |                 |
//                |                 |                |                 |      
//        -----------------         |        -----------------         |    
//        |               |         |        |               |         |  
//        |               |         |        |               |         |    
//      Node 1          Node 2      |      Node 1          Node 2      |
//        |               |         |        |               |         |    
//        |               |         |        |               |         |    
//    ---------           -----     |        -----       ---------     |
//    |       |               |     |            |       |       |     |
//    |       |               |     |            |       |       |     |
//  node3   node4           node5   |          node3   node4   node5   |


// 4. Degenerate Tree:- Every parent has exactly one child...

//               Node               |
//                |                 |
//                |                 |      
//        ---------                 |    
//        |                         |  
//        |                         |    
//      Node 1                      |
//        |                         |    
//        |                         |    
//        -----                     |
//            |                     |
//            |                     |
//          node2                   |

// 5. Skewed Trees:- Degenerate tree left aligned or right aligned...

//         Left Skewed Tree         |          Right Skewed Tree                    

//               Node               |               Node               
//                |                 |               |                 
//                |                 |               |                       
//        ---------                 |               ---------                     
//        |                         |                       |             
//        |                         |                       |           
//      Node 1                      |                     Node 1 
//        |                         |                       |    
//        |                         |                       |    
//    -----                         |                       -----
//    |                             |                           |
//    |                             |                           |
//  node2                           |                         node 2


















