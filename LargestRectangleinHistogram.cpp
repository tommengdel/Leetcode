class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea = 0;
        if(height.size() == 0) return 0;
        vector<int> leftInd(height.size() , -2);
        vector<int> rightInd(height.size(), -2);
        leftInd[0] = -1;
        rightInd[height.size() - 1] = height.size();
        /*
        for(int i = 1; i < height.size(); ++i) {
            if(height[i] > height[i - 1]) {
                leftInd[i] = i - 1;
            }
            else if(height[i] < height[i - 1]) {
                rightInd[i - 1] = i;
            }
            else {
                leftInd[i] = leftInd[i - 1];
                rightInd[i - 1] = rightInd[i];
            }
        }
        
        //针对递增序列，再加上一次预处理
        */
        //可以将leftInd和rightInd作为一个提示
        for(int i = 1; i < height.size(); ++i) {
            if(height[i] > height[i - 1]) {
                leftInd[i] = i - 1;
            } else if(height[i] < height[i - 1]){
                rightInd[i - 1] = i;
            }
            else {
                leftInd[i] = leftInd[i - 1];
            }
        }
        
        for(int i = height.size() - 2; i >= 0; --i) {
            if(height[i] > height[i + 1]) {
                leftInd[i + 1] = leftInd[i];
            }
            else if(height[i] < height[i + 1]) {
                rightInd[i] = rightInd[i + 1];
            }
            else {
                rightInd[i] = rightInd[i + 1];
            }
        }
//这段预处理代码还是有些冗余了。        
        for(int i = 0; i < height.size(); ++i)  {
            int left, right;
            if(leftInd[i] != -2) left = leftInd[i];
          
            while(left >= 0 && height[left] >= height[i]) left--;

            
            if(rightInd[i] != -2) right = rightInd[i];
            //else {
              //   right = i + 1;
            while(right < height.size() && height[right] >= height[i])++right;
   
            //}
            /*
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && height[left] >= height[i]) left--;
            while(right < height.size() && height[right] >= height[i])++right;
            */
            maxArea = max(maxArea, (right - left  - 1) * height[i]);
        }
        return maxArea;
    }
};

//去除了冗余的代码如下
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea = 0;
        if(height.size() == 0) return 0;
        vector<int> leftInd(height.size() , -2);
        vector<int> rightInd(height.size(), -2);
        leftInd[0] = -1;
        rightInd[height.size() - 1] = height.size();
        /*
        for(int i = 1; i < height.size(); ++i) {
            if(height[i] > height[i - 1]) {
                leftInd[i] = i - 1;
            }
            else if(height[i] < height[i - 1]) {
                rightInd[i - 1] = i;
            }
            else {
                leftInd[i] = leftInd[i - 1];
                rightInd[i - 1] = rightInd[i];
            }
        }
        
        //针对递增序列，再加上一次预处理
        */
        //可以将leftInd和rightInd作为一个提示
        for(int i = 1; i < height.size(); ++i) {
            if(height[i] > height[i - 1]) {
                leftInd[i] = i - 1;
            } else if(height[i] < height[i - 1]){
                rightInd[i - 1] = i;
                leftInd[i] = leftInd[i - 1]; //下面那个循环的那一句移上来了
            }
            else {
                leftInd[i] = leftInd[i - 1];
            }
        }
       //本来逆向循环的情况，就是为了处理height[i] <= height[i + 1]的情形
        for(int i = height.size() - 2; i >= 0; --i) {
            if(height[i] > height[i + 1]) {
                //leftInd[i + 1] = leftInd[i];
            }
            else if(height[i] < height[i + 1]) { //这两段也可以合并
                rightInd[i] = rightInd[i + 1];
            }
            else {
                rightInd[i] = rightInd[i + 1];
            }
        }
        
        for(int i = 0; i < height.size(); ++i)  {
            int left, right;
            if(leftInd[i] != -2) left = leftInd[i];
          
            while(left >= 0 && height[left] >= height[i]) left--;

            
            if(rightInd[i] != -2) right = rightInd[i];
            //else {
              //   right = i + 1;
            while(right < height.size() && height[right] >= height[i])++right;
   
            //}
            /*
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && height[left] >= height[i]) left--;
            while(right < height.size() && height[right] >= height[i])++right;
            */
            maxArea = max(maxArea, (right - left  - 1) * height[i]);
        }
        return maxArea;
    }
};

//其实代码写的是不太清晰的，因为我混合使用了i - 1, i , i + 1; 若只是用i + 1和i,则会方便阅读
