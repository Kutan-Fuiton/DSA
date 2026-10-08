// Breadth First Search (BFS):- 

// -- In BFS, we start with a node and start exploring its connected nodes. The same process is repeated with all the connecting nodes until all the nodes are visited

// Let the graph be this:- 

//  0---1
//  |\  |
//  | \ |
//  |  \|  
//  3---2 
//   \ /
//    4
//   / \ 
//  5   6 


// --------------- A CONCEPT -- BFS SPANNING TREE:- [we will not use this method for bfs traversal, if u want to skip, u can] -------------
//
// -- Consider the graph shown at the right!
// -- We can start with any source node
// -- Lets start with 0
// -- Try to construct a tree with 0 as the root
// -- Mark all the sideways or duplicate edges (above a node) as dashed
// -- This constructed tree is called as BFS Spanning Tree
// -- Level order traversal of a BFS spanning tree is a valid BFS traversal of a graph



// --- Let there is a pivot on node 0, now if we fix that pivot to upper wall, and leave rest of the nodes as it is, it would result in this formation:- 

//       0
//      /|\ 
//     / | \ 
//    /  |  \ 
//   3---2---1
//    \ /
//     4
//    / \ 
//   5   6

// --- Now less make it a binary tree, but dashing some solid lines, like lines between 3&2 and 2&1 and 4&2, [Note:- now we could even dash 3&4 instead of 4&2...]... This is a valid tree...

//       0
//      /|\ 
//     / | \ 
//    /  |  \ 
//   3   2   1
//    \  
//     4
//    / \ 
//   5   6

// Now the level order traversal of this tree is BFS traversal of this graph...
// level order traversal --> traversal from left to right coming from up level to down...
// for this tree, level order traversal is... 0 3 2 1 4 5 6...
// but also, it is the BFS traversal of this graph...
// But we will not create BFS spanning tree for traversal...



// ----------------- BFS TRAVERSAL ----------------------


// Let the graph be this:- 

//  0---1
//  |\  |
//  | \ |
//  |  \|  
//  3---2 
//   \ /
//    4
//   / \ 
//  5   6 

// -- Consider the graph shown above
// -- we can start with any source node
// -- Lets start with 0 and insert it in the queue
// -- visit all the connected vertices and enqueue them from exploration


// lets start visiting nodes from 0 ...
// Visited:- 0        Exploration Queue:- 0

// now every nodes connecting to 0, will first visited
// Visited:- 0, 1, 2, 3        Exploration Queue:- 0

// and side by side, will make it enter into exploration queue too, cuzz those nodes need to be explored...
// Visited:- 0, 1, 2, 3        Exploration Queue:- 0, 1, 2, 3

// now after completely visit the node 0... will remove that node from exploration queue, cuzz its been visited
// Visited:- 0, 1, 2, 3        Exploration Queue:-    1, 2, 3

// now less explore 1, and saw both 0 and 2 connected to 1 is already visited... so will cut it from exploration queue
// Visited:- 0, 1, 2, 3        Exploration Queue:-       2, 3

// now less explore 2, and saw 3 is already visited but 4 is not visited, so will mark put in in visited and also not explored 4, so will put it in exploration queue too... and will cut down 2 from exploration queue too
// Visited:- 0, 1, 2, 3, 4        Exploration Queue:-       2, 3, 4
// Visited:- 0, 1, 2, 3, 4        Exploration Queue:-          3, 4

// now will explore 3, saw 0, 2 and 4 is visited already, also 4 in exploration queue, so will cut down 3 too
// Visited:- 0, 1, 2, 3, 4        Exploration Queue:-             4

// ------ Exploration Queue's meaning, the connected nodes of exploration queue is visited or not?
// ------ Visited meaning those nodes are visited, and those are visited will not push it again in visited

// now will explore 4, saw 2 and 3 visited, but 5 ans 6 is not visited, so will put in exploration queue as well as in visited and 4 will cut down
// Visited:- 0, 1, 2, 3, 4              Exploration Queue:-             4
// Visited:- 0, 1, 2, 3, 4, 5, 6        Exploration Queue:-                5, 6

// visiting 5, there is every node already visited, and visiting 6, there is every node already visited, so will cut down 5 and 6 from exploration queue... and queue will be empty
// Visited:- 0, 1, 2, 3, 4, 5, 6        Exploration Queue:-       


// ALGORITHM:- 

// Mark all nodes v in V as unvisited
// Mark source node s as visited
// enq(Q,s) // First-in-first-out queue Q
// while (Q is not empty){
//     u := deq(Q);
//     for each unvisited neighbour v of u {
//          mark v as visited;
//          enq(Q,v);
//     }
// }



#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct Queue *q){
    if (q->r == q->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q){
    if (q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int val) {
    if (isFull(q)){
        printf("Queue Overflow!\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue* q){
    int a = - 1;
    if (isEmpty(q)){
        printf("Queue Underflow!\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

// Graph on which we will work

//  0---1
//  |\  |
//  | \ |
//  |  \|  
//  3---2 
//   \ /
//    4
//   / \ 
//  5   6 

int main() {
    // Initializing Queue (Array implementation)
    struct Queue * q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    // BFS Implementation
    int node;    // the node that have to dequeued
    int i = 0;   // graph starting from here...
    int visited[7] = {0,0,0,0,0,0,0};
    int n[7][7] = {      // Adjancency Matrix 
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(q, i); // enqueue i for exploration
    while (!isEmpty(q)){
        int node = dequeue(q);
        for(int j = 0; j < 7; j++){
            if (n[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    return 0;
}


// Now the visual representation of queue:- 














