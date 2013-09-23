#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool sign = false;
        //Xor is a better operation for decide sign
        int mask = 1<<(sizeof(int) * 8 - 1);
        if(divisor == 0) return 0;
        if((dividend & mask)^(divisor & mask) != 0) sign = true;
        dividend = abs(dividend); divisor = abs(divisor);
        int quotient = 0;        
        while(dividend >= divisor) {
            int shift = 0;
            while(dividend >= (divisor<<(shift + 1))) shift++; 
            dividend -= (divisor<<shift);
            quotient += 1<<shift;
        }
        if(sign) quotient = 0 - quotient;
        return quotient;
    }
};

//此题无限循环，归根到底，在于1<<31则会出现负数。此乃数的表示。 非常的蛋疼
//而且，用abs也是错误的。 因为负数的最大一个 比正数大
//abs(INT_MIN)本来也会导致未定义的行为。
//代码V2
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool sign = false;
        //Xor is a better operation for decide sign
        int mask = 1<<(sizeof(int) * 8 - 1);
        if(divisor == 0) return 0;
        //if((dividend & mask)^(divisor & mask) != 0) sign = true;这句话导致-1, -1测试用例出错
	if(((dividend & mask)^(divisor & mask)) != 0) sign = true;
        int quotient = 0;
        if(divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
        if(dividend == INT_MIN) {
            if(sign) dividend += divisor;
            else dividend -= divisor;
            quotient += 1;
        }
        
        dividend = abs(dividend); divisor = abs(divisor);
                
        while(dividend >= divisor) {
            int shift = 0;
            while((dividend>>(shift + 1)) >= (divisor)) shift++;
            dividend -= (divisor<<shift);
            quotient += 1<<shift;
        }
        if(sign) quotient = 0 - quotient;
        return quotient;
    }
};
//错误的测试用例 -1 -1
//原因：^运算符优先级比!=低
int main() {
//	cout<<Solution().divide(2147483647, 1);
	cout<<Solution2().divide(-1, -1);
}

