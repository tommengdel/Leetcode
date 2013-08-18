class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ret;
        ret.resize(s.size());
        int count = 0;
        if(nRows == 1) return s; //∫‹÷ÿ“™
        int cirnum = 2 * nRows - 2;
        for(int i = 0; i < s.size(); i += cirnum) ret[count++] = s[i];
	//Can't use ret.push_back, or the memeory will become 2 * s.size()
        for(int i = 1; i < nRows - 1; ++i)
            for(int j = i; j < s.size(); j += cirnum) {
                ret[count++] = s[j];
                if(j + cirnum - 2 * i < s.size()) ret[count++] = s[j + cirnum - 2 * i];
            }
        for(int i  = nRows - 1; i < s.size(); i += cirnum) ret[count++] = s[i];
        return ret;
    }
};

