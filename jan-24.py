class Solution:
    def isTree(self, n, m, edges):
        # Code here
        if m != n - 1:
            return 0

        adj = [[] for _ in range(n)]
        
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = [False] * (n)

        def dfs(v, p):
            visited[v] = True
            for u in adj[v]:
                if visited[u] == False:
                    if dfs(u, v) == False:
                        return False
                elif u != p:
                    return False
            return True

        if dfs(0, -1) == False or any(visited[i] == False for i in range(n)):
            return 0
        else:
            return 1
