class Solution {
public:
    int set(string word){
        unordered_set<char>s;
        for(char c: word)
            s.insert(c);
        return s.size();
    }
    int maxFreq(string s, int maxletters, int minsize, int maxsize) {
        unordered_map<string, int>freq;
        int n= s.size();
        int i=0;
        while(i<=n-minsize){
            string temp= s.substr(i, minsize);
            if(set(temp)<=maxletters){
                freq[temp]++;
            }
            i++;
        }
        int maxocc=0;
        for(auto it: freq)
            maxocc= max(maxocc, it.second);
        return maxocc;
    }
};