#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int num;
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(S.size() == 0) return T.size() == 0 ? 1 : 0;
        num = 0;
        enum { AlphaSIZE = 256};
        vector<int> NextCharPos(S.size(), -1 );
        vector<int>prevCharPos(AlphaSIZE, -1), charPosInS(AlphaSIZE, -1);
        
        
        for(int i = 0; i < S.size(); ++i) {
            if(prevCharPos[S[i]] != -1) {
                NextCharPos[prevCharPos[S[i]]] = i;
            }
            prevCharPos[S[i]] = i;    
        }
        
        for(int i = 0; i < T.size(); ++i) charPosInS[T[i]] = -2;
        for(int i = 0; i < S.size(); ++i) 
            if(charPosInS[S[i]] == -2) charPosInS[S[i]] = i;
        
        GenerateDistinctSeq(S, T, 0, 0, NextCharPos, charPosInS);
        return num;
    }
    
    
    void GenerateDistinctSeq(string &S, string &T, int pos_s, int pos_t, vector<int> &NextCharPos, vector<int> &charPosInS) {
        if(pos_t == T.size()) ++num;
        else {
            int reservePos = charPosInS[T[pos_t]];
            
            int iter = charPosInS[T[pos_t]];
            while(iter >= 0 && iter < pos_s) {
                iter = charPosInS[T[pos_t]] = NextCharPos[iter];
            }
            
            while(iter >= 0 && (S.size() - 1 - iter >= T.size() - 1 - pos_t)) {
                int matchPos = charPosInS[T[pos_t]];
                charPosInS[T[pos_t]] = NextCharPos[charPosInS[T[pos_t]]];
                iter = NextCharPos[iter];
                GenerateDistinctSeq(S, T, matchPos + 1, pos_t + 1, NextCharPos, charPosInS);
            }
            charPosInS[T[pos_t]] = reservePos;
        }
    }
};
//Logic is too mesy! Prefer the Map version
//Error Test Case S:"b" T:"a"
//Time Limit Exceeded
//
void Test(string s, string t) {
	cout<<Solution().numDistinct(s, t)<<endl;
}
int main() {
	Test("b", "b");
	string S = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe", T ="bddabdcae";
	Test(S, T);
}

//Dynamic Programming Solution
//
class SolutionDP {
	int numDistinct(string S, string T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        vector<int> temp(T.size(), -1);
        vector<vector<int> > dp(S.size(), temp);
        
        ComputeDistinctSubseq(S, T, S.size() - 1, T.size() - 1, dp);
        
        return dp[S.size() - 1][T.size() - 1];
    }
    
    int ComputeDistinctSubseq(string &S, string &T, int i, int j, vector<vector<int> >&dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        else {
        
            if(i == 0 && j == 0) return dp[i][j] = S[i] == T[j] ? 1 : 0;
            dp[i][j] = 0;
            for(int t = i; t >= 0; --t) {
                if(S[t] == T[j]) dp[i][j] += ComputeDistinctSubseq(S, T, t - 1, j - 1, dp);
            }
            return dp[i][j];    
        }
    
    }
}



