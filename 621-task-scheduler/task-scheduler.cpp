class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        int maxfreq=0;
        for(char c: tasks){
            int index= c-'A';
            freq[index]++;
            maxfreq= max(maxfreq, freq[index]);
        }
        int count=0;
        for(int f: freq){
            if(f== maxfreq)
                count++;
        }
        int minslot= (maxfreq-1)*(n+1)+count;
        if(tasks.size()>minslot) return tasks.size();
        else return minslot;
    }
};