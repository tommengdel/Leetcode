class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = false;
        double ret = 1.0;
        if(x == 1) return 1;
        if(n < 0) neg = true;
        n = abs(n);
        int digit;
        for(digit = 31; digit >= 0; --digit) 
            if(((1 << digit) & n) != 0) break;
        for(;digit >= 0; --digit) {
            ret = ret * ret;
            if(((1<<digit) & n) != 0) ret *= x;
        }
        if(neg) ret = 1 / ret;
        return ret;
        
    }
};

//此算法源自算法导论
