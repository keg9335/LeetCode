class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        n_tmp = n
        
        for b in range(2, n - 1):
            temp = 0
            while n_tmp:
                temp = temp * b + n_tmp % b
                n_tmp /= b
            if temp != n: return False
            
        return True
                
        
        