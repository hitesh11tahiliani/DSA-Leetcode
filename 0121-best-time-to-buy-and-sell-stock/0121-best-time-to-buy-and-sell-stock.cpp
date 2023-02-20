class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (buy > prices[i])
                buy = prices[i];
            else if (prices[i] - buy > max_profit)
                max_profit = prices[i] - buy;
        }
        return max_profit;
    }
};

// kadens algo 
// int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         int maxprofit = 0;
//         int minvalue = INT_MAX;
//         for(int i =0;i<n;i++){
//             minvalue = min(prices[i],minvalue);
//             maxprofit= max(maxprofit,prices[i] - minvalue);
//         }
//         return maxprofit;
//     }
