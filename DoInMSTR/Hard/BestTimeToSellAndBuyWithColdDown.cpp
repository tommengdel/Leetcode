class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size() + 2, 0);
        int n = prices.size();
        for(int i = n - 2; i >= 0; --i) {
            //Compute profit[i]
            //fetch the buy point
            int buyPoint = i;
            while(buyPoint + 1 < prices.size() && prices[buyPoint] > prices[buyPoint + 1]) ++buyPoint;
            int sellPoint = buyPoint + 1;
            while(sellPoint + 1 < prices.size() && prices[sellPoint] < prices[sellPoint + 1]) ++sellPoint;

            if(sellPoint < prices.size() && buyPoint < prices.size()) {
               int profit1 = prices[sellPoint] - prices[buyPoint];
               int profit2 = prices[sellPoint - 1] - prices[buyPoint];

               profit[i] = max(profit[i], profit1 + profit[sellPoint + 2]);
               profit[i] = max(profit[i], profit2 + profit[sellPoint - 1 + 2]);
            }
        }

        return profit[0];
    }
};
//Error Case: [6,1,3,2,4,7] Expected: 6 Result: 5
