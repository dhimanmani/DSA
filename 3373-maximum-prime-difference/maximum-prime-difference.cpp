class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=n-1;
        while(left<=right){
            if(!(isprime(nums[left]))){
                left++;
                continue;
            }
            if(!(isprime(nums[right]))){
                right--;
                continue;
            }
            return abs(right-left);
        }
        return 0;
    }
};