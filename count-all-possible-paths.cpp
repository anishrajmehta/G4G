/*

15 February 2024

You are presented with an undirected connected graph consisting of n vertices and connections between them represented by an adjacency matrix. Your objective is to determine whether it is possible to start traversing from a node, x, and return to it after traversing all the vertices at least once, using each edge exactly once.

Example 1:

Input: 
paths = 0 1 1 1 1
        1 0 0 1 0
        1 0 0 1 0
        1 1 1 0 1
        1 0 0 1 0
Output: 1
Explanation: 
One can visit the vertices in the following way:
1->3->4->5->1->4->2->1 (assuming 1-based indexing)
Here all the vertices has been visited and all
paths are used exactly once.
Example 2:

Input: 
paths = 0 1 1 0
        1 0 1 1
        1 1 0 0
        0 1 0 0
Output: 0
Explanation: 
There exists no such vertex from which all the 
vertices could be visited and all edges are used 
exactly once.
Your Task:
You don't need to read or print anything. Your task is to complete the function isPossible() which takes adjacency matrix paths as an input parameter and returns 1 if it is possible to start traversing from a node, x, and come back to it after traversing all the vertices at least once, using each edge exactly once.

 Expected Time Complexity: O(n2)
Expected Space Compelxity: O(1)

Constraints:
1 <= n <= 100
0 <= paths[i][j] <= 1
Note: paths[i][j] = 0 where i == j or there exists no edge between i and j. paths[i][j] = 1 means there is a path between i to j.

*/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    int n = paths.size();
	    vector<int> in(n, 0), vis(n, 0);
	    vector<vector<int>> g(n);
	    
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(paths[i][j]){
	                g[i].push_back(j);
	                ++in[j];
	            }
	        }
	    }
	    
	    int odd = 0;
	    int cc = 0;
	    
	    function<void(int)> dfs = [&](int node) {
	        vis[node] = 1;
	        odd = odd or (in[node] & 1);
	        ++cc;
	        
	        for(auto child : g[node]) {
	            if(!vis[child])
	                dfs(child);
	        }
	    };
	    
	    dfs(0);
	    
	    return cc == n and !odd;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
