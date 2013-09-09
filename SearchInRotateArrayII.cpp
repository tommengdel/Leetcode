#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0;  i< n; ++i) if(target == A[i]) return true;
        return false;
    }
};
//4ms 52ms
//Try to use divide an conquer
class Solution1 {
    bool InRange(int value, int below, int above) {
        return value >= below && value <= above;
    }
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return search(A, 0, n - 1, target);
    }
    
    bool search(int A[], int low, int high, int target) {
        if(low == high) return target == A[low];
        if(low > high) return false;
        
        int mid = low + (high - low)/ 2;
        if(A[low] < A[high])
            return InRange(target, A[low], A[high]) && binary_search(A + low, A + high + 1, target);
        else if(A[low] == A[high]) {
            if(A[mid] == A[low]) {
                if(search(A, low, mid - 1, target)) return true;
                if(search(A, mid + 1, high, target)) return true;
                return false; //??
            }
            else if(A[mid] < A[low]) {
                //A[mid.. high] is sorted
                if(InRange(target, A[mid], A[high]) && binary_search(A + mid, A + high + 1, target)) return true;
                else return search(A, low, mid - 1, target);
            }
            else if(A[mid] > A[low]) {
                //A[low..mid] is sorted
                if(InRange(target, A[low], A[mid]) && binary_search(A + low, A + mid + 1, target)) return true;
                else return search(A, mid + 1, high, target);
            }
        }
        
        else if(A[low] > A[high]) {
            if(A[mid] >= A[low]) {
                //A[low..mid] is sorted
                if(InRange(target, A[low], A[mid]) && binary_search(A + low, A + mid + 1, target)) return true;
                else return search(A, mid + 1, high, target);
            }
            else {
                //A[mid.. high] is sorted
                if(InRange(target, A[mid], A[high]) && binary_search(A + mid, A + high + 1, target)) return true;
                else return search(A, low, mid - 1, target);
            }
        }
    }
};
//逐层抽丝剥茧即可
//A[low] 与 A[high]的三种可能性 > = < 
//	在这三种可能性之下的A[low] 与 A[mid]的三种可能性
//	总共情况小于3 * 3 = 9种 共6种
//12ms 48ms
int main() {
}
