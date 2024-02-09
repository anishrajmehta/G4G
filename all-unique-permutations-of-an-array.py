"""

17 January 2024

Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input: 
n = 2
arr[] = {4, 5}
Output: 
Only possible 2 unique permutations are
4 5
5 4
Your Task:
You don't need to read input or print anything. You only need to complete the function uniquePerms() that takes an integer n, and an array arr of size n as input and returns a sorted list of lists containing all unique permutations of the array.

Expected Time Complexity:  O(n*n!)
Expected Auxilliary Space: O(n*n!)

Constraints:
1 ≤ n ≤ 9
1 ≤ arri ≤ 9

"""

#User function Template for python3

class Solution:
    def uniquePerms(self, arr, n):
        result = []
        temp = []
        used = [False] * n

        def backtrack(idx):
            if idx == n:
                result.append(temp.copy())  # Store a copy of the permutation
                return

            for i in range(n):
                if not used[i]:
                    # Handle duplicates: Only consider elements not used or different from the previous one
                    if i > 0 and arr[i] == arr[i - 1] and not used[i - 1]:
                        continue

                    temp.append(arr[i])
                    used[i] = True
                    backtrack(idx + 1)
                    used[i] = False
                    temp.pop()

        arr.sort()  # Sort the array to generate permutations in sorted order
        backtrack(0)
        return result



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n=int(input())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        res = ob.uniquePerms(arr,n)
        for i in range(len(res)):
            for j in range(n):
                print(res[i][j],end=" ")
            print()
# } Driver Code Ends
