class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i = left; i <= right; i++){
            if(isprime(i)){
                primes.push_back(i);
            }
        }
        if(primes.size() < 2) return {-1, -1};
        int minDiff = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i = 1; i < primes.size(); i++){
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff){
                minDiff = diff;
                ans = {primes[i-1], primes[i]};
            }
        }
        return ans;
    }
};