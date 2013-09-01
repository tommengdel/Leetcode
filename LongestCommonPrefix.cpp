class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(strs.size() == 0) return "";
        int i;
        for(i = 0;; ++i) {
           bool flag = true;
           if(strs[0].size() < i + 1) break;
           for(int j = 1; j < strs.size(); ++j) {
                if(strs[j].size() < i + 1 || strs[j][i] != strs[0][i]) {
                    flag = false;
                    break;
                }
           }
           if(!flag) break;
        }
        return strs[0].substr(0, i);
    }
};
//´úÂëÌ«ÂÒ
