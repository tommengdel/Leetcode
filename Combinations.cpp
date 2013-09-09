class Solution {
    vector<vector<int> > sols;
    vector<int> oneSol;
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sols.clear(), oneSol.clear();
        if(k != 0) Generate(n, k, 0, 1);
        return sols;
    }
    
    void Generate(int n, int k, int level, int start) {
        if(level == k) {
            sols.push_back(oneSol);
            return;
        }
        for(int j = start; j <= n - (k - level - 1); ++j) {
            oneSol.push_back(j);
            Generate(n, k, level + 1, j + 1);
            oneSol.pop_back();
        }
        
    }
    
};

