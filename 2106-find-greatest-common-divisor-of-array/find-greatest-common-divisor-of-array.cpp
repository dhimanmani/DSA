class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        int n=nums.size();
        int ans=1;
        for(int i=0; i<n; i++){
            if(nums[i]<mn) mn=nums[i];
            if(nums[i]>mx) mx=nums[i];
        }
        for(int i=1; i<=mn; i++){
            if(mn%i==0 && mx%i==0) ans=i;
        }
        return ans;
    }
};