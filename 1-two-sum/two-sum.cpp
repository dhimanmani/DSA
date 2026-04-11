class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>freq;
        for(int i=0; i<nums.size();i++){
            int comp= target-nums[i];
            if(freq.find(comp)!=freq.end()){
                return {freq[comp], i};
            }
            freq[nums[i]]=i;
        }
        return {};
    }
};