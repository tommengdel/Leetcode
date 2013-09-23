//At Most means you can do none transaction
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //int minval = prices[0];
        if(prices.size() < 2) return 0;
        int minval = prices[0];
        int maxPro = 0;//Important!!
        //int maxPro = prices[1] - prices[0];
        for(int i = 1; i < prices.size(); ++i)  {
            maxPro = max(prices[i] - minval, maxPro);
            minval = min(prices[i], minval);
        }
        return maxPro;
    }
};
//Test case: [2,1] []
