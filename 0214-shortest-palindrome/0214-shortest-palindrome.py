class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if self.isPalindrome(s): return s
        
        for i in range(1, len(s)+1):
            if self.isPalindrome(s[-1:-i-1:-1]+s):
                return s[-1:-i-1:-1]+s
        
    
    def isPalindrome(self, s):
        return s == s[::-1]
        