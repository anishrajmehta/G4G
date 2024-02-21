/*

21 February 2024

Given a boolean expression s of length n with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer can be large, so return it with modulo 1003

Example 1:

Input: 
n = 7
s = T|T&F^T
Output: 
4
Explaination: 
The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: 
n = 5
s = T^F|F
Output: 
2
Explaination: 
((T^F)|F) and (T^(F|F)) are the only ways.
Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes n and s as input parameters and returns number of possible ways modulo 1003.

Expected Time Complexity: O(n3)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ n ≤ 200 

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        int n = N/2 + 1;
        vector<vector<int>> T(n, vector<int>(n, 0));
        vector<vector<int>> F(n, vector<int>(n, 0));
        int mod = 1003;

        for (int i = 0; i < n; i++) {
            F[i][i] = (S[2*i] == 'F') ? 1 : 0;
            T[i][i] = (S[2*i] == 'T') ? 1 : 0;
        }

        for (int gap = 1; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                T[i][j] = F[i][j] = 0;
                for (int g = 0; g < gap; g++) {
                    int k = i + g;

                    int tik = (T[i][k] + F[i][k]) % mod;
                    int tkj = (T[k+1][j] + F[k+1][j]) % mod;

                    if (S[2*k+1] == '&') {
                        T[i][j] += (T[i][k] * T[k+1][j]) % mod;
                        F[i][j] += ((tik * tkj - T[i][k] * T[k+1][j]) % mod + mod) % mod;
                    }
                    if (S[2*k+1] == '|') {
                        F[i][j] += (F[i][k] * F[k+1][j]) % mod;
                        T[i][j] += ((tik * tkj - F[i][k] * F[k+1][j]) % mod + mod) % mod;
                    }
                    if (S[2*k+1] == '^') {
                        T[i][j] += ((F[i][k] * T[k+1][j] + T[i][k] * F[k+1][j]) % mod + mod) % mod;
                        F[i][j] += ((T[i][k] * T[k+1][j] + F[i][k] * F[k+1][j]) % mod + mod) % mod;
                    }
                    T[i][j] %= mod;
                    F[i][j] %= mod;
                }
            }
        }
        return T[0][n-1];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
