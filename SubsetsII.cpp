#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    vector<int> oneSol;
    vector<vector<int> > sols;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());   
        sols.clear();
        oneSol.clear();
        set<int> abandoned;
        Generate(S, 0, abandoned);
        return sols;
    }
    
    void Generate(vector<int> &num, int level, set<int> &abandoned) {
        if(level == num.size()) sols.push_back(oneSol);
        else {
            if(abandoned.find(num[level]) == abandoned.end()) {
                oneSol.push_back(num[level]);
                Generate(num, level + 1, abandoned);
                oneSol.pop_back();
            }
            pair<set<int>::iterator, bool> insertRes
                = abandoned.insert(num[level]);
            Generate(num, level + 1, abandoned);
            if(insertRes.second) abandoned.erase(num[level]); //I think insertRes is neccessary, but without it , we can also pass the oJ
	    //Why??
        }
    }
};

int main() {
	vector<int> s;
	for(int i = 0; i < 5; ++i) s.push_back(2);
	vector<vector<int> > ret = Solution().subsetsWithDup(s);
	for(int i = 0; i < ret.size(); ++i) {
		for(int j = 0; j < ret[i].size(); ++j) 
			cout<<ret[i][j]<<" ";
		cout<<endl; 	}
}


//注：
//此处insertRes并非必须的，因为我们把 不选择num[level]的代码放在了后面，把选择num[level]的代码放在了前面。 所以缺少insertRes并不会影响最终的结果，但是这仍然是不正确的。
//因为从逻辑上来讲，删除的地方和插入的地方并不是在同一个执行过程中。 插入在p， 删除可能在p的子过程p1种。
//
//我们若是将两段代码对调
//结果就会是错误的 错误用例：[1 1]
class SolutionERROR {
    vector<int> oneSol;
    vector<vector<int> > sols;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());   
        sols.clear();
        oneSol.clear();
        set<int> abandoned;
        Generate(S, 0, abandoned);
        return sols;
    }
    
    void Generate(vector<int> &num, int level, set<int> &abandoned) {
        if(level == num.size()) sols.push_back(oneSol);
        else {
	    abandoned.insert(num[level]);
            Generate(num, level + 1, abandoned);
            abandoned.erase(num[level]); 
            if(abandoned.find(num[level]) == abandoned.end()) {
                oneSol.push_back(num[level]);
                Generate(num, level + 1, abandoned);
                oneSol.pop_back();
            }
            //I think insertRes is neccessary, but without it , we can also pass the oJ
	    //Why??
        }
    }
};

