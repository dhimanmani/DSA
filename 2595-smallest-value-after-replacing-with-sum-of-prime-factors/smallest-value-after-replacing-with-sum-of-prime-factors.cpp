class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        while(!isprime(n)){
            int sum=0, temp=n;
            for(int i = 2; i*i <= temp; i++){
                while(temp % i == 0){
                    sum += i;
                    temp /= i;
                }
            }
            if(temp > 1) sum += temp; 
            if(sum == n) break; 
            n = sum;
        }
        return n;
    }
};