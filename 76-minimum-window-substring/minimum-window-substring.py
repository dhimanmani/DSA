class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans=""
        if(len(s)<len(t)):
            return ans
        need=Counter(t)
        window={}
        required=len(need)
        formed=0
        l=0
        minlen=float("inf")
        for r in range(len(s)):
            ch=s[r]
            window[ch]=window.get(ch, 0)+1
            if ch in need and window[ch] == need[ch]:
                formed += 1
            while formed == required:
                if (r - l + 1) < minlen:
                    minlen = r - l + 1
                    ans = s[l:r+1]
                left_char = s[l]
                window[left_char] -= 1
                if left_char in need and window[left_char] < need[left_char]:
                    formed -= 1
                l += 1
        return ans

        
            
