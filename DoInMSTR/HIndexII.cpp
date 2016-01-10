class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int len = citations.size();
        int low = 0, high = citations.size() - 1;
        int hIndex = 0; //This is very important.
        while(low <= high) {
            int mid = (low + high) / 2;
            //Test if mid is a HIndex value
            // if(len - mid >= mid) {
            //     hIndex = mid;
            //     low = mid + 1;
            // } else high = mid;
            
            //(len - mid) items bigger than citations[mid]
            if(citations[mid] >= (len - mid)) {
                hIndex = max(hIndex, len - mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return hIndex;
    }
};