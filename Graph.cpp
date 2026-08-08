#include <bits/stdc++.h>
using namespace std;
/*
============================================================
                        GRAPH BASICS
============================================================
A Graph consists of:
    1. Nodes / Vertices
    2. Edges / Connections
A graph can contain cycles and does not necessarily have a root
like a tree.
Common graph representations:
    1. Adjacency List
    2. Adjacency Matrix
    3. Edge List
Adjacency List is commonly preferred for BFS and DFS because
it gives direct access to the neighbours of a node.
*/
int main() {
    int n = 10;
    // adjclist[i] contains all neighbours of node i.
    vector<vector<int>> adjclist(n + 1);
    // Undirected graph: if u is connected to v, v is also connected to u.
    adjclist[1] = {2, 4};
    adjclist[2] = {1, 3, 5, 7, 8};
    adjclist[3] = {2, 4, 10, 9};
    adjclist[4] = {1, 3};
    adjclist[5] = {6, 7, 2, 8};
    adjclist[6] = {5};
    adjclist[7] = {5, 8, 2};
    adjclist[8] = {2, 5, 7};
    adjclist[9] = {3};
    adjclist[10] = {3};
/*
============================================================
                            BFS
============================================================
BFS = Breadth First Search
BFS traverses a graph level by level.
If we start from node 1:
    Level 0 -> 1
    Level 1 -> nodes at distance 1
    Level 2 -> nodes at distance 2
    ...
BFS uses a Queue:
    Queue -> FIFO -> First In First Out
Steps:
    1. Push starting node into queue.
    2. Mark it visited.
    3. Take the front node.
    4. Visit all unvisited neighbours.
    5. Push those neighbours into the queue.
    6. Repeat until queue is empty.
*/
    set<int> bfsvisited;       // Stores visited nodes.
    vector<int> btraverse;     // Stores BFS traversal order.
    queue<int> que;            // Queue used for BFS.
    bfsvisited.insert(1);      // Start BFS from node 1.
    btraverse.push_back(1);
    que.push(1);
    while (!que.empty()) {
        int current = que.front();    // Take the first node.
        cout << current << " ";
        que.pop();                    // Remove it from the queue.
        for (int neighbour : adjclist[current]) {
            // Visit only unvisited neighbours.
            if (bfsvisited.find(neighbour) == bfsvisited.end()) {
                bfsvisited.insert(neighbour); // Mark as visited.
                btraverse.push_back(neighbour);
                que.push(neighbour);          // Process later.
            }
        }
    }
    cout << "\nBFS Traversal: ";
    for (int node : btraverse) cout << node << " ";
    cout << "\n";
/*
============================================================
                            DFS
============================================================
DFS = Depth First Search
DFS does not go level by level. It goes as deep as possible
before backtracking.
DFS can be implemented using:
    1. Recursion
    2. Stack
Here we use a Stack:
    Stack -> LIFO -> Last In First Out
Steps:
    1. Push starting node into stack.
    2. Mark it visited.
    3. Look at the top node.
    4. Find an unvisited neighbour.
    5. Push that neighbour and go deeper.
    6. If no unvisited neighbour exists, pop the node
       and backtrack.
nextIndex[node] stores which neighbour of node we should
check next. This prevents repeatedly checking the adjacency
list from index 0 after backtracking.
*/
    set<int> dfsvisited;             // Stores visited nodes.
    stack<int> stac;                 // Stack used for DFS.
    vector<int> nextIndex(n + 1, 0); // Next neighbour index for each node.
    vector<int> dtraverse;           // Stores DFS traversal order.
    dfsvisited.insert(1);            // Start DFS from node 1.
    dtraverse.push_back(1);
    stac.push(1);
    while (!stac.empty()) {
        int current = stac.top();    // Current node being explored.
        cout << current << " ";
        int i = nextIndex[current];  // Start from saved neighbour index.
        vector<int> neighbours = adjclist[current];
        // Skip already visited neighbours.
        while (i < neighbours.size() &&
               dfsvisited.find(neighbours[i]) != dfsvisited.end()) {
            i++;
        }
        nextIndex[current] = i + 1;  // Remember where to continue later.
        if (i >= neighbours.size()) {
            stac.pop();              // No neighbour left -> backtrack.
        }
        else {
            int nextNode = neighbours[i]; // Found an unvisited neighbour.
            dfsvisited.insert(nextNode);  // Mark it visited.
            stac.push(nextNode);           // Go deeper.
            dtraverse.push_back(nextNode);
        }
    }
    cout << "\nDFS Traversal: ";
    for (int node : dtraverse) cout << node << " ";
    cout << "\n";
/*
============================================================
                        BFS VS DFS
============================================================
BFS:
    Queue -> FIFO -> Level by level.
DFS:
    Stack -> LIFO -> Go deep, then backtrack.
Both use visited to avoid repeatedly visiting nodes.
BFS -> Queue + Visited
DFS -> Stack + Visited + nextIndex
============================================================
*/
    return 0;
}