//Basic Solution : use backtracking
//But backtracking is too time-consuming for large data
//Suddenly, I find I can use DP;
//
//Backtracking Solution
class Solution {
    int wayNum;
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        wayNum = 0;
    
        if(s.size() != 0)CountDecodeWay(s, 0);
        return wayNum;
    }
    
    void CountDecodeWay(string &s, int level){
        if(level == s.size()) wayNum++;
        else {
            int num = 0;
            for(int j = level; j < s.size(); ++j) {
                num = num * 10 + s[j] - '0';
                if(InRange(num, 1, 26))  CountDecodeWay(s, j + 1);
                else break;
            }
        }
    }
    
    inline bool InRange(int value, int below, int above) {
        return value >= below && value <= above;
    }
};

//Dynamic Programming Solution
//F[i]: s[i...s.size() -1]'s decode ways.
class Solution {
    bool InRange(int value, int below, int above) {
        return value >= below && value <= above;
    }
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
        int num = 0;
        
        //Initialize
        int iter = s.size() - 1;
        if(InRange(s[iter] - '0', 1, 26)) dp[iter] = 1;
        if(--iter >= 0) {
            num = s[iter] - '0';
            if(InRange(num, 1, 26)) {
                dp[iter] += dp[iter + 1];
                num = num * 10 + s[iter + 1] - '0';
                if(InRange(num, 1, 26)) dp[iter] += 1;
            }
        }
        
        for(iter = s.size() - 3; iter >= 0; --iter) {
            num = 0;
            for(int j = iter; j <= iter + 1; ++j) {
                num = num * 10 + s[j] - '0';
                if(InRange(num, 1, 26)) dp[iter] += dp[j + 1];
                else break;
            }
        }
        return dp[0];
    }
};
//Forget to consider the case : "01"

