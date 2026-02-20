class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int>freq;
        unordered_map<int, int>freqcount;
        for(int n: nums)
            freq[n]++;
        for(auto &f: freq)
            freqcount[f.second]++;
        for(int x: nums){
            if(freqcount[freq[x]]==1){
                return x;
            }
        }
        return -1;
    }
};