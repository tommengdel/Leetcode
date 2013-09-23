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
        
        //��Ե������У��ټ���һ��Ԥ����
        */
        //���Խ�leftInd��rightInd��Ϊһ����ʾ
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
//���Ԥ������뻹����Щ�����ˡ�        
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

//ȥ��������Ĵ�������
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
        
        //��Ե������У��ټ���һ��Ԥ����
        */
        //���Խ�leftInd��rightInd��Ϊһ����ʾ
        for(int i = 1; i < height.size(); ++i) {
            if(height[i] > height[i - 1]) {
                leftInd[i] = i - 1;
            } else if(height[i] < height[i - 1]){
                rightInd[i - 1] = i;
                leftInd[i] = leftInd[i - 1]; //�����Ǹ�ѭ������һ����������
            }
            else {
                leftInd[i] = leftInd[i - 1];
            }
        }
       //��������ѭ�������������Ϊ�˴���height[i] <= height[i + 1]������
        for(int i = height.size() - 2; i >= 0; --i) {
            if(height[i] > height[i + 1]) {
                //leftInd[i + 1] = leftInd[i];
            }
            else if(height[i] < height[i + 1]) { //������Ҳ���Ժϲ�
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

//��ʵ����д���ǲ�̫�����ģ���Ϊ�һ��ʹ����i - 1, i , i + 1; ��ֻ����i + 1��i,��᷽���Ķ�
