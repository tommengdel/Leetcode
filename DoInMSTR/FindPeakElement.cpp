class Solution {
public:
    int findPeakElement(const vector<int> &num) {
          if(num.size() == 0) return -1;
          int peak = 0; 
          while(peak < num.size() - 1) {
              if(num[peak] > num[peak + 1]) break;
              else ++peak;
          }
          return peak;
    }
};
//Remove useless comparison
