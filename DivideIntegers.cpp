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

//��������ѭ����������ף�����1<<31�����ָ������������ı�ʾ�� �ǳ��ĵ���
//���ң���absҲ�Ǵ���ġ� ��Ϊ���������һ�� ��������
//abs(INT_MIN)����Ҳ�ᵼ��δ�������Ϊ��
//����V2
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool sign = false;
        //Xor is a better operation for decide sign
        int mask = 1<<(sizeof(int) * 8 - 1);
        if(divisor == 0) return 0;
        //if((dividend & mask)^(divisor & mask) != 0) sign = true;��仰����-1, -1������������
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
//����Ĳ������� -1 -1
//ԭ��^��������ȼ���!=��
int main() {
//	cout<<Solution().divide(2147483647, 1);
	cout<<Solution2().divide(-1, -1);
}

