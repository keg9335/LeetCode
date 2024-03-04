class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:        
        return self.isPalindrome(a, b) or self.isPalindrome(b, a) # a_prefix + b_suffix, b_prefix + a_suffix

    
    def isPalindrome(self, s1: str, s2: str) -> bool:
        i, j = 0, len(s1)-1

        while (i < j):
            if s1[i] != s2[j]: # 문자가 일치하지 않는 지점을 찾음 (i~j)
                break
            i += 1
            j -= 1
        
        sub_s1 = s1[i:j+1] # s1의 i~j 위치 문자 추출
        sub_s2 = s2[i:j+1]

        return (sub_s1 == sub_s1[::-1]) or (sub_s2 == sub_s2[::-1])