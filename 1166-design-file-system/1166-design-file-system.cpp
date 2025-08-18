class FileSystem {
private:
    unordered_map<string, int> storedPath;
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        string parentPath = path.substr(0, path.find_last_of('/'));
        if (storedPath.find(path) != storedPath.end()) return false;
        if (!parentPath.empty() && storedPath.find(parentPath) == storedPath.end()) return false;
        storedPath[path] = value;
        return true;
    }
    
    int get(string path) {
        return storedPath.find(path) == storedPath.end() ? -1 : storedPath[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */