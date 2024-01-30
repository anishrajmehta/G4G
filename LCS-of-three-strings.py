"""
Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

Example 1:

Input:
A = "geeks"
B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: 
"geeks"is the longest common
subsequence with length 5.
Example 2:

Input: 
A = "abcd"
B = "efgh"
C = "ijkl"
Output: 0
Explanation: 
There's no subsequence common
in all the three strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings consitutes only of the lower case english alphabets.
"""
#User function Template for python3

class Solution:

    def LCSof3(self,A,B,C,n1,n2,n3):
        # code here
        dp = [[[0 for _ in range(n3+1)] for _ in range(n2+1)] for _ in range(n1+1)]
        
        for i in range(n1+1):
            for j in range(n2+1):
                for k in range(n3+1):
                    if i == 0 or j == 0 or k == 0:
                        dp[i][j][k] = 0
                    elif A[i-1] == B[j-1] == C[k-1]:
                        dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                    else:
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])
        
        return dp[n1][n2][n3]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        n1,n2,n3 = map(int,input().split())
        A,B,C = input().split()

        solObj = Solution()

        ans = solObj.LCSof3(A,B,C,n1,n2,n3)

        print(ans)
# } Driver Code Ends
