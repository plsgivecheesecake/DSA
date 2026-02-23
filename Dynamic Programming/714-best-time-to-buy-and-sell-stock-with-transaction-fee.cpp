class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         //lest cobvert int memo
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
     
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
         int profit=0;
        
        if(buy)
        {
           
            int not_buy= dp[index+1][1];
            int buy= -prices[index]+ dp[index+1][0];
            profit=max(buy,not_buy);
        }
        else
        {
            
            int sell=prices[index]-fee+dp[index+1][1];
            int not_sell=dp[index+1][0];
            profit=max(sell,not_sell);
        }
       dp[index][buy]=profit;
            }
        }

        return dp[0][1];
    }
};