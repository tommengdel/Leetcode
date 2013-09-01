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
        
        if(pos_t == p.size()) return matchRes[Index(pos_s, pos_t)] = false;
        bool ret = false;
        switch(p[pos_t]) {
            case '?':
                ret = isMatch(s, pos_s + 1, p, pos_t + 1, matchRes);
                break;
            case '*':
                //Count the Question Mark
                int countQMark = 0, NextPos_t;
                for(NextPos_t = pos_t + 1; NextPos_t < p.size(); ++NextPos_t) {
                    if(p[NextPos_t] == '?') countQMark++;
                    else break;
                }
                //if One match
                for(int NextPos_s = pos_s + countQMark; NextPos_s < s.size(); ++NextPos_s) {
                    if((NextPos_t >= p.size() && s[NextPos_s] == p[NextPos_t])  //Fix Bug1: aa '*' Beautiful
                        && isMatch(s, NextPos_s + 1, p, NextPos_t + 1, matchRes)) {
                            ret = true;
                            break;
                        }
                }
                
                break;
            default:
                ret = s[pos_s] == p[pos_t] && isMatch(s, pos_s + 1, p, pos_t + 1, matchRes);
        }
        matchRes[Index(pos_s, pos_t)] = ret;
        return ret;
        
    }
};

