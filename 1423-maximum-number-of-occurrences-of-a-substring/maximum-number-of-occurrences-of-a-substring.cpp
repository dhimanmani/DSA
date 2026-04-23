class Solution {
public:
    int maxFreq(string s, int maxletters, int minsize, int maxsize) {
        unordered_map<string, int>freq;
        int maxocc=0, n=s.size();
        for(int i=0; i<=n-minsize; i++){
            string temp= s.substr(i, minsize);
            unordered_set<char>st(temp.begin(), temp.end());
            if(st.size()<=maxletters){
                freq[temp]++;
                maxocc= max(maxocc, freq[temp]);
            }
        }
        return maxocc;
    }
};