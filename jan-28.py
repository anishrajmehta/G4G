from typing import List

class Solution:
    def findNthNumber(self, n : int, k : int ) -> int:
        #code here
        low, high = 0, 10**18
        result = 0
        while low <= high:
            mid = low + (high - low) // 2
            count, _ = self.countNumbers(mid, k)
            if count >= n:
                result = mid
                high = mid - 1
            else:
                low = mid + 1
        return result

    def countNumbers(self, num: int, k: int) -> (int, int):
        dp = [[[0 for _ in range(65)] for _ in range(65)] for _ in range(2)]
        s = bin(num)[2:].zfill(64)
        return self.countNumbersDP(s, len(s), 1, k, dp), dp

    def countNumbersDP(self, s: str, n: int, tight: int, k: int, dp: List[List[List[int]]]) -> int:
        if k < 0:
            return 0
        if n == 0:
            return 1
        if dp[tight][k][n] != 0:
            return dp[tight][k][n]
        ub = int(s[len(s) - n]) if tight == 1 else 1
        res = 0
        for dig in range(ub + 1):
            dpf_val = self.countNumbersDP(s, n - 1, tight if dig == ub else 0, k - dig, dp)
            res += dpf_val
        dp[tight][k][n] = res
        return res
