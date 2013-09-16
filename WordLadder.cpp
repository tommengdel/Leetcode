class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> q;
        queue<int> level;
        q.push(start); level.push(1);
        if(start == end) return 0;
        //return 0;
        while(!q.empty()) {
            string st = q.front();
            int cur_level = level.front();
            
            q.pop(); level.pop();
            for(int i = 0;  i < st.size(); ++i) {
                string tmp = st;
                for(char c = 'a'; c <= 'z'; ++c) {
                    if(c == st[i])continue;
                    tmp[i] = c;
                    if(tmp == end) return (cur_level + 1);
                    unordered_set<string>::iterator it = dict.find(tmp);
                    if(it != dict.end()) {
                        q.push(tmp);
                        dict.erase(it);
                        level.push(cur_level + 1);
                    }
                    /*
                    if(dict.find(tmp) != dict.end()) {
                        q.push(tmp);
                        dict.erase(tmp);
                        level.push(cur_level + 1);
                    }
                    */
                }
            }
        }
        return 0;
    }
};

