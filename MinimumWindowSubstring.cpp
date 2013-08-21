class Solution {
    typedef map<char, int>::iterator MapIt;
    bool includes(map<char, int>&s, map<char, int> &t) {
        for(MapIt iter = t.begin(); iter != t.end(); ++iter) {
            MapIt tmp = s.find(iter->first);
            if(tmp == s.end() ||tmp->second < iter->second)
                return false;
        }
        return true;
    }
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> schCount, tchCount;
        if(T.size() == 0) return "";
        for(int i = 0; i < T.size(); ++i) ++tchCount[T[i]];
        int window_start, window_end;
        for(window_start = 0, window_end = 0; window_end < S.size(); ++window_end) {
            if(tchCount.find(S[window_end]) != tchCount.end()){
                ++schCount[S[window_end]];
                if(includes(schCount, tchCount)) break;
            }
        }
        
        if(window_end == S.size()) return ""; 
        //Start slide
        string ret = S.substr(window_start, window_end - window_start + 1);
        
        while(window_end < S.size()) {
            //Slide the window start
            if(ret.size() > window_start - window_end + 1) 
             ret = S.substr(window_start, window_end - window_start + 1);

            char slidechar = S[window_start];
            
            --schCount[S[window_start]];//important
            do { 
                ++window_start;
                ++schCount[S[window_start]];
            } while(tchCount.find(S[window_start]) == tchCount.end());
            
            //This stat is important
            if(includes(schCount, tchCount)) continue;
            
            //Slide the window end
            ++window_end;
            for(; window_end < S.size(); ++window_end) {
                ++schCount[S[window_end]];
                if(S[window_end] == slidechar) break; 
            }
        }
        return ret;
    }
};

