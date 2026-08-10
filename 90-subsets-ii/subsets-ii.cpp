class Solution {
public:
    void solve(int i, vector<vector<int>>& res, vector<int>& curr, vector<int>& nums){
        if(i>= nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1, res, curr, nums);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        solve(i+1, res, curr, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        int n= nums.size();
        vector<int>curr;
        sort(nums.begin(), nums.end());
        solve(0, res, curr, nums);
        return res;
    }
};