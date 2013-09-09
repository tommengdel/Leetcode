class Solution {
    vector<int> oneSol;
    vector<vector<int> > sols;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        oneSol.clear(), sols.clear();
        sort(num.begin(), num.end(), greater<int>());
        unordered_set<int> abandoned;
        GenerateCombSum(num, target, num.size() - 1, abandoned);
        return sols;
    }
    
    void GenerateCombSum(vector<int> &num, int target, int index, unordered_set<int> &abandoned) {
        if(index == -1) {
            if(target == 0) sols.push_back(oneSol);
            return;
        }
        
        if(abandoned.find(num[index]) == abandoned.end() && target >= num[index]) {//target >= num[index] is very important condition
            oneSol.push_back(num[index]);
            GenerateCombSum(num, target - num[index], index - 1, abandoned);
            oneSol.pop_back();
        }
        
        pair<unordered_set<int>::iterator, bool> insertRes = abandoned.insert(num[index]);
        GenerateCombSum(num, target, index - 1, abandoned);
        if(insertRes.second) abandoned.erase(num[index]);
    }
};

