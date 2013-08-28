#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
    vector<vector<bool> > isPalin;
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0) return 0;
        vector<bool> tmp(s.size(), true);
        isPalin.assign(s.size(), tmp);
        
        //Initialize
        for(int i = 0; i < s.size(); ++i) isPalin[i][i] = true;
        for(int dist = 1; dist <= s.size() - 1; ++dist) {
            for(int i = 0; i <= s.size() - 1 - dist; ++i) {
                if(s[i] == s[i + dist] && isPalin[i + 1][i + dist - 1]) 
                    isPalin[i][i + dist] = true;
                else isPalin[i][i + dist] = false;
            }
        }
        
        vector<int> dp(s.size() + 1, -1);
	dp[s.size()] = -1;
        for(int i = s.size() - 1; i >= 0; --i) {
            int min = s.size();
            for(int j = i; j < s.size(); ++j) {
                if(isPalin[i][j]) min = min > dp[j + 1] + 1 ? dp[j + 1] + 1 : min;
            }
            
            dp[i] = min;
        }
        return dp[0];
    }
};
int Test(string s) {
	cout<<Solution().minCut(s)<<endl;
}

int main() {
	Test("");
}
//Accepted


