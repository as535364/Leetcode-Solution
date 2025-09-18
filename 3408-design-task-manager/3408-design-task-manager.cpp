class TaskManager {
private:
    priority_queue<tuple<int, int, int>> pq; // priority, taskId, userId
    unordered_map<int, int> taskId2Priority;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskId2Priority[taskId] = priority;
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        taskId2Priority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskId2Priority.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()) {
            auto [priority, taskId, userId] = pq.top(); pq.pop();
            int recordPriority = taskId2Priority.find(taskId) == taskId2Priority.end() ? -1 : taskId2Priority[taskId];
            if (priority != recordPriority) continue;
            rmv(taskId);
            return userId;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */