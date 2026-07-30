class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(128, 0);
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            while (vis[s[right]]) {
                vis[s[left]]--;
                left++;
            }
            vis[s[right]]++;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};