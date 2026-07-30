class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int, int>freq;
        int n= bulbs.size();
        vector<int>res;
        for(int i=0; i<n; i++){
            freq[bulbs[i]]++;
        }
        for(auto &it: freq){
            if(it.second % 2!=0){
                res.push_back(it.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};