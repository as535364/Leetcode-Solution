class SnapshotArray {
private:
    unordered_map<int, map<int, int>> changeVal;
    int time;
    
public:
    SnapshotArray(int length): time(0) {
        for (int i = 0; i < length; ++i) {
            changeVal[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        changeVal[index][time] = val;
    }
    
    int snap() {
        return time++;
    }
    
    int get(int index, int snap_id) {
        auto it = changeVal[index].upper_bound(snap_id);
        return prev(it) -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */