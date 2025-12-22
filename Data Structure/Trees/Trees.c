// Trees Data Structure
// It consists of nodes only 

// How many edges counts the depth/height

//    0 --------> 1 --------> 2 -------> 3


//                      |---> 3 ---|
//          |---> 11 ---|          |---> 4
//          |
//          |           |---> 2
//    7  ---|---> 2  ---|
//          |
//          |           |---> 0
//          |---> 8  ---|
//                      |---> 1


// It is tree kinda structure, where every element is a node, we usually visualise it by rotating above representation at 90deg
// Terminologies:- 1. Root:- Topmost Node is the origin node from where everything starts (here, 7)
//                 2. Parent:- Parent Node is the node which have children or child node or lower node (here, 7, 8, 2, 11, 3)
//                 3. Child:- Child node is the node which have parent node or upper node (here, 8, 2, 11, 1, 0, 2, 3, 4)
//                 4. Leaf/External Node:- Leaf Node is the last node of the tree which do not have any child (here, 1, 0, 2, 4)
//                 5. Internal Node:- Internal Node is the node with atleast one child (here, everyone except 1, 0, 2, 4)
//                 6. Depth:- No of edges from root to that node, is the depth of that node (here, depth of node 4 is 3...)
//                 7. Height:- No of edges from node to the deepest leaf... (here height of node 11 is 2... and height of node 8 is 1...)
//                 8. Sibling:- Node belonging to same parent (here, 0 and 1 are sibling)
//                 9. Ancestor:- previous connected nodes are ancestor of that node
//                 10. Descendant:- next connected nodes are descendant of that node
