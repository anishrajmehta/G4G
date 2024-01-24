#User function Template for python3
from collections import defaultdict

class Solution:
    def findOrder(self, n, m, prerequisites):
        # Code here
        adjacency_list = defaultdict(list)
        for pair in prerequisites:
            adjacency_list[pair[1]].append(pair[0])

        visited = [0] * n
        recStack = [0] * n
        result = []

        def dfs(node):
            visited[node] = 1
            recStack[node] = 1

            for neighbor in adjacency_list[node]:
                if visited[neighbor] == 0:
                    if dfs(neighbor) == True:
                        return True
                elif recStack[neighbor] == 1:
                    return True

            recStack[node] = 0
            result.append(node)
            return False

        for node in range(n):
            if visited[node] == 0:
                if dfs(node) == True:
                    return []

        return result[::-1]
