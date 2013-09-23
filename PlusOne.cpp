#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        ret.push_back(1);
        if(digits.size() == 0) {
            
            return ret;
        }
        int i = digits.size() - 1;
        int c = 0, radix = 10;
	/*
	 *My Mistake: while(i >= 0 && c != 0) 
	 *It make the statement always false.
	 */
        while(i >= 0) {
            digits[i] += 1  ;
            c = digits[i] / radix;
            digits[i] %= 10;
	    if(c == 0) break;
            i--;
        }
        
        if(c != 0) {
            copy(digits.begin(), digits.end(), back_inserter(ret));
	    return ret;
        }
        else return digits;
    }
};
int main() {
	int a[] = {3, 2, 3, 4, 4, 5};
	int b[] = {9,9,9};
	vector<int> num;
	cout<<endl;
	vector<int> ret = Solution().plusOne(num);
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ""));
	cout<<endl;
	num.assign(a, a + 6);
	ret = 	Solution().plusOne(num);
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ""));
	cout<<endl;
	num.assign(b, b + 3);
	ret = 	Solution().plusOne(num);
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ""));

}
//Not Test
//
//So important
//
//Below is Accepted at Leetcode.com
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        digits[digits.size() -1]  += 1;
        for(int i = digits.size() - 1; i > 0; --i) 
            if(digits[i] >= 10) {
                digits[i -1] += 1;
                digits[i] -= 10;
            }
        vector<int> ret;
        if(digits[0] >= 10) {
            digits[0] -= 10;
            ret.push_back(1);
            copy(digits.begin(), digits.end(), back_inserter(ret));
            return ret;
        }else return digits;
        
    }
};

