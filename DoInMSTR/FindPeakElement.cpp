class Solution {
public:
    int findPeakElement(const vector<int> &num) {
          if(num.size() == 0) return -1;
          if(num.size() == 1) return 0;
          if(num[0] > num[1]) return 0;
          if(num[num.size() - 1] > num[num.size() - 2]) return num.size() - 1;
          
          for(int i = 1; i < num.size() - 1; ++i)
             if(num[i] > num[i -1] && num[i] > num[i + 1]) return i;
    }
};
//Code Is too ugly.
//You need to improve it.
