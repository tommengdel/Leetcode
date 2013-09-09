class Solution {
    vector<vector<int> > sols;
    vector<int> oneSol;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sols.clear();
        sort(candidates.begin(), candidates.end());
        oneSol.assign(candidates.size(), 0);
        if(candidates.size() != 0) GenerateCombSum(candidates, target, candidates.size() - 1);
        return sols;
    }
    
    void GenerateCombSum(vector<int> &cand, int target, int index) {
        if(index == -1) {
            if(target == 0) {
                sols.push_back(vector<int>());
                for(int i = 0; i < oneSol.size(); ++i) {
                    for(int j = 0; j < oneSol[i]; ++j) sols.back().push_back(cand[i]);
                }
            }
            return;
        }
        
        int num = 0, count = 0;
        while(target  - num >= 0) {
            oneSol[index] = count;
            GenerateCombSum(cand, target - num, index - 1);
            oneSol[index] = 0;
            num += cand[index];
            ++count;
        }
    }
};

