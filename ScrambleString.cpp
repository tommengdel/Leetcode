class Solution {
    bool isAnagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        if(s1.size() == 1) return s1 == s2;
        int len = 1;
        int n = s1.size();
        for(; len < s1.size(); ++len) {
            if(isAnagram(s1.substr(0, len), s2.substr(0, len))) {
                if(isScramble(s1.substr(0, len), s2.substr(0, len))
                    && isScramble(s1.substr(len, n - len), s2.substr(len, n - len))) return true;
                    else break;
            }
        }
        for(len = 1; len < s1.size(); ++len) {
            if(isAnagram(s1.substr(0, len), s2.substr(n - len, len))) {
                if(isScramble(s1.substr(0, len), s2.substr(n - len, len))
                    && isScramble(s1.substr(len, n - len), s2.substr(0, n - len))) return true;
                    else break;
            }
        }
        return false;
    }
};

