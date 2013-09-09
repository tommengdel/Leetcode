class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        unordered_map<string, list<string> > groups;
        for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(strs[i]);
        }
        
        unordered_map<string, list<string> > ::iterator it;
        for(it = groups.begin(); it != groups.end(); ++it) {
            if(it->second.size() > 1)
                copy(it->second.begin(), it->second.end(), back_inserter(ret));
        }
        return ret;
    }
};

