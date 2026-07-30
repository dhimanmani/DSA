class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>onoff(100, false);
        for(int b: bulbs){
            onoff[b]=!onoff[b];
        }
        vector<int>ans;
        for(int i=1; i<=100; i++){
            if(onoff[i]) ans.push_back(i);
        }
        return ans;
    }
};