class Solution {
public:
    void solve(int index, vector<vector<int>>& res, vector<int>& curr, vector<bool>& vis, vector<int>& nums){
        int n= nums.size();
        if(index==n){
            res.push_back(curr);
            return;
        }
        int i=0;
        while(i<n){
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]){
                i++;
                continue;
            }
            if(!vis[i]){
                vis[i]=true;
                curr[index]=nums[i];
                solve(index+1, res, curr, vis, nums);
                vis[i]=false;
            }
            i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>curr(n);
        vector<bool>vis(n);
        solve(0, res, curr, vis, nums);
        return res;
    }
};