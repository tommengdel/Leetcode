class Solution {
    vector<vector<int> > Permute;
    public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        Permute.clear();
        if(num.size() != 0) GetPermute(0, num);
        return Permute;
    }
    void GetPermute(int level, vector<int> &num) {
        if(level == num.size()) {
            Permute.push_back(num);
            return;
        }
        for(int i = level; i < num.size(); ++i) {
            swap(num[i], num[level]);
            GetPermute(level + 1, num);
            swap(num[i], num[level]);//Forget this statement , So easy a Problem

        }
    }
};

