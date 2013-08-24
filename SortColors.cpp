class Solution {
    void swap(int& a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int zero, one, two, i = 0;
        zero = -1;
        two = n; 
        while(i < two) {
            switch(A[i]) {
                case 0:
                    ++zero;
                    if(zero == i) ++i;
		    else swap(A[zero], A[i]);
                    
                    break;
                case 1:
                    ++i;
                    break;
                case 2:
                    --two;
                    swap(A[two], A[i]);
                    break;
            }
        }
    }
};

