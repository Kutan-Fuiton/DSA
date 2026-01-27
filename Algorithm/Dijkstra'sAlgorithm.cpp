// Dijkstra's Algorithm  -  shortest distance from one node to any other node...

//         A
//        / \
//     8 /   \ 2
//      /     \
//     D-------B
//     |\  5   |
//     | \     |
//     |  \    |
//   2 |   \3  | 6
//     |    \  |
//     |     \ |
//     |  1   \|
//     F-------E
//      \     /
//     3 \   / 9
//        \ /
//         C


// 1. INITIALLY:-

// Prev node means shortest distance from which node
// We need two list, one is visited nodes, another is unvisitend nodes
// visited = []; non-visited = [A,B,C,D,F,E]
// and We will have a table:-

//    Node | Shortest Dist | Prev Node
//    ---------------------------------
//     A   |    Infinity   | 
//     B   |    Infinity   | 
//     C   |    Infinity   | 
//     D   |    Infinity   | 
//     E   |    Infinity   | 
//     F   |    Infinity   | 



// 2. A have two neighbors, one is B and another one is C

// From A to A, shortest distance is 0, which is less than infinity, so will update the table of A node
// From A to B, shortest distance is 2 + 0, which is less than infinity, so will update the table of B node
// From A to D, shortest distance is 8 + 0, which is less than infinity, so will update the table of D node

// A completely visted

// We need two list, one is visited nodes, another is unvisitend nodes
// visited = [A]; non-visited = [B,C,D,F,E]

//    Node | Shortest Dist | Prev Node
//    ---------------------------------
//     A   |       0       | A
//     B   |       2       | A
//     C   |    Infinity   | 
//     D   |       8       | A
//     E   |    Infinity   | 
//     F   |    Infinity   | 



// 3. B have two neighbors, one is D and another one is E

// From B to D, shortest distance is 5 + 2, which is less than 8, so will update the table of D node
// From B to E, shortest distance is 6 + 2, which is less than infinity, so will update the table of E node

// B completely visted

// We need two list, one is visited nodes, another is unvisitend nodes
// visited = [A, B]; non-visited = [C,D,F,E]

//    Node | Shortest Dist | Prev Node
//    ---------------------------------
//     A   |       0       | A
//     B   |       2       | A
//     C   |    Infinity   | 
//     D   |       7       | B
//     E   |       8       | B
//     F   |    Infinity   | 



// 4. D have two neighbors, one is E and another one is F

// From D to E, shortest distance is 3 + 7, which is not less than 8, so node E will stay the same
// From D to F, shortest distance is 2 + 7, which is less than infinity, so will update the table of F node

// D completely visted

// We need two list, one is visited nodes, another is unvisitend nodes
// visited = [A, B, D]; non-visited = [C,F,E]

//    Node | Shortest Dist | Prev Node
//    ---------------------------------
//     A   |       0       | A
//     B   |       2       | A
//     C   |    Infinity   | 
//     D   |       7       | B
//     E   |       8       | B
//     F   |       9       | D



// 5. E have two neighbors, one is F and another one is C

// From E to F, shortest distance is 1 + 8, which is equal to 9, so node F will stay the same
// From E to C, shortest distance is 9 + 8, which is less than infinity, so will update the table of C node

// E completely visted

// We need two list, one is visited nodes, another is unvisitend nodes
// visited = [A, B, D, E]; non-visited = [C, F]

//    Node | Shortest Dist | Prev Node
//    ---------------------------------
//     A   |       0       | A
//     B   |       2       | A
//     C   |       17      | E
//     D   |       7       | B
//     E   |       8       | B
//     F   |       9       | D



// 6. F have one neighbor left which is C

// From F to C, shortest distance is 3 + 9, which is less than 17, so will update the table of C node

// E completely visted

// We need two list, one is visited nodes, another is unvisitend nodes
// visited = [A, B, D, E]; non-visited = [C, F]

//    Node | Shortest Dist | Prev Node
//    ---------------------------------
//     A   |       0       | A
//     B   |       2       | A
//     C   |       12      | F
//     D   |       7       | B
//     E   |       8       | B
//     F   |       9       | D


// This table is the table of shortest distance of different nodes from node A...
// and for shortest distance from node A to node C is 12... which follows the path of A -> B -> D -> F -> C
// This is how it works