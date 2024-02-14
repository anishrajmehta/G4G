/*

14 February 2024

A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.

Example 1:

Input:

Output:
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to
reach node 0 and 2 from node 1. Also, on removing
edge (0, 2), you will not be able to reach node 0
and 1 from node 2.
Example 2:

Input:

Output:
2 3
Explanation:
The edge between nodes 2 and 3 is the only
Critical connection in the given graph.
Your task:
You dont need to read input or print anything. Your task is to complete the function criticalConnections() which takes the integer v denoting the number of vertices and an adjacency list adj as input parameters and returns  a list of lists containing the Critical connections in the sorted order.

Expected Time Complexity: O(v + e)
Expected Auxiliary Space: O(v)

Constraints:
1 ≤ v, e ≤ 10^4

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<int>> criticalConnections(int V, vector<int> adj[]) {
        // Code here
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<vector<int>> bridges;
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, adj, disc, low, parent, bridges);
            }
        }
        sort(bridges.begin(), bridges.end());
        return bridges;
    }

private:
    void dfs(int u, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& bridges) {
        static int time = 0;
        disc[u] = low[u] = time++;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                parent[v] = u;
                dfs(v, adj, disc, low, parent, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    vector<int> edge = {u, v};
                    sort(edge.begin(), edge.end());
                    bridges.push_back(edge);
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends
