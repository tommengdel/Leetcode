#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
    vector<vector<string> > sols;
    deque<string> oneSol;
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, list<string> > DirectedGraph;
        unordered_map<string, int> pathLen;
    
        //Use BFS to construct a graph
        queue<string> q;
        queue<int> len;
        q.push(start); len.push(1);
        pathLen[start] = 1;
        typedef unordered_map<string,int>::iterator umit;
        while(!q.empty()) {
            string curStr = q.front(); int curLen = len.front();
            if(curStr == end) break;
            q.pop(), len.pop();
            
            for(int i = 0; i < curStr.size(); ++i) {
                string temp = curStr;
                for(int j = 'a'; j <= 'z'; ++j) {
                    if(j == curStr[i]) continue;
                    temp[i] = j;
                    
                    if(dict.find(temp) != dict.end()) {
                        umit it = pathLen.find(temp);
                        if(it == pathLen.end()) {
                            q.push(temp); len.push(curLen + 1);
                            pathLen[temp] = curLen + 1;
                            DirectedGraph[temp].push_back(curStr);   
                        }
                        else if(it->second == curLen + 1) {
                            DirectedGraph[temp].push_back(curStr);
                        }
                    }
                    
                }
            }
            
        }
        sols.clear(); oneSol.clear();
        umit it = pathLen.find(end);
        if(it == pathLen.end()) return sols;
        GetAllPath(end, start, DirectedGraph);
        return sols;
    }
    
    void GetAllPath(string& start, string& end, unordered_map<string, list<string> >& DirGraph) {
        if(start == end) {
            oneSol.push_front(end);
            sols.push_back(vector<string>());
            copy(oneSol.begin(), oneSol.end(), back_inserter(sols.back()));
            oneSol.pop_front();
            return;
        }
        
        unordered_map<string, list<string> >::iterator it = DirGraph.find(start);
        oneSol.push_front(start);
        for(list<string>::iterator lit = it->second.begin(); lit != it->second.end(); ++lit)
                GetAllPath(*lit, end, DirGraph);
        oneSol.pop_front();
        
    }
    
    
};
//Accepted 12ms/932ms
//
//A new version
//Do not use map as directed graph; use int
