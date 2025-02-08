class NumberContainers {
private:
    unordered_map<int, int> stored;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> indexs;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        stored[index] = number;
        indexs[number].push(index);
    }
    
    int find(int number) {
        if (indexs.find(number) == indexs.end()) return -1;
        while (!indexs[number].empty()) {
            if (stored[indexs[number].top()] == number) return indexs[number].top();
            else indexs[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */