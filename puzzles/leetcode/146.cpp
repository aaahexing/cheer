/***************************
LRU Cache: https://leetcode.com/problems/lru-cache/

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set. 
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
**/

//---------------------------------------solution 1---------------------------------------------
//TLE
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
	//@time complexity: O(n) in worst case, n means the capacity of the LRC cache
    int get(int key) {
        if(m.find(key) != m.end()) {
            updateList(key);
            return m[key];
        }
          
        return -1;
    }
    
	//@time complexity: O(n) in worst case
    void set(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key] = value;
            updateList(key);
            return;
        }
        
        if (m.size() == capacity) {
            m.erase(keyList.back());
            keyList.pop_back();
        }
        
        keyList.push_front(key);
        m[key] = value;
    }
    
	//@time complexity: O(n) in worst case
    void updateList(int key) {
        keyList.remove(key);
        keyList.push_front(key);
    }
private:
    unordered_map<int, int> m;
    list<int> keyList;
    int capacity;
};

//------------------------------------------solution 2---------------------------------------------
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(keyToNumHash[key] > 0) {
            keyToNumHash[key]++;
            keyQueue.push(key);
            return keyToValueHash[key];
        }
        
        return -1;
    }
    
    void set(int key, int value) {
        if (get(key) != -1) {
            keyToValueHash[key] = value;
            return;
        }
        
        if (keyToValueHash.size() == capacity) {
            while(!keyQueue.empty()) {
                int front = keyQueue.front();
                keyQueue.pop();
                if (keyToNumHash[front] == 1) {
                    keyToNumHash.erase(front);
                    keyToValueHash.erase(front);
                    break;
                }
                
                if (keyToNumHash[front] > 1) {
                    keyToNumHash[front]--;
                }
            }
        }
        
        keyToNumHash[key] = 1;
        keyToValueHash[key] = value;
        keyQueue.push(key);
    }
    
private:
    map<int, int> keyToValueHash;
    map<int, int> keyToNumHash;
    queue<int> keyQueue;
    int capacity;
};