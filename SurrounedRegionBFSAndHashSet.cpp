#include<set>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<iterator>
#include<cctype>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char Mark = 'M';
        if(board.size() == 0 || board[0].size() == 0) return;
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'O')
                    if(BFS(board, i , j, Mark))
                        BFS(board, i, j, 'N');
            }
            
            
        for(int i = 0; i < board.size(); ++i) {
            replace(board[i].begin(), board[i].end(), Mark, 'O');
            replace(board[i].begin(), board[i].end(), 'N', 'X');

        }
    
        
    }
    bool InRange(int val, int below, int above) {
        return val >= below && val <= above;
    }
    void print(vector<vector<char> >&board) {
	    for(int i = 0; i < board.size(); ++i) {
		    copy(board[i].begin(), board[i].end(), ostream_iterator<char>(cout, " "));
		    cout<<endl;
	    }
    } 
    bool BFS(vector<vector<char> >&board, int i, int j, char Mark) {
        struct Index {
            int r, c;
            Index(int r = 0, int c = 0) : r(r), c(c) {}
	    Index() {}
	    bool operator <(const Index &i2) const {
		    return r < i2.r && (r == i2.r && c < i2.c);
	    }
        };
        queue<Index> q;
        q.push(Index(i, j));
        int count = 0;
        
        bool ret = true;
        while(!q.empty()) {
            Index t = q.front(); q.pop();

            if(!InRange(t.r, 1, board.size() - 2) || !InRange(t.c, 1, board[0].size() - 2)) ret = false;
            
            board[t.r][t.c] = Mark;
	    cout<<t.r<<" "<<t.c<<" "<<endl;
	    if(count > 10) break;
            if(count++ > 10 * board.size() * board[0].size()){
		    cout<<"Count"<<count<<endl;
		    print(board);
		    break;    
	    }
            if(t.r > 0 && board[t.r - 1][t.c] != 'X' && board[t.r - 1][t.c] != Mark ) q.push(Index(t.r - 1, t.c));
            if(t.r < board.size() - 1 && board[t.r + 1][t.c] != 'X'&& board[t.r + 1][t.c] != Mark) q.push(Index(t.r + 1, t.c));
            if(t.c > 0 && board[t.r][t.c - 1] != 'X'&& board[t.r][t.c - 1] != Mark) q.push(Index(t.r, t.c - 1));
            if(t.c < board[0].size() - 1 && board[t.r][t.c + 1] != 'X' && board[t.r][t.c + 1] != Mark) q.push(Index(t.r, t.c + 1));
        }
	cout<<endl<<endl;
        return ret;
    }
};
bool isalpha(char c) {
	return c == 'O'  || c == 'X';
}
int main() {
   ifstream in("SurroundRegionData");
   string data;
   getline(in, data);
   int commaNum = count(data.begin(), data.end(), ',');
   int m = commaNum + 1;
   int n = (data.size() - 1) / m - 3;
   int alphaNum =  count(data.begin(), data.end(), 'O') + count(data.begin(), data.end(), 'X');

   vector<vector<char > > s(m);
   int index = 0;
   cout<<alphaNum<<endl;
   cout<<m * n<<endl;
   for(int i = 2; i < data.size() - 1; i += n + 3) {
	   copy(data.begin() + i, data.begin() + i + n, back_inserter(s[index]));
	   copy(s[index].begin(), s[index].end(), ostream_iterator<char>(cout, " "));
	   cout<<endl;
	    
	   ++index;
   }
   Solution().solve(s);
   

}
