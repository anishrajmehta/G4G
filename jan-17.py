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
