class Solution:
    def kTop(self, a, N, K):
        freq = {}
        top_k = []
        result = []
        
        for num in a:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
            
            if num not in top_k:
                top_k.append(num)
            
            top_k.sort(key = lambda x: (-freq[x], x))
            
            if len(top_k) > K:
                top_k.pop()
            
            result.append(top_k[:])
        
        return result