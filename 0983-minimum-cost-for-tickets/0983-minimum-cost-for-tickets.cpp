// class Solution {
//     int solve(vector<int>& days, vector<int>& costs, int i, int validity) {
//         if(i >= days.size())
//             return 0;
        
//         if(days[i] <= validity)
//             return solve(days, costs, i+1, validity);
//         else {
//             int ch1 = costs[0] + solve(days, costs, i+1, days[i]);
//             int ch2 = costs[1] + solve(days, costs, i+1, days[i]+6);
//             int ch3 = costs[2] + solve(days, costs, i+1, days[i]+29);
//             return min(ch1, min(ch2, ch3));
//         }
//     }
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         return solve(days, costs, 0, 0);
//     }
// };


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[366];
        memset(dp, 0, sizeof(dp));
        
        for(auto day: days)
            dp[day] = costs[0];
        for(int i = 1; i <= days[n-1]; i++){
            if(!dp[i])
                dp[i] = dp[i-1];
            else{
                dp[i] = dp[i-1] + costs[0];
                int j = max(0, i-7);
                dp[i] = min(dp[i], dp[j] + costs[1]);
                j = max(0, i-30);
                dp[i] = min(dp[i], dp[j] + costs[2]);
            }
        }
        
        return dp[days[n-1]];
    }
};