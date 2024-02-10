/*

10 February 2024

Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

Example 1:

Input:
k = 12, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [3, 2, 1]]
Output: 
2
Explanation: 
There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
Example 2:

Input:
k = 16, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [9, 8, 7]]
Output: 
0 
Explanation: 
There are no possible paths that lead to sum=16
Your Task:  
You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes n, k and 2D matrix arr[][] as input parameters and returns the number of possible paths.

Expected Time Complexity: O(n*n*k)
Expected Auxiliary Space: O(n*n*k)

Constraints:

1 <= k < 100
1 <= n < 100
0 <= arrij <= 200
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
public:
    long long calculatePaths(vector<vector<int>> &arr, int i, int j, int k, vector<vector<vector<long long>>> &dp) 
    {
        if(i < 0 || j < 0 || k < 0) 
        {
            return 0;
        }

        if(i == 0 && j == 0) 
        {
            return (k == arr[i][j]) ? 1 : 0;
        }

        if(dp[i][j][k] != -1) 
        {
            return dp[i][j][k];
        }

        long long fromTop = calculatePaths(arr, i - 1, j, k - arr[i][j], dp);
        long long fromLeft = calculatePaths(arr, i, j - 1, k - arr[i][j], dp);

        return dp[i][j][k] = fromTop + fromLeft;
    }

    long long numberOfPath(int n, int k, vector<vector<int>> &arr) 
    {
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));

        return calculatePaths(arr, n - 1, n - 1, k, dp);
        // Code Here
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
