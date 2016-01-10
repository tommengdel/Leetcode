class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
       if(n == 1) return vector<int>(1, 0);
       vector<int> degs(n, 0);
       map<int, vector<int>> graph;
       for(vector<pair<int, int>> ::iterator itor = edges.begin(); itor != edges.end(); ++itor) {
           graph[itor->first].push_back(itor->second);
           graph[itor->second].push_back(itor->first);
           
           ++degs[itor->first];
           ++degs[itor->second];
       }
       
       vector<int> nodes;
       for(int i = 0; i < degs.size(); ++i) {
           if(degs[i] == 1) nodes.push_back(i);
       }
    
       int remainNodes = n;
       while(remainNodes > 2) {
           remainNodes -= nodes.size();
           vector<int> nextHierNodes;
           
           for(vector<int>::iterator itor = nodes.begin(); itor != nodes.end(); ++itor) {
               vector<int> &edges = graph[*itor];
               for(vector<int>::iterator edgePtr = edges.begin(); edgePtr != edges.end(); ++edgePtr) {
                   --degs[*edgePtr];
                   if(degs[*edgePtr] == 1) nextHierNodes.push_back(*edgePtr);
               }
           }
           
           nodes.swap(nextHierNodes);
       }
       
       return nodes;
       
    }
};