/** 错误解法
 *  
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int countDup = 0;
        for(int i = 2; i < n; ++i) {
            if(A[i] == A[i - 1] && A[i] == A[i - 2]) ++countDup;
            else A[i - countDup] = A[i];
        }
        return n - countDup;
    }
};

Test Case : 1 1 1 2 2 3  
错误原因： A[i - 2] 可能被A[i - 1]覆盖，然后出现问题
为什么会犯这种错误
 *
 *
 *
 *
 */



class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int countDup = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(A[i] == A[i - 1] && A[i] == A[i + 1]) ++countDup;
            else A[i - countDup] = A[i];
        }
        A[n - 1 - countDup] = A[n - 1]; //Very Impotant , don't froget
        return n - countDup;
    }
};

