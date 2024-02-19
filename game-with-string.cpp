/*

19 February 2024

Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. 

Example 1:

Input: 
s = abccc, k = 1
Output: 
6
Explaination:
We remove c to get the value as 1^2 + 1^2 + 2^2
Example 2:

Input: 
s = aabcbcbcabcc, k = 3
Output: 
27
Explaination: 
We remove two 'c' and one 'b'. Now we get the value as 32 + 32 + 32.
Your Task:
You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

Expected Time Complexity: O(n+klog(p))  where n is the length of string and p is number of distinct alphabets and k number of alphabets to be removed. 
Expected Auxiliary Space: O(n)

Constraints:
0 ≤ k ≤ |string length| ≤ 10^5

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minValue(string s, int k) {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        
        priority_queue<int> q;
        for (int i = 0; i < 26; i++)
            q.push(freq[i]);
        
        while (k--) {
            int temp = q.top();
            q.pop();
            temp--;
            q.push(temp);
        }
        
        int result = 0; 
        while (!q.empty()) {
            int temp = q.top();
            result += temp * temp;
            q.pop();
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
