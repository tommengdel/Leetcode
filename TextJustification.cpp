//unnormal cases:
//  A line other than the last line might contain only one word
//  Only one Line
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<string> sols;
	if(words.size() == 0) return sols;
	int left = 0;
	while(left < words.size())  {
		int right = left - 1;
		int curLen = 0;
		cout<<curLen + words[right + 1].size() + right + 1 - left<<endl;
//		while(right < words.size() && (curLen + words[right + 1].size() + right + 1 - left <= L))  { //我知道这一句话错误的原因了，因为right被转换成unsigned int,在与words.size()这个unsigned int比较时候
		while(right + 1 < words.size() && curLen + words[right + 1].size() + right + 1 - left <= L) {
			++right;
			curLen += words[right].size();
		}
		//words[left...right]
		int space, extra;
		string oneLine;
		if(right - left != 0) {
		    space = (L - curLen) / (right - left);
		    extra = (L - curLen) % (right - left);
	            
//		    if(right == words.size() - 1) extra = 0;
		    if(right == words.size() - 1) {
			    extra = 0;
			    space = 1; //此处我忘记考虑的地方。 导致的错误测试用例：["What","must","be","shall","be."], 12	在最后一行的shall be。出错
		    }


		    for(int i = left; i < right; ++i) {
			oneLine += words[i];
			fill_n(back_inserter(oneLine), space + (extra-- > 0 ? 1 : 0), ' ');
		    }
	            oneLine += words[right];
		    if(right == words.size() - 1) fill_n(back_inserter(oneLine), L - curLen - (right - left), ' ');

		} else {
		    oneLine += words[left];
		    fill_n(back_inserter(oneLine), L - curLen, ' ');
		}
		

		sols.push_back(oneLine);
		

		//Update Left
		left = right + 1;
	}
	return sols;
    }
};



int main() {
	vector<string> vec = {""};
	int l = 0;
	Solution().fullJustify(vec, l);
}
