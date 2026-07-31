class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxend= nums[0], minend= nums[0], ans= nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]<0) swap(maxend, minend);
            maxend= max(nums[i], maxend*nums[i]);
            minend= min(nums[i], minend*nums[i]);
            ans= max(ans, maxend);
        }
        return ans;
    }
};