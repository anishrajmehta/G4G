#User function Template for python3

class Solution:
    def matrixChainOrder(self, p, n):
        # code here
        m = [[0 for x in range(n)] for x in range(n)]
        s = [[0 for x in range(n)] for x in range(n)]
        
        for i in range(1, n):
            m[i][i] = 0

        for L in range(2, n):
            for i in range(1, n - L + 1):
                j = i + L - 1
                m[i][j] = float('inf')
                for k in range(i, j):
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                    if q < m[i][j]:
                        m[i][j] = q
                        s[i][j] = k

        return self.printParenthesis(1, n - 1, n, s)

    def printParenthesis(self, i, j, n, s):
        matrix = [chr(x) for x in range(ord('A'), ord('A') + n)]
        if i == j:
            return matrix[i - 1]
        else:
            return "(" + self.printParenthesis(i, s[i][j], n, s) + self.printParenthesis(s[i][j] + 1, j, n, s) + ")"
