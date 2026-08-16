// BIPARTITE GRAPH
// We call a graph a Bipartite Graph if we can color its vertices using
// two different colors such that no two adjacent vertices have the same color.
// Another way to think about it:
// - Divide the vertices into two sets.
// - Every edge must connect a vertex from one set to the other.
// Important observations:
// - A graph with no cycles is always bipartite.
// - An even-length cycle is bipartite because we can color it alternately.
// - An odd-length cycle is NOT bipartite because alternating colors will
//   eventually force two adjacent vertices to have the same color.
// We can check whether a graph is bipartite using BFS or DFS.
// In both approaches:
// - -1 means the vertex has not been colored yet.
// -  0 and 1 represent the two colors.
// If we find an edge connecting two vertices with the same color,
// the graph is NOT bipartite.
// Time Complexity:  O(V + E)
// Space Complexity: O(V + E) for the adjacency list and traversal structures.
#include <bits/stdc++.h>
using namespace std;
// ============================================================
// BFS APPROACH
// ============================================================
// We use a queue to traverse the graph level by level.
// We also loop through all vertices because a graph may have
// multiple disconnected components. Each unvisited component
// needs its own BFS.
class SolutionBFS {
public:
    bool isBipartite(int V, vector<vector<int>>& edges) {
        // Convert the edge list into an adjacency list.
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // The graph is undirected, so add both directions.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // -1 = not colored
        //  0 = color 0
        //  1 = color 1
        vector<int> color(V, -1);
        queue<int> q;
        // The graph may contain multiple disconnected components.
        for (int i = 0; i < V; i++) {
            // If this vertex is already colored, its component
            // has already been processed.
            if (color[i] != -1)
                continue;
            // Start a new component with color 0.
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                // Give every uncolored neighbor the opposite color.
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    // If the neighbor already has the same color,
                    // the graph cannot be bipartite.
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// ============================================================
// DFS APPROACH
// ============================================================
// Here we use a stack to perform DFS iteratively.
// The idea is exactly the same as BFS:
// - Color the starting vertex.
// - Give every uncolored neighbor the opposite color.
// - If an already-colored neighbor has the same color,
//   the graph is not bipartite.
// We again check every vertex because the graph may be
// disconnected.
class SolutionDFS {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // -1 = not colored
        //  0 = color 0
        //  1 = color 1
        vector<int> color(V, -1);
        stack<int> st;
        // Check every component.
        for (int i = 0; i < V; i++) {
            if (color[i] != -1)
                continue;
            // Start this component with color 0.
            color[i] = 0;
            st.push(i);
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                // Visit all neighbors of the current node.
                for (int neighbor : graph[node]) {
                    // If the neighbor is uncolored,
                    // give it the opposite color.
                    if (color[neighbor] == -1) {

                        color[neighbor] = 1 - color[node];
                        st.push(neighbor);
                    }
                    // If the neighbor has the same color,
                    // the graph is not bipartite.
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// ============================================================
// KEY IDEA TO REMEMBER
// ============================================================
// BFS and DFS use the same logic:
//
//     Current node = 0
//     Neighbor     = 1
//
//     Current node = 1
//     Neighbor     = 0
// If an edge ever connects:
//
//     0 ---- 0    -> NOT BIPARTITE
//     1 ---- 1    -> NOT BIPARTITE
//
// Otherwise, after processing the whole graph:
//     -> BIPARTITE
// For a GENERAL GRAPH, always consider disconnected components,
// which is why both solutions loop from 0 to V - 1.