class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int start=0, currgas=0, totalgas=0;
        for(int i=0; i<n; i++){
            currgas+=(gas[i]- cost[i]);
            totalgas+=(gas[i]- cost[i]);
            if(currgas<0){
                currgas=0;
                start=i+1;
            }
        }
        if(totalgas<0) return -1;
        return start;
    }
};