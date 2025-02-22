class Logger {
private:
    unordered_map<string, int> lastPrint;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = lastPrint.find(message);
        if (it == lastPrint.end() || timestamp - it -> second >= 10) {
            lastPrint[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */