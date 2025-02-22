class Logger {
private:
    unordered_map<string, int> messageLastPrintTime;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = messageLastPrintTime.find(message);
        if (it == messageLastPrintTime.end() || 
                    messageLastPrintTime[message] + 10 <= timestamp) {
            messageLastPrintTime[message] = timestamp;
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */