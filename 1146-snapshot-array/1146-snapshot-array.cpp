class SnapshotArray {
private:
    map<int, unordered_map<int, int>> snapVal;
    int time;
    
public:
    SnapshotArray(int length): time(0) {
        
    }
    
    void set(int index, int val) {
        snapVal[time][index] = val;
    }
    
    int snap() {
        return time++;
    }
    
    int get(int index, int snap_id) {
        auto timeIt = snapVal.upper_bound(snap_id);
        if (timeIt == snapVal.begin()) return 0;
        
        while (timeIt != snapVal.begin()) {
            auto valIt = prev(timeIt) -> second.find(index);
            if (valIt != prev(timeIt) -> second.end()) return valIt -> second;
            advance(timeIt, -1);
        }
        return 0;

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */