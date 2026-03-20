class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int n: nums) mp[n]++;
        for(auto it: mp){
            if(isprime(it.second)) return true;
        }
        return false;
    }
private:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
};