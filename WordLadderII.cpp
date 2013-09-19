#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    vector<string> oneSol;
    
    vector<vector<string> >sols;
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        oneSol.clear(); 
        sols.clear();
        int len = bfs(start, end, dict);
	cout<<"Length: "<<len<<endl;
        if(len == -1) return sols;
        
        dfs(start, end, dict, len - 1);
        return sols;
    }
    
    int bfs(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        queue<int> len;
        unordered_set<string> visited;
        
        q.push(start);len.push(1);
        int curLen = 1;
        visited.insert(start);
        while(!q.empty()) {
            string curStr = q.front(); q.pop(); curLen = len.front(); len.pop();
            string temp = curStr;//Wrong Location

            for(int i = 0; i < temp.size(); ++i) {
		temp = curStr; //Important
                for(char j = 'a'; j <= 'z'; ++j) {
                     if(j == curStr[i]) continue;
                     temp[i] = j; 
                     if(temp == end) return curLen + 1;
                     if(dict.find(temp) != dict.end() && visited.find(temp) == visited.end()) {
                         q.push(temp);
                         len.push(curLen + 1);
                         visited.insert(temp);
                     }
                
                }
            }
            
        }
        return -1;
    }
    
    
    //不设置已访问了（只是可以提高效率而已）
    void dfs(string start, string end, unordered_set<string>&dict, int len) {
        if(len == 0) {
            if(start == end) {
                oneSol.push_back(start);
                sols.push_back(oneSol);
                oneSol.pop_back();
            }
            return;
        }
        
        string temp = start;
        oneSol.push_back(start);
        for(int i = 0; i < start.size(); ++i) 
            for(char j = 'a'; j <= 'z'; ++j) {
                if(j == start[i]) continue;
                temp[i] = j;
                if(temp == end) { //Important
                    dfs(temp, end, dict, len - 1);
                }
                else if(dict.find(temp) != dict.end()) {
                    dict.erase(temp); //必须加,否则可能出现异常
                    dfs(temp, end, dict, len - 1);
                    dict.insert(temp);
                }
            }
        oneSol.pop_back();
    }
    
};
int main() {
	unordered_set<string> dict;
	dict.insert("hot"); dict.insert("dog"); dict.insert("dot");
	vector<vector<string> > sol =Solution().findLadders("hot", "dog", dict);
	for(int i = 0; i < sol.size(); ++i) {
		cout<<"[";	
		for(int j = 0; j < sol[i].size(); ++j) cout<<sol[i][j]<<" ";
		cout<<"]";
		cout<<endl;
	}
}
