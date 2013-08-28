class Solution {
    vector<int> oneSub;
    vector<vector<int> > subs;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        oneSub.clear();
        subs.clear();
        sort(S.begin(), S.end());
        GenerateSubsets(S, 0);
        return subs;
    }
    
    //Empty Set is a subset too
   void GenerateSubsets(vector<int> &s, int level) {
        if(level == s.size()) subs.push_back(oneSub);
        else {
        //Choose or not choose , it is a question
            GenerateSubsets(s, level + 1);
            oneSub.push_back(s[level]);
            GenerateSubsets(s, level + 1);
            oneSub.pop_back();
        }
    }
};

