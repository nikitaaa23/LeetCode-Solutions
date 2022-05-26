class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn = prices[0]
        mx = 0
        
        for p in prices:
            if mn > p:
                mn = p
            if mx < p - mn:
                mx = p - mn
        return mx