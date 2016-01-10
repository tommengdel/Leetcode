class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int hIndex = 0;
        for(int i = 0; i < citations.size(); ++i) {
            if(citations[i] >= (citations.size() - i)) hIndex = max(hIndex, citations.size() - i);
        }
        return hIndex;
    }
    
    int max(int x, int y) {
        return x >= y ? x : y;
    }
};

Another Approach : use the bucket sort theory.
class Solution {
public:
    int hIndex(vector<int>& citations) {
       vector<int> buckets(citations.size() + 1, 0);
       for(vector<int>::iterator it = citations.begin(); it != citations.end(); ++it) {
           buckets[min(*it, citations.size())]++;
       }
       
       for(int i = buckets.size() - 2; i >= 0; --i) {
           buckets[i] += buckets[i + 1];
       }
       
       int hIndex = 0;
       for(int i = 0; i < buckets.size(); ++i) {
           if(buckets[i] >= i) hIndex = i; //Pay attention to HIndex Definition
       }
       return hIndex;
    }
    
    int min(int x, int y) {
        return x <= y ? x : y;
    }
     int max(int x, int y) {
        return x >= y ? x : y;
    }
};