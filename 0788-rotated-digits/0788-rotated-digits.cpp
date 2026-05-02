class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(isGood(i)){
                cnt += (i != rotate(i));
            }
            
        }
        return cnt;
    }
    
    vector<int> rotateTable = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    
    int rotate(int n){
        string str;
        while(n){
            int x = n % 10;
            str += to_string(rotateTable[x]);
            n /= 10;
        }
        reverse(str.begin(), str.end());
        return stoi(str);
    }
    bool isGood(int n){
        while(n){
            int x = n % 10;
            if(rotateTable[x] == -1)return false;
            n /= 10;
        }
        return true;
    }
};