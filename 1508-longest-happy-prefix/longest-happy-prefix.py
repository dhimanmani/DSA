class Solution:
    def longestPrefix(self, s: str) -> str:
        n= len(s)
        if len(s)<=1:
            return ""
        Base= 131
        Mod= 10**9+7
        power=1
        suffix=0
        prefix=0
        res=0
        for i in range(n-1):
            prefix= (prefix*Base + ord(s[i]))%Mod
            suffix= (suffix + ord(s[n-i-1])*power)%Mod
            power= (power*Base)%Mod
            if suffix==prefix:
                res=i+1
        return s[:res]