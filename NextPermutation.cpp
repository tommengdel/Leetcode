class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        for(i = num.size() - 1; i > 0; --i) 
            if(num[i] > num[i - 1]) break;
        if(i != 0) {
            
            for(int j = num.size() - 1; j >= i; --j) {
                if(num[j] > num[i - 1]) {
                    swap(num[j], num[i - 1]);
                    break;
                }
            }
        }
        reverse(num.begin() + i, num.end());
        
    }
};
//Beautiful Code using stl
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        for(i = num.size() - 1; i > 0; --i) 
            if(num[i] > num[i - 1]) break;
        if(i != 0) {
            vector<int>::reverse_iterator it = find_if(num.rbegin(), num.rend(), bind2nd(greater<int>(), num[i - 1]));
            iter_swap(num.begin() + i - 1, it.base() - 1);
        }
        reverse(num.begin() + i, num.end());
        
    }
};

