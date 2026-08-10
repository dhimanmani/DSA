class Solution {
public:
    void generatesubsets(int i, vector<vector<int>>& res, vector<int>& nums, vector<int>&currsub){
        if(i==nums.size()){
            res.push_back(currsub);
            return;
        }
        generatesubsets(i+1, res, nums, currsub);
        currsub.push_back(nums[i]);
        generatesubsets(i+1, res, nums, currsub);
        currsub.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n= nums.size();
        vector<int>currsub;
        generatesubsets(0, res, nums, currsub);
        return res;
    }
};