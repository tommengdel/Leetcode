class Solution {
    bool InRange(int v, int below, int above) { return v >= below && v <= above; }
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int minInt = numeric_limits<int>::min();
        int maxInt = numeric_limits<int>::max();
        int rx = 0;
        while(x != 0) {
            int d = x % 10;
            if(!InRange(rx , minInt / 10 - d / 10, maxInt / 10 - d / 10)) return -1;
            rx = rx * 10 + d;
            x /= 10;
        }
        return rx;
    }
};

