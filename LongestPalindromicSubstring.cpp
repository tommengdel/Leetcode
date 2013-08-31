//DP Solution
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0) return s;
        
        vector<bool> tmp(s.size(), true);
        vector<vector<bool> >dp(s.size(), tmp);
        
        //Initialization
        //Computation
        int LeftInd = 0, RightInd = 0;
        for(int dist = 1; dist < s.size(); ++dist) {
            for(int i = 0; i < s.size() - dist; ++i) {
                if(s[i] == s[i + dist] && dp[i + 1][i + dist - 1]) {
                    dp[i][i + dist] = true;
                    LeftInd = i;
                    RightInd = i + dist;
                }
                else {
                    dp[i][i + dist] = false;
                }
            }
        }
        
        
        return s.substr(LeftInd, RightInd - LeftInd + 1);
    }
};

//center solution
class Solution {
public:

    int expand(const string& s, int center) {
        int l, r;
        //i == 0 How to solve
        if(center % 2 == 1) {
            r = center / 2; 
            l = center / 2 + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
        }
        else {
            l = r = center / 2;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
        }
        
        return r - l  - 1;
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0; 
        int leftInd = 0, rightInd = 0;
        if(s.size() == 0) return s;
        for(int i = 0; i < s.size() * 2 - 1; ++i) {
            int len = expand(s, i);
            if(len > max) {
                max = len;
                if(i % 2 == 1) {
                    leftInd = i / 2 - len / 2 + 1;
                    rightInd = (i / 2 + 1)+ len / 2  - 1;
                }
                else {
                    leftInd = i / 2 - (len - 1) / 2;
                    rightInd = i /2 + (len - 1) / 2;
                }
            }
        }
        
        return s.substr(leftInd, rightInd - leftInd + 1);
    }
};
//Center with some cut!
class Solution {
public:

    int expand(const string& s, int center) {
        int l, r;
        //i == 0 How to solve
        if(center % 2 == 1) {
            r = center / 2; 
            l = center / 2 + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
        }
        else {
            l = r = center / 2;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
        }
        
        return r - l  - 1;
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0; 
        int leftInd = 0, rightInd = 0;
        if(s.size() == 0) return s;
        for(int i = 0; i < s.size() * 2 - 1; ++i) {
		   //在此处可以进行剪枝
            int PossibleMaxLen = (i / 2) * 2 + 1 + (i % 2);
            if(PossibleMaxLen < max) {
                if(i / 2 > s.size() / 2) break;
                continue;
            }
            int len = expand(s, i);
         
            if(len > max) {
                max = len;
                if(i % 2 == 1) {
                    leftInd = i / 2 - len / 2 + 1;
                    rightInd = (i / 2 + 1)+ len / 2  - 1;
                }
                else {
                    leftInd = i / 2 - (len - 1) / 2;
                    rightInd = i /2 + (len - 1) / 2;
                }
            }
        }
        
        return s.substr(leftInd, max);
    }
};

