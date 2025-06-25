class PhoneDirectory {
private:
    int n;
    unordered_map<int, list<int>::iterator> availableIt;
    list<int> availableNum;
public:
    PhoneDirectory(int maxNumbers): n(maxNumbers) {
        for (int i = 0; i < n; ++i) {
            availableNum.push_back(i);
            availableIt[i] = prev(availableNum.end());
        }
    }
    
    int get() {
        if (availableNum.empty()) return -1;
        int num = availableNum.front();
        availableNum.pop_front();
        availableIt.erase(num);
        return num;
    }
    
    bool check(int number) {
        return availableIt.find(number) != availableIt.end();
    }
    
    void release(int number) {
        if (availableIt.find(number) != availableIt.end()) return;
        availableNum.push_back(number);
        availableIt[number] = prev(availableNum.end());
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */