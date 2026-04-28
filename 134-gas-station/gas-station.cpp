class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int start= n-1;
        int end= n-1;
        int station=0, gascost=0;
        while(station<n){
            gascost+= gas[end]- cost[end];
            station+=1;
            end = (end + 1) % n;
            while (gascost < 0 && station < n) {
                start--;
                gascost += gas[start] - cost[start];
                station++;
            }
        }
        return gascost<0 ? -1: start;
    }
};