class Solution:
    def printPaths(self, root, sum):
        #code here
        path = []
        all_paths = []
        self.printPathRec(root, sum, path, all_paths)
        return all_paths
        
    def printPathRec(self, node, sum, path, all_paths):
        if not node:
            return
        
        path.append(node.data)
        
        sum -= node.data
        
        if sum == 0:
            all_paths.append(list(path))
            
        if node.left is not None:
            self.printPathRec(node.left, sum ,path, all_paths)
            
        if node.right is not None:
            self.printPathRec(node.right, sum, path, all_paths)
            
        path.pop()
