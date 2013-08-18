class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ret;
        ret.resize(s.size());
        int cirnum = 2 * nRows - 2;
        for(int i = 0; i < s.size(); i += cirnum) ret.push_back(s[i]);
        for(int i = 1; i < nRows - 1; ++i)
            for(int j = i; j < s.size(); j += cirnum) {
                ret.push_back(s[j]);
                if(j + cirnum - 2 * i < s.size()) ret.push_back(s[j + cirnum - 2 * i]);
            }
        for(int i  = nRows - 1; i < s.size(); i += cirnum) ret.push_back(s[i]);
        return ret;
    }
};

