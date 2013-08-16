class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0) {
            if(*p == 0) return true;
            else if(*p == '*') {
                return isMatch(s, p + 1);
            }
            else return false;
        }
        
        if(*p == '?') return isMatch(s + 1, p + 1);
        else if(*p == '*') {
            bool matchone = false;
            char *iter = const_cast<char*>(s);
            while(*iter != 0 && !matchone) {
                if(isMatch(iter, p + 1)) matchone = true;
                iter = iter + 1;
            }
            if(isMatch(iter, p + 1)) matchone = true;
            return matchone;
        }
        else return (*s == *p) && isMatch(s + 1, p + 1);
    }
};
//Time Limit Exceeded
