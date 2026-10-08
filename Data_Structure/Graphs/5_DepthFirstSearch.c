#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0,0,0,0,0,0,0};
int A[7][7] = {      // Adjancency Matrix 
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {0,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void DFS(int i){
    printf("%d ", i);  // starting node printed
    visited[i] = 1;    // starting node marked visited
    for (int j = 0; j < 7; j++){    
        if (A[i][j] == 1 && !visited[j]){     // wherever the edge is i.e. connected with starting node, assume those nodes as starting nodes and also those nodes should be not visited and start DFS from there, just visited array will go on filling on iterating from 0 - 6
            DFS(j);
        }
    }
}

// The recursion doing inside this function is using stack by default, or we can say, we are using stack implicitly not explicitly...

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
    // DFS Implementation
    DFS(4);

    return 0;
}