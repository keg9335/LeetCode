class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k : return False
        freq = {}
        odd = 0
        
        for c in s:
            if c not in freq.keys():
                freq[c] = 1
            else: freq[c] += 1
                
        for _, item in freq.items():
            if item % 2: odd += 1
        
        return odd <= k