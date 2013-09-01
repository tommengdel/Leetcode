class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > solutions;
        if(num.size() < 4) return solutions;
        class Triple {
            public:
             int a, b, c;
             Triple(int a, int b, int c) : a(a), b(b), c(c) {}
             bool operator <(const Triple &t2) const {
                 return a < t2.a || (a == t2.a && b < t2.b) || (a == t2.a && b == t2.b && c < t2.c);
             }
        };
        
        set<Triple> AllSolution;
        
        sort(num.begin(), num.end());
        for(int i1 = 0; i1 < num.size() - 3; ++i1) 
            for(int i2 = i1 + 1; i2 < num.size() - 2; ++i2) 
                for(int i3 = i2 + 1; i3 < num.size() - 1; ++i3) {
		    if((target - num[i1] - num[i2] - num[i3]) < num[i3]) break; //Important cut 
                    bool isExist = binary_search(num.begin() + i3 + 1, num.end(), target - num[i1] - num[i2] - num[i3]);
                    if(isExist) {
                        if(AllSolution.find(Triple(num[i1], num[i2], num[i3])) != AllSolution.end()) continue;
                        AllSolution.insert(Triple(num[i1], num[i2], num[i3]));
                    }
                }
        
        for(set<Triple>::iterator iter = AllSolution.begin(); iter != AllSolution.end(); ++iter) {
            vector<int> tmp;
            tmp.push_back(iter->a);
            tmp.push_back(iter->b);
            tmp.push_back(iter->c);
            tmp.push_back(target - (iter->a + iter->b + iter->c ));
            solutions.push_back(tmp);
        }
        return solutions;
    }
};
//O(n^3 logn) Time Limit Exceed
//Line 23 make time limit not exceeded 1108ms
//
//
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > solutions;
        if(num.size() < 4) return solutions; //越到紧要关头越是不能忘记的东西
        class Index {
            public:
                int  e1, e2;
                Index(int e1, int e2): e1(e1), e2(e2) {}
                bool overlap(Index & i2) {
                    return e1 == i2.e1 || e1 == i2.e2 || e2 == i2.e1 || e2 == i2.e2;
                }
        };
        set<vector<int> > sol_set;
        unordered_multimap<int, Index> twoSum;
        typedef   unordered_multimap<int, Index> :: iterator  mmapIter;
        
        //sort(num.begin(), num.end());//not important
        for(int i = 0; i < num.size() - 1; ++i) 
            for(int j = i + 1; j < num.size(); ++j) {
                int sum = num[i] + num[j];
                Index tmp(i, j);
                
                pair<mmapIter, mmapIter> eq = twoSum.equal_range(target - sum);
                for(mmapIter iter = eq.first; iter != eq.second; iter++)
                    if(iter != twoSum.end() && !(iter->second).overlap(tmp)) {
                    //we got a solution
                        vector<int> vtmp;
                        vtmp.push_back(num[iter->second.e1]);
                        vtmp.push_back(num[iter->second.e2]);
                        vtmp.push_back(num[i]); vtmp.push_back(num[j]);
                        sort(vtmp.begin(), vtmp.end());
                        sol_set.insert(vtmp);       
                    }
                twoSum.insert(pair<int, Index>(sum, tmp));
            }
        copy(sol_set.begin(), sol_set.end(), back_inserter(solutions));
        return solutions;
    }
};

//520ms
//

//以下代码尚未调试成功 unordered_set
bool operator==(const vector<int> &v1, const vector<int> &v2) {
                    return v1.size() == v2.size() && mismatch(v1.begin(), v2.end(), v1.begin()) == v1.end();
    }
class Solution {
    
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > solutions;
        if(num.size() < 4) return solutions; //越到紧要关头越是不能忘记的东西
        class Index {
            public:
                int  e1, e2;
                Index(int e1, int e2): e1(e1), e2(e2) {}
                bool overlap(Index & i2) {
                    return e1 == i2.e1 || e1 == i2.e2 || e2 == i2.e1 || e2 == i2.e2;
                }
                bool operator==(const Index &i2) {
                    return e1 == i2.e1 && e2 == i2.e2;
                }
        };
        class cmpVector {
            public:
                size_t operator()(const vector<int>&v) {
                    return v[0] + v[1] * 10 + v[2] * 100 + v[3] * 1000;
                }
        };
        
        class EqualVector {
            public:
                bool operator()(const vector<int> &v1, const vector<int> &v2) {
                    return v1.size() == v2.size() && mismatch(v1.begin(), v2.end(), v1.begin()) == v1.end();
                }
        };
        unordered_set<vector<int>, cmpVector()> sol_set;
        unordered_multimap<int, Index> twoSum;
        typedef   unordered_multimap<int, Index> :: iterator  mmapIter;
        
        //sort(num.begin(), num.end());//not important
        for(int i = 0; i < num.size() - 1; ++i) 
            for(int j = i + 1; j < num.size(); ++j) {
                int sum = num[i] + num[j];
                Index tmp(i, j);
                
                pair<mmapIter, mmapIter> eq = twoSum.equal_range(target - sum);
                for(mmapIter iter = eq.first; iter != eq.second; iter++)
                    if(iter != twoSum.end() && !(iter->second).overlap(tmp)) {
                    //we got a solution
                        vector<int> vtmp;
                        vtmp.push_back(num[iter->second.e1]);
                        vtmp.push_back(num[iter->second.e2]);
                        vtmp.push_back(num[i]); vtmp.push_back(num[j]);
                        sort(vtmp.begin(), vtmp.end());
                        sol_set.insert(vtmp);       
                    }
                twoSum.insert(pair<int, Index>(sum, tmp));
            }
        copy(sol_set.begin(), sol_set.end(), back_inserter(solutions));
        return solutions;
    }
};

