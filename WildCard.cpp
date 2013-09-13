class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0) {
            if(*p == 0) return true;
            else if(*p == '*') return isMatch(s, p + 1);
            else return false;
        }   
        
        if(*p == '?') {
            return isMatch(s + 1, p + 1);
        }
        else if(*p == '*') {
            char *pnext = const_cast<char*>(p);
            int countp = 0, counts = 0;
            for(char *t = pnext; *t != 0; t = t + 1) 
                if(*t != '*') countp++;
                
            counts = strlen(s);
            
            while(*pnext == '*') pnext = pnext + 1;
            char *iter = const_cast<char*>(s);
            bool matchone = false;
            while(*iter != 0 && !matchone && counts >= countp) {
                if(isMatch(iter, pnext)) matchone = true;
                iter = iter + 1;
                counts--;
            }
            
            if(isMatch(iter, pnext)) matchone = true;
            return matchone;
        }
        else return *s == *p && isMatch(s + 1, p + 1);
    }
};
//使用了优化  
