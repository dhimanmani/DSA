class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_map<int, int>freq;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=2; j<=nums[i]; j++){
                if(isprime(j) && (nums[i]%j)==0){
                    freq[j]++;
                }
            }
        }
        int count=0;
        for(auto it: freq){
            if(it.first) count++;
        }
        return count;
    }
};