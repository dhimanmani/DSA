class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0; i<n; i++){
            vector<int>freq(26, 0);
            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;
                int minf=INT_MAX;
                int maxf=INT_MIN;
                for(int k=0; k<26; k++){
                    if(freq[k]>0){
                        minf=min(minf, freq[k]);
                        maxf=max(maxf, freq[k]);
                    }
                }
                sum+=(maxf-minf);
            }
        }
        return sum;
    }
};