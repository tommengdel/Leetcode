#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
    bool includes(vector<int> &a, vector<int>& b) {
        return mismatch(a.begin(), a.end(), b.begin(), greater_equal<int>()).first == a.end();
    }
    bool InRange(int val, int below, int above) {
        return val >= below && val <= above;
    }
public:
    
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int ALPHASIZE = 256;
        vector<int> charS(ALPHASIZE, 0), charT(ALPHASIZE, 0);
        for(int i = 0; i < T.size(); ++i)  charT[T[i]]++;
        if(S.size() == 0) return "";
        int left = -1, right = -1;
        int start = 0, end;
        while(start < S.size() && charT[S[start]] == 0) ++start;
        end = start;
        while(end < S.size()) {
            charS[S[end]]++;
            if(includes(charS, charT)) break;
            ++end;
        }
        left = start, right = end;
        
        //Start to slide
        while(end < S.size()) {
            char delChar;
            //Slide the left 
            do {
                delChar = S[start++];
                if(charT[delChar] != 0) --charS[delChar];
            } while(start < S.size() && includes(charS, charT));
            
            if(right - left > end - (start - 1)) {
                left = start - 1;
                right = end;
            }
            
            //Slide the right end
	    /* 活该，谁让你用这么复杂的while循环
            //while(++end < S.size() && S[end] != delChar);
            while(++end < S.size() && S[end] != delChar){ ++charS[S[end]]; } 
	    //对比注释掉的那句，Error Test Case "bdab" "ab"
	    //还欠缺一句
	    if(end != S.size())++charS[S[end]];
	   */

	    end += 1;
	    while(end < S.size()) {
		    charS[S[end]]++;
		    if(S[end] == delChar) break;
		    ++end;
	    }
        }
        
        if(InRange(left, 0, S.size() - 1) && InRange(right, 0, S.size() - 1)) return S.substr(left, right - left + 1);
        else return "";
        
    }
};

int main() {
	Solution().minWindow("bdab", "ab");
}

//Accepted
