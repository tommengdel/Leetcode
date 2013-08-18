#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        //First row
        string ret = "";
        ret.resize(s.size());
        int count = 0;
        //first row
        for(int i = 0; i < s.size(); i += 2 * nRows - 2) ret[count++] = s[i];
        
        //Intermediate rows
        for(int  i = 1;  i < nRows - 1; ++i) {
            for(int j = 1; j < s.size(); j += 2 * nRows - 2) {
                ret[count++] = s[j];
                if(j + 2 * nRows - 4 < s.size()) ret[count++] = s[j + 2 * nRows - 4];
            }
        }
        //Last row
        for(int i = nRows - 1; i < s.size(); i += 2 * nRows - 2) ret[count++] = s[i];
        return ret;
    }   
    
};
