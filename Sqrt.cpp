//Divide And Conquer
#include<iostream>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0) return 0;
        
        int mid;
        int low = 1, high = x;
        while(low < high) {
            int mid = low + (high - low ) / 2 + 1; // "+ 1" For [1, 2] mid is 2, not 1 . To avoid inifinite loop
            int t = x / mid;
            if(t == mid) return mid;
            else if( t < mid) high = mid - 1;
            else if( t > mid) low = mid;
        }
	cout<<"Low"<<endl;
        return low;
    }
};

int main() {
	for(int i = 1; i < 100000; ++i) {
		int sq = Solution().sqrt(i);
		if(!(sq * sq <= i && i< (sq + 1) * (sq + 1))) cout<<"Error"<<endl;

	}
	 
}

