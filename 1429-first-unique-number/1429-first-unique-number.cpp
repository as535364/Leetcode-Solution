class FirstUnique {
private:
    unordered_map<int, pair<bool, list<int>::iterator>> mp;
    list<int> l;
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        return l.empty() ? -1 : *l.begin();
    }
    
    void add(int value) {
        if (mp.find(value) != mp.end()) {
            if (!mp[value].first) {
                l.erase(mp[value].second);
                mp[value].first = true;
            }
        }
        else {
            l.push_back(value);
            mp[value].first = false;
            mp[value].second = prev(l.end());
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */