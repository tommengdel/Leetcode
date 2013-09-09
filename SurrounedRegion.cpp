class Solution {
	static void visit(char &s) {}
	static void visit_set(char &s) { s = 'X';}
	bool InRange(int value, int below, int above) {
		return value >= below && value <= above;
	}
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if(board.size() == 0 || board[0].size() == 0) return;
	vector<int> tmp(board[0].size(), 0);
	vector<vector<int> > mark(board.size(), tmp);
	int markSign = 1;
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[0].size(); ++j) {
			if(board[i][j] == 'O' && mark[i][j] == 0) {
				if(DFS(board, i, j, mark, markSign, visit)) {
					DFS(board, i, j, mark, markSign + 1, visit_set);
				}
			}
		}
	}
    }

    bool DFS(vector<vector<char> >&board, int i, int j, vector<vector<int> >&mark, int markSign, void (*visit)(char &s)) {
	    if(board[i][j] == 'X') return true;
	    mark[i][j] = markSign;
	    visit(board[i][j]);
	    if(!InRange(i, 1, board.size() - 2) || !InRange(j, 1, board[0].size() - 2)) return false;
	    bool ret = true;
	    if(mark[i - 1][j] != markSign && !DFS(board, i - 1, j, mark, markSign, visit)) ret = false;
	    if(mark[i + 1][j] != markSign && !DFS(board, i + 1, j, mark, markSign, visit)) ret = false;
	    if(mark[i][j - 1] != markSign && !DFS(board, i, j - 1, mark, markSign, visit)) ret = false;
	    if(mark[i][j + 1] != markSign && !DFS(board, i, j + 1, mark, markSign, visit)) ret = false;
	    return ret;
    }

};
//´óÊý¾Ý runtime error
