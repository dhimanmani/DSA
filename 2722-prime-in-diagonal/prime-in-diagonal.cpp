class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>v;
        int k=n-1;
        for(int i=0; i<n; i++){
            v.push_back(nums[i][i]);
            v.push_back(nums[i][k--]);
        }
        int maxele=0;
        int ele=0;
        for(int e: v){
            if(isprime(e)){
                ele=e;
            }
            maxele=max(maxele, ele);
        }
        return maxele;
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