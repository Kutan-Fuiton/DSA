// A. Array Representation of Tree

//                7(0)              |
//                |                 |    
//        -----------------         |  
//        |               |         |    
//        11(1)           2(2)      |
//        |               |         |    
//    ---------       ---------     |
//    |       |       |       |     |
//    7(3)    1(4)    11(5)   9(6)  |

// so in array, it will be representated as [7, 11, 2, 7, 1, 11, 9]


// Another Example:- 

//                                 7(0)                      
//                                  |                             
//                ----------------------------------           
//                |                                |           
//                11(1)                            2(2)              
//                |                                |                    
//        -----------------                -----------------     
//        |               |                |               |     
//        7(3)            1(4)             11(5)           9(6)  
//        |                                                |
//    -----                                                -----    
//    |                                                        |
//    2                                                        11 

//                                 7(0)                      
//                                  |                             
//                ----------------------------------           
//                |                                |           
//                11(1)                            2(2)              
//                |                                |                    
//        -----------------                -----------------     
//        |               |                |               |     
//        7(3)            1(4)             11(5)           9(6)  
//        |               |                |               |
//    ---------       ---------        ---------       ---------    
//    |       |       |       |        |       |       |       |
//    2(7)   n(8)    n(9)    n(10)    n(11)   n(12)   n(13)    11(14)


// so in array, it will be representated as [7, 11, 2, 7, 1, 11, 9, 2, n, n, n, n, n, n, 11]

// Basically iterate from left to right in levels from top to bottom, 1st level left to right, second level left to right, third level left to right and so on... 
// If there is no child then it will be representated as null in that position of array
// n means NULL


// B. Linked Representation of Tree
// not linked list, cuzz list is linear...

//                                2(0)                      
//                                 |                             
//                ----------------------------------           
//                |                                |           
//                1(1)                             4(2)              
//                |                                |                    
//        -----------------                -----------------     
//        |               |                |               |     
//        11(3)           12(4)            n(5)            3(6)  


//   Doubly Linked List Node
//   NULL <-- |prev|data|next| <--> |prev|data|next| <--> |prev|data|next| <--> |prev|data|next| --> NULL

//   [ pointer1 | value | pointer2 ]    ---> This type of node we need...

//                           [   | 2 |   ]                     
//                             |       |                         
//                --------------       -------------           
//                |                                |           
//          [   | 1 |   ]                    [   | 4 |   ]
//            |       |                        |       |                  
//        -----       -----                -----       -----     
//        |               |                |               |     
//  [   | 11 |   ]  [   | 12 |   ]        NULL       [   | 3 |   ]  
//    |        |      |        |                       |       |
//   NULL     NULL   NULL     NULL                    NULL    NULL


// Structure of a Node for Tree

// struct Node {
//     int data;
//     struct Node * left;
//     struct Node * right;
// };




