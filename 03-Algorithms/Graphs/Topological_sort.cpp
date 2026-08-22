#include <bits/stdc++.h>
using namespace std;
// Topological Sort using DFS and Kahn's Algorithm
// Topological Sort is possible only for a Directed Acyclic Graph (DAG)
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
         vector<int>& pathVis, stack<int>& st, bool& cycle) {
    vis[node] = 1;       // Marks the node as completely visited
    pathVis[node] = 1;   // Marks the node as visited in the current DFS path
    for (int next : adj[node]) {
        if (!vis[next]) {
            dfs(next, adj, vis, pathVis, st, cycle);
        }
        else if (pathVis[next]) {
            // Node is already present in the current path -> cycle exists
            cycle = true;
        }
    }
    pathVis[node] = 0;   // Remove node from the current DFS path
    st.push(node);       // Store node after visiting all its neighbours
}
vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);      // Tracks whether a node has been visited
    vector<int> pathVis(V, 0);  // Tracks nodes in the current DFS recursion path
    stack<int> st;              // Stores nodes in reverse topological order
    bool cycle = false;         // Becomes true if a cycle is detected
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            dfs(i, adj, vis, pathVis, st, cycle);
    }
    if (cycle)
        return {};              // No topological sort if graph contains a cycle
    vector<int> ans;
    // Reverse the DFS finishing order
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
vector<int> topoSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0); // Number of incoming edges for each node
    // Calculate indegree of every vertex
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
    queue<int> q; // Stores vertices whose indegree is currently 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans; // Stores the topological ordering
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        // Remove the outgoing edges of u
        for (int v : adj[u]) {
            indegree[v]--;
            // v is now ready to be processed
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    // If not all vertices were processed, a cycle exists
    if (ans.size() != V)
        return {};
    return ans;
}
int main() {
    int V = 6; // Number of vertices
    // adj[u] contains all vertices directly reachable from u
    vector<vector<int>> adj = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };
    // Topological Sort using DFS
    vector<int> dfsAns = topoSortDFS(V, adj);
    cout << "Topological Sort (DFS): ";
    for (int node : dfsAns)
        cout << node << " ";
    cout << '\n';
    // Topological Sort using Kahn's Algorithm
    vector<int> kahnAns = topoSortKahn(V, adj);
    cout << "Topological Sort (Kahn): ";
    for (int node : kahnAns)
        cout << node << " ";
    cout << '\n';
    return 0;
}