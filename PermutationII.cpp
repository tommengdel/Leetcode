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
//假设测试用例为
//1 1 1 2 2 2 
//当i开始第一次迭代为0， num[0]只能和1和2交换各一次。多了就会引发重复
//最重要的是，记录从i到n，num中有多少组不同的数字，包括i本身
//因为在LeetCode中，只创建一次Solution对象，并且运行多组程序，故而必须有clear语句
