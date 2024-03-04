class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        n_tmp = n
        
        for b in range(2, n - 1):
            temp = 0
            while n_tmp / b:
                temp = temp * b + n_tmp % b
                n_tmp /= b
            temp = b * temp + n_tmp
            if temp != n: return False
            
        return True
                
        
        