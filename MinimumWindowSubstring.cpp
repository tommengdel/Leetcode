class Solution {
    bool includes(map<char, int> Par, map<char, int> Child) {
        map<char, int>::iterator iter;
        for(iter = Child.begin(); iter != Child.end(); iter++) {
            map<char, int>::iterator pariter = Par.find(iter->first);
            if(pariter == Par.end() || pariter->second < iter->second) return false;
        }
        return true;
    }
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> s_char_count, t_char_count;
        if(S.size() < T.size() || T.size() == 0) return "";
        string ret;
        int window_start, window_end;
        window_start = 0;
        window_end = 0;
        
        //Initialization
        for(int i = 0; i < T.size(); ++i) t_char_count[T[i]]++;
	for(int i = 0; i < S.size(); ++i) 
		if(window_start < S.size() && t_char_count[S[window_start]] == t_char_count.end()) window_start++;
		else break;
        //Compute the window_end
	window_end = window_start;
        while(window_end < S.size()) {
            if(t_char_count.find(S[window_end]) != t_char_count.end()) {
                s_char_count[S[window_end]]++;
                if(includes(s_char_count, t_char_count)) break;
            }
            ++window_end;
        }
        
        if(window_end == S.size()) return ""; //S not include T
	
	while(includes(s_char_count, t_char_count)) {
		s_char_count[S[window_start]]--;
		window_start++;
	}        
	window_start--;
	s_char_count[S[window_start]]++;

        ret = S.substr(window_start, window_end - window_start + 1);
        //Start to Slide
        while(window_end < S.size()) {
            if(ret.size() > window_end - window_start + 1) 
                ret = S.substr(window_start, window_end - window_start + 1);

            char delchar = S[window_start];;
            s_char_count[S[window_start++]]--;
            while(window_start < S.size() && t_char_count.find(S[window_start]) == t_char_count.end()) window_start++; //Just clear useless char

            while(includes(s_char_count, t_char_count)) {
//		while(window_start < S.size() && t_char_count.find(S[window_start]) == t_char_count.end()) window_start++;
		
                s_char_count[S[window_start]]--;
                delchar = S[window_start]; //此处错误
                ++window_start;
            }
            while(window_start < S.size() && t_char_count.find(S[window_start]) == t_char_count.end()) window_start++; //clear useless char to decrese the length
              
            //Slide window_end
            while(++window_end < S.size() && S[window_end] != delchar) s_char_count[S[window_end]]++;            
        }
        return ret;
    }
};
//not accpeted
//逻辑还是不够清楚
//bba ba 返回错误 逻辑还是不太清晰
//
//Error Test Case:"acbbaca", "aba"	"acbba"	"baca" 
