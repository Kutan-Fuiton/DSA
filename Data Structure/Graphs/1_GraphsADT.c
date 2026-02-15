// What is a Graph?

// -- Array/LinkedList & stacks --> Linear Data Structure
// -- BST & AVL Trees --> Non linear Hierarchical Data Structure
// -- Graph is an example of Non Linear Data Structure
// -- A Graph is a collection of nodes connected through edges

//   0 --- 1 --- 3
//   |     |     |
//   4 --- 2 --- 5

// this is a graph... where... Dashed lines are edges and numbers are nodes/vertices...
// Tree Data Structure is also a type of graph which consists of nodes and edges

// FORMAL DEFINITION OF A GRAPH:- 

// 1. A Graph G = (V, E) is a collection of vertices and edges connecting these vertices...
// For example:- here, V = {0,1,2,3,4,5} and 
// E = {{0,1}, {1,3}, {1,2}, {0,4}, {2,4}, {2,5}, {3,5}}

// 2. Used to model Paths in a city, social networks, website backlinks, internal employee network, etc...

// 3. A vertex or node is one fundamental unit/entity of which graphs are formed...

// 4. An edge is uniquely defined by its 2 endpoints
// 5. Directed Edge - One way connection
// 6. Undirected Edge - Two way connection
// 7. Directed Graph - All directed edges
// 8. Undirected Graph - All undirected edges

// The above graph is undirected graph, as it have no direction specified so it will act as in both direction of an edge



// INDEGREE AND OUTDEGREE OF A NODE:-

// for this, we need a directed graph, like for example:- 

//   0 --> 1 --> 3
//  /\    /\     |
//   |     |     \/
//   4 --> 2 --- 5

// Indegree - No of edges going out of the node
// Outdegree - No of edges coming into the node

// For example, node '1' have Indegree 2 and outdegree 1




// APPLICATION :- FaceBook - A Graph of Users

// A --- B --- C
// |    / \ 
// |   /   \ 
// |  /     \ 
// | /       \ 
// |/         \ 
// D           E

// 1. Graphs are used to model relationships between nodes
// 2. We can apply graph algorithms to suggest friends to people, calculate no of mutual friends etc.
// 3. Other examples of graph include result of a web crawl for a website or for the entire world wide web, city routes, etc.


// Now here, C is friend of B, and A is friend of B, so algorithm will suggest B to add friend C too, that's how it can increase its network/connection...