class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       if(nums.size() < 3) return false;
       //triple1[1..3] triple2[1..3]
       vector<int> triple1, triple2;
       triple1.push_back(nums[0]);
       for(int i = 1; i < nums.size(); ++i) {
           if(triple1.size() == 1){
               if(triple1.back() < nums[i]) triple1.emplace_back(nums[i]);
               else triple1[0] = nums[i];
           }
           else if(triple1.size() == 2) {
               if(triple1[1] < nums[i]) return true;
               else if(triple1[0] < nums[i]) {
                   triple1[1] = nums[i];
               } else if(nums[i] <= triple1[0]) {
                    //move it into triple2[0]
                    if(triple2.size() == 0) {
                        triple2.push_back(nums[i]);
                    } else if(triple2.size() == 1) {
                        if(triple2.back() > nums[i]) triple2[0] = nums[i];
                        else if(triple2.back() < nums[i]) triple2.emplace_back(nums[i]);
                    } else if(triple2.size() == 2) {
                        if(triple2.back() <  nums[i]) return true;
                        else if(triple2[0] < nums[i]) triple2[1] = nums[i];
                        else {
                            triple1.swap(triple2);
                            triple2.resize(1);
                            triple2[0] = nums[i];
                        }
                    }
               }
               
           }
           
           
       }
       return false;
       
    }
};