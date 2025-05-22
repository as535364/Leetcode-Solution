class MovingAverage {
private:
    int size;
    double sum;
    list<int> li;
public:
    MovingAverage(int size): size(size), sum(0) {
        
    }
    
    double next(int val) {
        li.push_back(val);
        sum += val;
        
        if (li.size() > size) {
            sum -= li.front();
            li.pop_front();
        }
        return sum / li.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */