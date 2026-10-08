// Graph Traversal

// -- Graph Traversal refers to the process of visiting (checking and/or updating) each vertex(node) in a graph. 
// -- Sequence of steps known as Graph traversal algorithm can be used to traverse a graph.
// -- Two Algorithms of Graph Traversal are:
//     - Breadth First Search (BFS)
//     - Depth First Search (DFS)


// EXPLORING A VERTEX (NODE):- 

// -- In a typical Graph Traversal algorithm, we traverse through (or visit) all the nodes of a graph and add it to the collection of visited nodes
// -- Exploring a vertex in a graph means visiting all the connected vertices

// Graph:-
//     1 --- 4
//   /   \ 
// 0       3
//   \   /
//     2

// 0, 1, 2, 3, 4
// 0 is explored 
//    1, 2, 3, 4
// 1 is explored
//       2, 3, 4
// like this, so it is basically following first in and first out principle, which is basically queue data structure which we will use in breadth first search
// and in depth first search, we will use depth first Search, will use stack data structure