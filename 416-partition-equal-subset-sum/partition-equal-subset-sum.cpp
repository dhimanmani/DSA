class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x: nums) sum+=x;
        if(sum%2!=0) return false;
        int target= sum/2;
        vector<vector<bool>>dp(n, vector<bool>(target+1, false));
        for(int i=0; i<n; i++) dp[i][0]=true;
        if(nums[0]<=target){
            dp[0][nums[0]]= true;
        }
        for(int index=1; index<n; index++){
            for(int t=1; t<=target; t++){
                bool nottaken= dp[index-1][t];
                bool taken= false;
                if(nums[index]<=t){
                    taken= dp[index-1][t-nums[index]];
                }
                dp[index][t]= nottaken||taken;
            }
        }
        return dp[n-1][target];
    }
};