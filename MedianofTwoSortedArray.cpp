
#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = m + n;
        if(total % 2 == 0) {
	    cout<<GetKth(A, m, B, n, total / 2 + 1)<<endl;
            return (double)(GetKth(A, m, B, n, total / 2 ) + GetKth(A, m, B, n, total / 2 + 1)) / 2.0;

        }
        else return GetKth(A, m, B, n, total / 2 + 1);
    }
    
    int GetKth(int A[], int m, int B[], int n, int k) {
    cout<<"A: ";
    for(int i = 0; i < m; ++i) cout<<A[i]<<" ";
    cout<<"  B: ";
    for(int i = 0; i < n; ++i) cout<<B[i]<<" ";
    cout<<"  K: "<<k<<endl;

    if(m == 0) return B[k - 1];
    if(n == 0) return A[k - 1];
    

    int midA = m / 2, midB = n / 2;
    int ret = 0;
    if(A[midA] > B[midB]) {
        if(k > midA + midB + 1)
            ret = GetKth(A , m , B + midB + 1, n - midB - 1, k - midB - 1); //Make a serious mistake!!  
        else ret = GetKth(A, midA, B, n, k);
    }
    else {
        if(k > midA + midB + 1) 
            ret = GetKth(A + midA + 1, m - midA - 1, B , n, k - midA  - 1);
        else ret = GetKth(A, m, B, midB, k);
    }
    return ret;
}
};

int main() {
	int A[] = {1, 2, 3};
	int B[] = {4, 5, 6};

	double ret = Solution().findMedianSortedArrays(A, 3, B, 3);
	cout<<ret;
}
