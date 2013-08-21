#include<set>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> s(num.begin(), num.end());
        set<int>::iterator elem;
        int longest = 1, size;
        for(int i = 0; i < num.size(); ++i) {
            elem = s.find(num[i]);
            if(elem != s.end()) {
                s.erase(elem);
                size = 1;
                int j = num[i];//I write j = i , instead of j = num[i] , A big mistake.
                while(true) {
                    --j;
                    elem = s.find(j);
                    if(elem == s.end()) break;
                    s.erase(elem);
                    size++;
                }
                
                j = num[i];
                while(true) {
                    ++j;
                    elem = s.find(j);
                    if(elem == s.end()) break;
                    s.erase(elem);
                    size++;
                }
                
                longest = longest > size ? longest : size;
            }
        }
        return longest;
    }
};

int main() {
	int arr[] = {1, 0, -1};
	vector<int> v(arr, arr + 3);
	cout<<Solution().longestConsecutive(v)<<endl;
}
