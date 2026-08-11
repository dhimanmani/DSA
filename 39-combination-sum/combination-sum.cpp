class Solution {
public:
    void solve(int i, int target, vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int n){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<nums[i]){
            return;
        }
        for(int j=i; j<n; j++){
            curr.push_back(nums[j]);
            solve(j, target-nums[j], res, curr, nums, n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>curr;
        solve(0, target, res, curr, candidates, n);
        return res;
    }
};