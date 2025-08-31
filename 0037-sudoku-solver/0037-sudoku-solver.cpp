class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        dfs(0, 0, board);
        return;
    }
    bool isOK(int x,int y, const vector<vector<char>> &field){ // 回傳擺完數字後 當前數獨是否合法
        bitset<9> b1(0), b2(0), b3(0);//直的 橫的 九宮格
        // 直的
        for(int i = 0; i < 9; ++i){
            char tmp = field[x][i];
            if(tmp == '.')continue;
            else if(b1.test(tmp - '1'))return false;
            else b1.set(tmp - '1');
        }
        // 橫的
        for(int i = 0;i < 9; ++i){
            char tmp = field[i][y];
            if(tmp == '.')continue;
            else if(b2.test(tmp - '1'))return false;
            else b2.set(tmp - '1');
        }	
        // 九宮格
        int g1 = x / 3,g2 = y / 3;//把數獨分成 3 * 3 組
        int sx = g1 * 3,sy = g2 * 3;//該組左上角的座標
        for(int i = sx; i <= sx + 2; ++i){
            for(int j = sy; j <= sy + 2; ++j){
                char tmp = field[i][j];
                if(tmp == '.')continue;
                else if(b3.test(tmp - '1'))return false;
                else b3.set(tmp - '1');
            }
        }
        return true;
    }
    bool dfs(int x, int y, vector<vector<char>> &board){ // 處理 row: x col: y
        if(x > 8)
            return true;
        bool flag = false;
        if(board[x][y] != '.'){ // 已有數字
            // cout << "已有數字: " << x << " " << y << " " << board[x][y] << endl;
            if(y < 8)flag |= dfs(x, y + 1, board); // 右邊
            else flag |= dfs(x + 1, 0, board); // 下列
        }
        else{ // 沒有數字就試擺看看
            for(int i = 1; i <= 9; ++i){
                board[x][y] = '0' + i;
                // cout << "在 " << x << " " << y << " 試擺 " << board[x][y] << endl;
                if(isOK(x, y, board)){ // 擺完還 ok 就繼續
                    if(y < 8)flag |= dfs(x, y + 1, board); // 右邊
                    else flag |= dfs(x + 1, 0, board); // 下列
                }
                if(!flag)board[x][y] = '.'; // 恢復
                else break;
            }
        }
        return flag;
    }
};