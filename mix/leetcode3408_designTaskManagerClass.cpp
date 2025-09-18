class TaskManager {
public:
    #define P pair<int, int>
    #define PP pair<int, P>

    set<PP, greater<PP>> st;  //{priority , <taskId, userId>}
    unordered_map<int, P> mp; //{taskId, {priority, userId} }

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks){
           st.insert({task[2], {task[1], task[0]}} );
           mp[task[1]] = {task[2], task[0]};
        }

    }
    
    void add(int userId, int taskId, int priority) {
           mp[taskId] = {priority, userId};
           st.insert({priority, {taskId, userId}});       
    }
    
    void edit(int taskId, int newPriority) {
        auto task = mp[taskId];
        int userId = task.second;
        int oldPriority = task.first;

        auto taskTemp = st.find({oldPriority, {taskId, userId}});
        if (taskTemp != st.end()) {
           st.erase(taskTemp);
        }
        st.insert({newPriority, {taskId, userId}});

        mp[taskId] = {newPriority, userId};
    }
    
    void rmv(int taskId) {
        auto task = mp[taskId];
        int userId = task.second;
        int priority = task.first;

        mp.erase(taskId);
        st.erase({priority ,{taskId, userId} });
    }


    
    int execTop() {
        if(st.empty()) return -1;

        auto task = st.begin();
        
        int taskId = (task->second).first;
        int userId = (task->second).second;
        mp.erase(taskId);
        st.erase(task);
        
        return userId;
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

/*
==================== LEARNING NOTES ====================

🔹 Iterators (* and ->)
- *iterator → gives the value stored at that iterator.
  Example:
    set<int> st = {10, 20};
    auto it = st.begin();
    cout << *it; // 10

- iterator->member → used when iterator points to a pair (map, set<pair<...>>).
  Example:
    map<int,string> mp = {{1,"one"}};
    auto it = mp.begin();
    cout << it->first;   // key = 1
    cout << it->second;  // value = "one"

--------------------------------------------------------

🔹 erase in set/map
There are 3 ways to erase:

1. By key/value
    st.erase(20);    // erase element with value 20
    mp.erase(1);     // erase element with key 1

2. By iterator
    auto it = st.find(10);
    if(it != st.end()) st.erase(it); // remove 10

3. By range
    st.erase(st.begin(), st.end()); // clear all

⚠️ Rule: After erase(iterator), that iterator is INVALID.  
   👉 Accessing it later (like task->first, task->second) is **undefined behavior (UB)**.  
   This was the big mistake I made in TaskManager (erasing and then calling task->first).  
   ✅ Fix: Save values first, then erase.

--------------------------------------------------------

🔹 remove vs erase
- Associative containers (set/map/unordered_map) → only erase is used.
- std::remove → algorithm for vectors/lists, does not shrink container.
  Example:
    vector<int> v = {1,2,3,2};
    v.erase(remove(v.begin(), v.end(), 2), v.end()); // removes all 2's

--------------------------------------------------------

🔹 Safe erase pattern
Always save values before erasing:
    auto it = st.begin();
    int val = it->first;   // save key/priority etc.
    int uid = it->second;  // save userId etc.
    st.erase(it);          // erase safely
    cout << val << " " << uid; // safe

--------------------------------------------------------

🔹 unordered_map basics
Insert / Update:
    unordered_map<int,string> ump;
    ump[1] = "one";             
    ump.insert({2, "two"});

Find:
    auto it = ump.find(1);
    if(it != ump.end()) cout << it->second;

Erase:
    ump.erase(1);                 // erase by key
    auto it = ump.find(2);
    if(it != ump.end()) ump.erase(it); // erase by iterator

========================================================
*/

