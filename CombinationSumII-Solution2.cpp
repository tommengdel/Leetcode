class Solution {
    vector<int> oneSol;
    vector<vector<int> > sols;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        oneSol.clear(); 
        sols.clear();
        sort(num.begin(), num.end());
        Generate(num, 0, target);
        return sols;
    }
    
    void Generate(vector<int> &num, int level, int target) {
        //Find the max count where num[level] = num[level + count]
        int count = 0;
        if(level == num.size()) {
            if(target == 0) {
                sols.push_back(oneSol);
            }
            return;
        }
        while(level + count < num.size() && num[level] == num[level + count]) count++;
        //num[level] - count 
        for(int i = 0; i <= count; ++i) {
            if(target - i * num[level] >= 0) {
                for(int j = 0; j < i; ++j) oneSol.push_back(num[level]);
                Generate(num, level + count, target - i * num[level]);                
                for(int j = 0; j < i; ++j) oneSol.pop_back();
            } 
        }
        
    }
};

