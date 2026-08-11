class Solution {
public:
    void solve(int i, int target, vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int n){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int j=i; j<n; j++){
            if(j>i && nums[j]== nums[j-1]){
                continue;
            }
            if(nums[j]>target){
                break;
            }
            curr.push_back(nums[j]);
            solve(j+1, target-nums[j], res, curr, nums, n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>curr;
        solve(0, target, res, curr, candidates, n);
        return res;
    }
};