#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int buyPoint = 0, sellPoint;
        int maxPro = 0;
	if(prices.size() == 0) return maxPro;	
	//通过将(prices.size() - 1) 转换成signed int可以避免这个问题
//	cout<<prices.size()<<endl;//0
//	cout<<prices.size() - 1<<endl; //2^32 - 1
//	size_t : unsigned int
	//-1的补码：FFFF prices.size():0000 作为无符号数的FFFF 就是2 ^ 32 - 1
        while(buyPoint < (prices.size() - 1) && prices[buyPoint] >= prices[buyPoint + 1]) ++buyPoint;
        
        while(buyPoint < (prices.size() - 1)) {
            sellPoint = buyPoint + 1;
            while(sellPoint < prices.size() - 1 && prices[sellPoint] <= prices[sellPoint + 1]) sellPoint++;
            maxPro += prices[sellPoint] - prices[buyPoint];
            //Update the buy Point
            buyPoint = sellPoint + 1;
            while(buyPoint < prices.size() - 1 && prices[buyPoint] >= prices[buyPoint + 1]) ++buyPoint;
        }
        return maxPro;
    }
};


int main() {
	vector<int> prices;
	Solution().maxProfit(prices);

}
