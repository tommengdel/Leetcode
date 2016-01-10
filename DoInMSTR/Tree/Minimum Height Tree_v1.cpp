class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) {
            vector<int> result(1, 0);
            return result;
        }
        map<int, list<int>> graph;
        map<int, int> vDeg;
        vector<pair<int, int>>:: iterator it;
        map<int, int> ::iterator degItor;
        //Init
        for(it = edges.begin(); it != edges.end(); ++it) {
            int v1 = it->first, v2 = it->second;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
            
            vDeg[v1]++;
            vDeg[v2]++;
        }
        
        //fetch the set that has degree 1
        list<int> nodes;
        for(degItor = vDeg.begin(); degItor != vDeg.end(); ++degItor) {
            if(degItor->second == 1) nodes.push_back(degItor->first);
        }
        int remainingNodes = vDeg.size();
        
         
        
         while(remainingNodes > 2) {
            //Discard the nodes;
            remainingNodes -= nodes.size();
            list<int> nextNodes;
            
            for(list<int> :: iterator itor = nodes.begin(); itor != nodes.end(); ++itor) {
                list<int> &edges = graph[*itor];
                for(list<int> ::iterator itor2 = edges.begin(); itor2 != edges.end(); ++itor2) {
                    --vDeg[*itor2];
                    if(vDeg[*itor2] == 1) nextNodes.push_back(*itor2);
                }
            }
            
            //swap nodes and nextNodes
            nodes.swap(nextNodes);
        }
        
        vector<int> result(nodes.begin(), nodes.end());
        return result;
    }
};