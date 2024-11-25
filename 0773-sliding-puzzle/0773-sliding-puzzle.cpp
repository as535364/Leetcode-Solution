class Solution {
private:
    void vec2str (const vector<vector<int>>& board, string &b) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                b[i * 3 + j] = board[i][j] + '0';
            }
        }
    }
    void str2vec (vector<vector<int>>& board, const string &b) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = b[i * 3 + j] - '0';
            }
        }
    }
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid (int r, int c) {
        return 0 <= r && r < 2 && 0 <= c && c < 3;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> vis;
        queue<string> q;
        string b(6, ' ');
        int move = 0;

        vec2str(board, b);
        q.push(b);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                b = q.front();
                q.pop();
                if (b == "123450") return move;
                str2vec(board, b);

                int zeroRow = -1, zeroCol = -1;
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (board[i][j] == 0) {
                            zeroRow = i, zeroCol = j;
                            break;
                        }
                    }
                }

                string tmp(6, ' ');
                for (int d = 0; d < 4; ++d) {
                    int newRow = zeroRow + dir[d][0], newCol = zeroCol + dir[d][1];
                    if (!isValid(newRow, newCol)) continue;
                    swap(board[zeroRow][zeroCol], board[newRow][newCol]);
                    vec2str(board, tmp);
                    if (!vis.count(tmp)) {
                        vis.insert(tmp);
                        q.push(tmp);
                    }
                    swap(board[zeroRow][zeroCol], board[newRow][newCol]);
                }
            }
            move++;
        }
        return -1;
    }
};