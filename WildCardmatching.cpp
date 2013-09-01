class Solution {
    class Index {
        public:
            int i, j;
            Index(int i, int j):i(i), j(j) {}
            bool operator < (const Index & i2) const {
                return i < i2.i || (i == i2.i && j < i2.j);
            }
    };
    void DeleteAdjChar(vector<char>& pv, char del) {
        int countdel = 0;
        for(int i = 0; i < pv.size(); ++i) {
            if(pv[i] == pv[i - 1] && pv[i] == del) {
                countdel++;
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
        vector<char> sv(s, s + strlen(s));
        vector<char> pv(p, p + strlen(p));
        if(sv.size() == 0) {
            for(int i = 0; i < pv.size(); ++i) 
                if(pv[i] != '*') return false;
            return true;
        }
        
        //Delete multiple star
        //Make a***b => a*b;
        DeleteAdjChar(pv, '*'); //resize the pv
        map<Index, bool> matchSign;
        
        return isMatch(sv, 0, pv, 0, matchSign); 
    }
    
    
    bool isMatch(vector<char>& s, int pos_s, vector<char> &p, int pos_t, map<Index, bool>& matchSign) {
        map<Index, bool>::iterator iter = matchSign.find(Index(pos_s, pos_t));
        if(iter != matchSign.end()) {
            return iter->second;
        }
        if(pos_t == p.size()) return pos_s == s.size();
        int prevPos_s = pos_s, prevPos_t = pos_t;
        
        while(pos_t < p.size() && p[pos_t] != '*') {
            if(pos_s >= s.size() || (p[pos_t] != '?'  && s[pos_s] != p[pos_t])) return false;
            ++pos_t;
            ++pos_s;
        }
        
        //pos_t + 1 must be '*' or out of range
        if(pos_t + 1 > p.size()) {
            matchSign[Index(pos_s, pos_t)] = true;
            return true;
        
        }
        bool matchone = false;
        
        //pos_t + 1 may be ?
        //it is hard 
        int countQuestionMark = 0;
        for(int i = pos_t + 1; i < p.size(); ++i) {
            if(p[i] == '?') countQuestionMark++;
            else break;
        }
        pos_t += countQuestionMark;
        if(pos_t == p.size()) return s.size() - pos_s >= countQuestionMark;
        //pos_t may be larger then p.size()
        for(int i = pos_s + countQuestionMark - 1; i < s.size(); ++i) {
            if(s[i] == p[pos_t] && isMatch(s, i + 1, p,  pos_t + 1, matchSign)) {
                matchone = true;
                break;
            }
        }
        
        
        //update matchSign
        matchSign[Index(prevPos_s, prevPos_t)] = matchone;
        return matchone;
    }
};
//"aa" "a"
//
//Code is incorrect!!
//
