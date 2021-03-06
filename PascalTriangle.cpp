class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ret;
        if(numRows == 0) return ret;//Attention
        vector<int> first(1, 1);
        ret.push_back(first);
        
        for(int i = 1; i < numRows; ++i) {
            ret.push_back(vector<int>());
            ret[i].push_back(1);
            for(int j = 1; j < i; ++j) {
                ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            }
            
            ret[i].push_back(1);
        }
        return ret;
    }
};

