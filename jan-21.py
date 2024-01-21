from typing import List, Tuple

class Solution:
    def vertexCover(self, n: int, edges: List[Tuple[int, int]]) -> int:
        ans = float('inf')
        
        for mask in range(1 << n):
            ok = True
            
            for u, v in edges:
                if not (mask & (1 << (u - 1))) and not (mask & (1 << (v - 1))):
                    ok = False
                    break
            
            if ok:
                ans = min(ans, bin(mask).count('1'))
                
        return ans
