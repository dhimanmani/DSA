class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int, int>freq;
        for(int i: bulbs){
            freq[i]++;
        }
        int n=bulbs.size();
        vector<int>res;
        for(auto &it: freq){
            if(it.second%2!=0){
                res.push_back(it.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};