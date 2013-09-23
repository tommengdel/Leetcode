class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int starts = 0, startp = 0, lenS = strlen(s), lenP = strlen(p);
        int ends = lenS - 1, endp = lenP - 1;
        while(startp < lenP && p[startp] != '*') {
            if(starts >= lenS || (p[startp] != '?' && p[startp] != s[starts])) return false;
            ++starts;
            ++startp;
        }
        
        //from the end 
        while(endp > startp && p[endp] != '*') {
            if(ends < starts || (p[endp] != '?' && p[endp] != s[ends])) return false;
            --endp;
            --ends;
        }
        
        
        return isMatch(s, starts, ends - starts + 1, p, startp, endp - startp + 1);
        
    }
    
    void SplitString(const char *p, int len, char delim, vector<string>&pattern) {
         int start = 0;
         int end = 0;
         while(start < len) {
             while(start < len && p[start] == delim) ++start;
             end = start + 1;
             while(end < len && p[end] != delim) ++end;
             if(start != len) pattern.push_back(string(p + start, p + end));
             start = end + 1;
         }
    }
    bool strncmp(const char *p, const char *s, int n) {
        for(int i = 0; i < n; ++i) 
            if(*(p + i) != '?' && *(p + i) != *(s + i)) return false;
        return true;
    }
    bool isMatch(const char* s, int starts, int lens, const char* p, int startp, int lenp) {
        //Split p
        if(lenp <= 0) return lens == 0;
        //Split p as a vector<string>
        vector<string> pattern;
        SplitString(p + startp, lenp, '*', pattern);
        
        //Dynamic Programming for 
        if(pattern.size() == 0) return true;
        else {
            vector<bool> tmp(lens, false);
            vector<vector<bool> > dp(pattern.size(), tmp);
            //Init
            
            for(int i = 0; i < min(pattern[0].size() - 1, lens); ++i) dp[0][i] = false;
            
            if(lens >= pattern[0].size())
                dp[0][pattern[0].size() - 1] = strncmp(pattern[0].c_str(), s + starts, pattern[0].size()) == true;
            for(int i = pattern[0].size(); i < lens; ++i) {
                if(dp[0][i - 1]) dp[0][i] = true;
                else if(strncmp(pattern[0].c_str(), s + starts + i + 1 - pattern[0].size(), pattern[0].size())) 
                    dp[0][i] = true;
            }
            
            for(int row = 1; row < pattern.size(); ++row) {
                for(int col = pattern[row].size(); col < lens; ++col) {
                    if(dp[row][col -1]) dp[row][col] = true;
                    else if(dp[row - 1][col - (pattern[row].size())] 
                        && strncmp(pattern[row].c_str(), s + starts+ col + 1 - pattern[row].size(), pattern[row].size()))
                        {
                            dp[row][col] = true;
                        }
                }
            }
            return dp.back().back();
            
            
        }
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
};

