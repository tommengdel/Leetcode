class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxind = 0;
        for(int i = 1; i < n; ++i) {
            if(A[i] > A[maxind])  maxind = i;
        }
        
        int i = 0, trapwater = 0, j;
        while(i < maxind) {
            for(j = i + 1; A[j] < A[i]; ++j)
                trapwater += A[i] - A[j];
            i = j;
        }
        
        i = n - 1;
        while(i > maxind) {
            for(j = i - 1; A[j] < A[i]; --j) 
                trapwater += A[i] - A[j];
            i = j;
        }
        
        return trapwater;
        
    }
};
//Find max index is the key!! from 0 to max; from n - 1 to max;
