class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int forward = 0, backward = s.size() - 1;
        bool ret = true;
        
        
        while(forward < s.size() && !isalnum(s[forward])) ++forward;
        while(backward > - 1 && !isalnum(s[backward])) --backward;
        
        while(forward < backward) {
            if(toupper(s[forward]) != toupper(s[backward])) {
                ret = false;
                break;
            }
            ++forward; --backward; //���Ǽ���һ�У�������ѭ��
            while(forward < s.size() && !isalnum(s[forward])) ++forward;
            while(backward > - 1 && !isalnum(s[backward])) --backward;
            
        }
        return ret;
    }
};
//�Ұ�10��11�еĶ����հᵽ19,20. �����ˡ�
//���õ������ͬ��
//������18�оͻᵼ����ѭ����
//��Ϊ10,11�У����ܲ������forward ��backward
//�ƺ���ȱ���ر������ĳ�������ͼ��
