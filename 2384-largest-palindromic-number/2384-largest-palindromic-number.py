class Solution:
    def largestPalindromic(self, num: str) -> str:
        numDict = {}
        for c in num:
            n = int(c)
            if n not in numDict.keys():
                numDict[n] = 1
            else: numDict[n] += 1
        val = ""
        for n in range(9, -1, -1):
            if n in numDict.keys() and numDict[n] % 2:
                val = str(n)
                numDict[n] -= 1
                break
            
        for n in range(0, 10):
            if n in numDict.keys():
                c = str(n)
                while numDict[n] > 1:
                    numDict[n] -= 2
                    val = c + val + c

        while len(val) > 2 and val[-1] == '0':
            val = val[1:-1]
        if len(val) == 2 and val[-1] == '0':
            val = val[0]
            
        return val
        
            
        