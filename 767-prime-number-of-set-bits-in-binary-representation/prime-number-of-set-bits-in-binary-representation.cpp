class Solution {
public:
    bool prime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    string dectobin(int n){
        int len= (int)(log2(n));
        return bitset<64>(n).to_string().substr(64-len-1);
    }
    bool countset(int n){
        string bin= dectobin(n);
        int c=0;
        for(int i=0; i<bin.size(); i++){
            if(bin[i]=='1'){
                c++;
            }
        }
        bool ans=prime(c);
        return ans;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left; i<=right; i++){
            if(countset(i)) count++;
        }
        return count;
    }
};