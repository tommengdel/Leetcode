#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    int binary_search(vector<int> &num, int low, int high, int target) {
        int mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(num[mid] == target) return mid;
            else if(num[mid] < target) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return -1;
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.size() < 3) return ret;
        sort(num.begin(), num.end());
        int prevTwoSum;
        bool Init = false;
        for(int i = 0; i < num.size() - 2; ++i) 
            for(int j = i + 1; j < num.size() - 1; ++j) {
                if(!Init) {
			Init = true;
			prevTwoSum = num[i] + num[j];
		}
                else {
                    if(prevTwoSum == num[i] + num[j]) continue;
		    
                    
                }
                int k =  binary_search(num, j + 1, num.size(), 0 - num[i] - num[j]);
                if(k != -1) {
                    ret.push_back(vector<int>());
                    ret.back().push_back(num[i]);
                    ret.back().push_back(num[j]);
                    ret.back().push_back(num[k]);
                }
                prevTwoSum = num[i] + num[j];
            }
        return ret;
    }
};

int main() {
	int a[] = {0,0, 0, 0};
	vector<int> num(a, a + 4);
	Solution().threeSum(num);
}
