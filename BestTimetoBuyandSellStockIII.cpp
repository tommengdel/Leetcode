#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxPro = 0;
        for(int i = 2; i <= prices.size(); ++i) {
            maxPro = max(maxPro, maxProfit(prices, 0, i) + maxProfit(prices, i, prices.size()));
        }
	return maxPro;
    }
    
    int maxProfit(vector<int>& prices, int low, int high) {
        int maxPro = 0;
        if(high - low < 2) return 0;
        int minval = prices[low];
        for(int i = low + 1;  i < high; ++i) {
            maxPro = max(prices[i] - minval, maxPro);
            minval = min(minval, prices[i]);
        }
	return maxPro;
    }
};


int main() {
	vector<int> prices = {1, 2};
	cout<<Solution().maxProfit(prices);
}
//���©д����ֵ���������
//Big Data: Time Limit Exceeded
//���뵽��һ������ʱ��Ľⷨ
//���ĸ�����
//min1, min2, max1, max2;
//������RMQ����ĳɷ��ڡ�
