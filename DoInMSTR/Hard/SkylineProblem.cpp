
 bool pairEqual(pair<int, int>& p1, pair<int, int> &p2) {
         return p1.second == p2.second;
     }
class Solution {
     
     vector<pair<int, int>> merge(vector<pair<int,int>>& leftSky, vector<pair<int, int>>& rightSky) {
         int left = 0, right = 0;
         vector<pair<int, int>> mergeResult;
         while(left < leftSky.size() && right < rightSky.size()) {
             if(leftSky[left].first > rightSky[right].first) {
                 //rightSky[right].second = height
                // if(left - 1 < 0 || (rightSky[right].second > leftSky[left - 1].second)) mergeResult.push_back(rightSky[right]);
                
                int maxHeight = rightSky[right].second;
                if(left - 1 >= 0) maxHeight = max(maxHeight, leftSky[left - 1].second);
                mergeResult.emplace_back(rightSky[right].first, maxHeight);
                 ++right;
             } else if(leftSky[left].first < rightSky[right].first) {
                //  if(right - 1 < 0 || leftSky[left].second > rightSky[right - 1].second) mergeResult.push_back(leftSky[left]);
                int maxHeight = leftSky[left].second;
                if(right - 1 >= 0) maxHeight = max(maxHeight, rightSky[right - 1].second);
                mergeResult.emplace_back(leftSky[left].first, maxHeight);
                 ++left;
             } else {
                 //push the one with higher height
                 mergeResult.push_back(max(leftSky[left], rightSky[right]));
                 ++right; ++left;
             }
         }
         
         //clear the battle
         while(left < leftSky.size()) mergeResult.push_back(leftSky[left++]);
         while(right < rightSky.size()) mergeResult.push_back(rightSky[right++]);
         
         return mergeResult;
         
     }
     
     vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings, int left, int right) {
         vector<pair<int, int>> result;
         if(left > right) return result;
         if(left == right) {
             result.emplace_back(buildings[left][0], buildings[left][2]);
             result.emplace_back(buildings[left][1], 0);
             return result;
         }
         int mid = (right - left) / 2 + left;
         vector<pair<int, int>> leftResult = getSkyline(buildings, left, mid);
         vector<pair<int, int>> rightResult = getSkyline(buildings, mid + 1, right);
         
         return merge(leftResult, rightResult);
     }
     
    
     
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        if(buildings.size() < 1) return result;
        
        result = getSkyline(buildings, 0, buildings.size() - 1);
        
        //remove the consecutive duplicate
       vector<pair<int, int>> :: iterator it= unique(result.begin(), result.end(), pairEqual);
       result.resize(std::distance(result.begin(), it));
       return result;
    }
};