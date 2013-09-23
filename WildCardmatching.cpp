#include<algorithm>
#include<iterator>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
class Solution {
       class Index {
           	public:
			int pos_s, pos_t;
			Index(int i1, int i2): pos_s(i1), pos_t(i2) {}
			bool operator<(const Index& i2) const {
				return pos_s < i2.pos_s ||(pos_s == i2.pos_s && pos_t < i2.pos_t);
			}
       };
       void DeleteAdjChar(vector<char> &pv, char del) {
	       int countdel = 0;
	       for(int i = 0; i < pv.size(); ++i) {
	       		if(pv[i] == pv[i - 1] && pv[i] == del) {
				++countdel;
			}
			else {
			        pv[i - countdel] = pv[i];
			}
	       }
	       pv.resize(pv.size() - countdel);
       }
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char> pv(p, p + strlen(p)), sv(s, s + strlen(s));
        DeleteAdjChar(pv, '*');
        map<Index, bool> matchRes;
        
        return isMatch(sv, 0, pv, 0, matchRes);
    }
    
    bool isMatch(vector<char> &s, int pos_s, vector<char> &p, int pos_t, map<Index, bool> &matchRes) {
        map<Index, bool> ::iterator it = matchRes.find(Index(pos_s, pos_t));
        if(it != matchRes.end()) {
            return it->second;
        }
        
        //Terminate Condition
        if(pos_s == s.size()) {
            bool ret = true;
            for(int i = pos_t; i < p.size(); ++i) 
                    if(p[i] != '*') 
                        ret = false;
                        
            return matchRes[Index(pos_s, pos_t)] = ret;
        }
        
        if(pos_t >= p.size()) return matchRes[Index(pos_s, pos_t)] = false;
        bool ret = false;
        switch(p[pos_t]) {
            case '?':
                ret = isMatch(s, pos_s + 1, p, pos_t + 1, matchRes);
                break;
            case '*':
                //Count the Question Mark
                {
                int countQMark = 0, NextPos_t;
                for(NextPos_t = pos_t + 1; NextPos_t < p.size(); ++NextPos_t) {
                    if(p[NextPos_t] == '?') countQMark++;
                    else break;
                }
                
                
                
                //if One match
                
                
                for(int NextPos_s = pos_s + countQMark; NextPos_s <= s.size(); ++NextPos_s) { //Fix Bug2 
                    if(isMatch(s, NextPos_s, p, NextPos_t, matchRes)) {
                        ret = true;
                        break;
                    }
                    /*
                    if((NextPos_t >= p.size() || s[NextPos_s] == p[NextPos_t]) 
                        && isMatch(s, NextPos_s + 1, p, NextPos_t + 1, matchRes)) {
                            ret = true;
                            break;
                        }
                        */
                }
                
        
                
                
                }
                break;
            default:
                ret = (s[pos_s] == p[pos_t]) && isMatch(s, pos_s + 1, p, pos_t + 1, matchRes);
                break;
        }
        matchRes[Index(pos_s, pos_t)] = ret;
        return ret;
        
    }
};

//STILL Time Limit Exceed
//"bababababbabbaabbbbabbbaaaaabbabbbbabaaabbbabbbaabaaaaaaaabbbbaaabababbbabababbbabbabbbbaabbbbabbaabbbabaaababaabbbaaaaaababaaabaaaabbbababbbbaaabbabbbbabaabaabaabbbbbbbaaababbbaaabbbbabbbbbabaabbbaaabbaa", "*b******b*bb*ba*a*baa****ab**aa*b**bab*bab****b*b**bbbbab**b**aab*bb*a*abb**aa*b*b*******baaaaab*b***"
//Dynamic Programming
class SolutionDP {
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
            if(ends <= starts || (p[endp] != '?' && p[endp] != s[endp])) return false;
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
            for(int i = 0; i < pattern[0].size() - 1; ++i) dp[0][i] = false;
            for(int i = pattern[0].size() - 1; i < lens; ++i) {
                if(dp[0][i - 1]) dp[0][i] = true;
                else if(strncmp(pattern[0].c_str(), s + i + 1 - pattern[0].size(), pattern[0].size()) == 0) 
                    dp[0][i] = true;
            }
            
            for(int row = 1; row < pattern.size(); ++row) {
                for(int col = pattern[row].size(); col < lens; ++col) {
                    if(dp[row - 1][col - (pattern[row].size() - 1)] 
                        && strncmp(pattern[row].c_str(), s + col + 1 - pattern[row].size(), pattern[row].size()) == 0)
                        {
                            dp[row][col] = true;
                        }
                }
            }
            return dp.back().back();
            
            
        }
        
    }
};


class SolutionDP2 {
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
	copy(s + starts, s + starts + lens, ostream_iterator<char>(cout, " "));
        for(int i = 0; i < pattern.size(); ++i) cout<<pattern[i]<<" ";
        cout<<endl;	
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
                else if(strncmp(pattern[0].c_str(), s + starts+ i + 1 - pattern[0].size(), pattern[0].size())) 
                    dp[0][i] = true;
		
            }
	    Print(dp); 
            for(int row = 1; row < pattern.size(); ++row) {
                for(int col = pattern[row].size(); col < lens; ++col) {
		    if(dp[row][col - 1]) dp[row][col] = true;//Important
		    else if(dp[row - 1][col - (pattern[row].size())] 
                        && strncmp(pattern[row].c_str(), s + starts + col + 1 - pattern[row].size(), pattern[row].size())) //Forget to added starts, Big Mistake
                        {
                            dp[row][col] = true;
                        }
		    
		    Print(dp);
                }
            }
	    cout<<dp.back().back()<<endl;
            return dp.back().back();
            
            
        }
    }

    void Print(vector<vector<bool> > &v) {
	    for(int i = 0; i < v.size(); ++i) {
		    for(int j = 0; j < v[0].size(); ++j) {
			    cout<<v[i][j]<<" ";
		    }
		    cout<<endl;
	    }
	    cout<<endl<<endl;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
};

int main() {
	SolutionDP2().isMatch("mississippi", "m*issi*iss*");
}
//ACCPTED
