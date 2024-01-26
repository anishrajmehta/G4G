class Item:
    def __init__(self,val,w):
        self.value = val
        self.weight = w
        
class Solution:    
    #Function to get the maximum total value in the knapsack.
    def fractionalknapsack(self, W,arr,n):
        
        # code here
        arr.sort(key = lambda x: x.value/x.weight, reverse=True)
        
        res = 0.0  # Result (value in Knapsack)
        for i in range(n):
            if arr[i].weight <= W:
                res += arr[i].value
                W -= arr[i].weight
            else:
                res += arr[i].value * (W / arr[i].weight)
                break
        return res
