class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n= ages.size();
        vector<pair<int, int>>teams;
        for(int i=0; i<n; i++)
            teams.push_back({ages[i], scores[i]});
        sort(teams.begin(), teams.end());
        vector<int>dp(n);
        for(int i=0; i<n; i++){
            dp[i]= teams[i].second;
        }
        int maxscore=dp[0];
        for(int i=1; i<n; i++){
            int agei= teams[i].first, scorei= teams[i].second;
            for(int j= 0; j<i; j++){
                int agej= teams[j].first, scorej= teams[j].second;
                if(agei== agej || scorej<= scorei){
                    dp[i]= max(dp[i], dp[j]+scorei);
                }
            }
            maxscore= max(maxscore, dp[i]);
        }
        return maxscore;
    }
};