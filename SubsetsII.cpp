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


//ע��
//�˴�insertRes���Ǳ���ģ���Ϊ���ǰ� ��ѡ��num[level]�Ĵ�������˺��棬��ѡ��num[level]�Ĵ��������ǰ�档 ����ȱ��insertRes������Ӱ�����յĽ������������Ȼ�ǲ���ȷ�ġ�
//��Ϊ���߼���������ɾ���ĵط��Ͳ���ĵط���������ͬһ��ִ�й����С� ������p�� ɾ��������p���ӹ���p1�֡�
//
//�������ǽ����δ���Ե�
//����ͻ��Ǵ���� ����������[1 1]
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

