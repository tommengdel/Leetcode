#include<iostream>
#include<numeric>
using namespace std;

class Solution {
    bool InRange(int v , int below, int above) { return v >= below && v <= above; }
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int rx = 0; 
	int t = x;
	while(t != 0) {
	  int d = t % 10;
	  if(!InRange(rx, (numeric_limits<int>::min() - d) / 10, (numeric_limits<int>::max() - d) / 10)) return false;//"min delete d" is a big mistake 
	  rx = rx * 10 + d;
	  t = t / 10;
	  //min<= rx * 10 + t % 10 <= max
	}
	return rx == x;
        
    }
};

int main() {
	int a[] = {1, 0, 101, numeric_limits<int>::min(), numeric_limits<int>::max()}
	cout<<Test(1);
}

int Test(int x[], int n) {
	for(int i = 0; i < n; ++i) cout<<Test(x[i])<<endl;
}
bool Test(int x) {
	return Solution().isPalindrome(x);
}


