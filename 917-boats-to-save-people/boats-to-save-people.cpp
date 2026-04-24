class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size();
        int i=0, j=n-1, count=0;
        sort(people.begin(), people.end());
        while(i<=j && j>=i){
            if(people[j]==limit){
                count++;
                j--;
            }
            else if(people[i]+people[j]<=limit){
                count++;
                i++, j--;
            }
            else if(people[i]+people[j]>=limit){
                count++;
                j--;
            }
            else{
                i++;
            }
        }
        return count;
    }
};