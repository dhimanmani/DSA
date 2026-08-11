class Solution {
public:
    void solve(int index, vector<int>& curr, vector<vector<int>>& res, vector<bool>& vis, vector<int>& nums){
        int n= nums.size();
        if(index==n){
            res.push_back(curr);
            return;
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i]= true;
                curr[index]= nums[i];
                solve(index+1, curr, res, vis, nums);
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>res;
        vector<bool>vis(n);
        vector<int>curr(n);
        solve(0, curr, res, vis, nums);
        return res;
    }
};