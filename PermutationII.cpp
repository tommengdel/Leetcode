class Solution {
    vector<vector<int> > solutions;
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solutions.clear();
        GeneratePermute(num, 0);
        return solutions;
    }
    
    void GeneratePermute(vector<int> &num, int level) {
        if(level == num.size()) solutions.push_back(num);
        else {
            set<int> notdup;
         //   notdup.insert(num[level];
            for(int i = level; i < num.size(); ++i) {
                if(notdup.find(num[i]) == notdup.end()) {
                    notdup.insert(num[i]);
                    swap(num[level], num[i]);
                    GeneratePermute(num, level + 1);
                    swap(num[level], num[i]);
                }
            }
        }
    }
};
//�����������Ϊ
//1 1 1 2 2 2 
//��i��ʼ��һ�ε���Ϊ0�� num[0]ֻ�ܺ�1��2������һ�Ρ����˾ͻ������ظ�
//����Ҫ���ǣ���¼��i��n��num���ж����鲻ͬ�����֣�����i����
//��Ϊ��LeetCode�У�ֻ����һ��Solution���󣬲������ж�����򣬹ʶ�������clear���
