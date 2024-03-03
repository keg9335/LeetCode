class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        self.backtrack(s, [], result)
        
        return result
        
    def backtrack(self, s, element, result):
        if not s: 
            result.append(element)
            
        for i in range(len(s)):
            if self.palindrome(s[:i+1]):
                element.append(s[:i+1])
                self.backtrack(s[i+1:], element[:], result)
                element.pop()
    
    def palindrome(self, s):
        return s == s[::-1]