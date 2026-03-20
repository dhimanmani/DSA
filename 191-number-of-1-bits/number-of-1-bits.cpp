class Solution {
public:
    string dectobin(int n){
        int len= (int)(log2(n));
        return bitset<64>(n).to_string().substr(64-len-1);
    }
    int hammingWeight(int n) {
        string bin= dectobin(n);
        int count=0;
        for(int i=0; i<bin.size(); i++){
            if(bin[i]=='1') count++;
        }
        return count;
    }
};