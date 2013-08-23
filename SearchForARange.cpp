#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	
        int leftInd, rightInd; 
        int low = 0, high = n - 1, mid;
        vector<int> ret;
        
        //Find the right index
        while(low < high) {
            mid = low + (high - low) / 2;
            if(A[mid] > target) high = mid;
            else low = mid + 1;
        }
        
        if(A[high] < target) rightInd = -1;
        else rightInd = A[high] == target ? high : high - 1;
        cout<<"Right Index: "<<rightInd<<":"<<A[rightInd]<<endl; 
	
        if(A[rightInd] != target) rightInd = -1;
        
        low = 0; high = rightInd;
        while(low < high) {
            mid = n - 1 - (n - 1 - high + n - 1 - low) / 2;
            if(A[mid] < target) low = mid;
            else high = mid - 1;
        }
        if(rightInd == -1) leftInd = -1;
        else leftInd = A[low] == target ? low : low + 1;
        ret.push_back(leftInd);
        ret.push_back(rightInd);
        return ret;
    }
};

int main() {
	int A[] = {9, 10, 11};
	int target = 4;
	Solution().searchRange(A, 3, target);
}
