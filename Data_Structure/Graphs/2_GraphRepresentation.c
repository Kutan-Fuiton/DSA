// WAYS TO REPRESENT A GRAPH:-

// Adjacency list - Mark the nodes with the list of its neighbors
// Adjacency matrix - Aij = 1 for an edge between i and j, 0 otherwise
// Edge Set - store the pair of nodes/vertices connected with an edge. Eg - {(0, 1), (0, 4), (1, 4)}
// Other implementations to represent a graph also exists. For e.g. Compact list representation, cost adjacency list, cost adjancency matrix etc.


// ADJACENCY LIST:-

// Graph:-

//  0----1
//  |   / \ 
//  |  /   \ 
//  | /     \ 
//  |/       3 
//  2----4

// -- Mark the nodes with list of its neighbors
// 0:- 1 -> 2            --> Linked List
// 1:- 0 -> 2 -> 3       --> Linked List  
// 2:- 0 -> 1 -> 4       --> Linked List 
// 3:- 1                 --> Linked List
// 4:- 2                 --> Linked List


// ADJACENCY MATRIX

// Graph:-

//  0     1
//   \   / \ 
//    \ /   \ 
//     5     \ 
//    /       \ 
//   /   /-----3 
//  2---/     / 
//           4 

// -- Aij = 1 for an edge between i and j, 0 otherwise!

//     0   1   2   3   4   5
// 0                       1
// 1                       1
// 2                      
// 3           1       1   1
// 4               1
// 5   1

//     0   1   2   3   4   5
// 0   0   0   0   0   0   1
// 1   0   0   0   0   0   1 
// 2   0   0   0   0   0   0                    
// 3   0   0   1   0   1   1
// 4   0   0   0   1   0   0
// 5   1   0   0   0   0   0

// COST ADJACENCY MATRIX
// Now, for cost adjacency matrix is 1 replaced with cost of that edge...

// Graph;- 

//  0     
//   \   
//    \ 4
//     \ 
//    8 \ 
//  1----2 
//       |\  
//     2 | \ 11   
//       |  \ 
//  3----4   5 
//    9

// -- Aij = cost for an edge between i and j, 0 otherwise!
// -- Aij = cost for an edge between i and j, -1 otherwise! (if the cost can be 0)

//     0   1   2   3   4   5
// 0   0   0   4   0   0   0
// 1   0   0   8   0   0   0 
// 2   4   8   0   0   2   11                    
// 3   0   0   0   0   9   0
// 4   0   0   2   9   0   0
// 5   0   0  11   0   0   0

// sometimes cost can be zero, so then will insert -1 instead of 0 for otherwise condition...


// OTHER IMPLEMENTATIONS
// -- Edge Set - Store the pair of nodes/vertices connected with an edge. eg - {(0, 1), (0, 4), (1,4)}
// -- Cost adjacency list - Cost is also stored along with the links
// -- Compact List representation - The entire graph is stored in a 1d array


// THE MAIN IMPLEMENTATIONS:- ADJACENCY LIST and ADJACENCY MATRIX