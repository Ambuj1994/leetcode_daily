class Router {
public:

    int memoryLimit;
    queue<vector<int> > q;
    unordered_set<string> st;
    unordered_map<int, vector<int> > mp;
 
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    int lowerBound(vector<int>& arr, int key){
        int n = arr.size();
        int l = 0, h = n - 1;
        int ans = n;

        while(l <= h){
            int mid = l + ((h - l) >> 1);

            if(arr[mid] >= key){
                h = mid - 1;
                ans = mid;
            }
            else
            l = mid + 1;
        }
        return ans;
    }

    int upperBound(vector<int>& arr, int key){
        int n = arr.size();
        int ans = n;
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = l + ((h - l) >> 1);

            if(arr[mid] > key){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet(3);
        string pkt = to_string(source)+"_"+to_string(destination)+"_"+to_string(timestamp);
        if(st.find(pkt) != st.end()) return false;

        packet[0] = source;
        packet[1] = destination;
        packet[2] = timestamp;
        if(q.size() == memoryLimit){
            vector<int> tmp = q.front();
            q.pop();
            string pack = to_string(tmp[0])+"_"+to_string(tmp[1])+"_"+to_string(tmp[2]);
            st.erase(pack);
            mp[tmp[1]].erase(mp[tmp[1]].begin());
        }
        st.insert(pkt);
        q.push(packet);
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};

        vector<int> pkt = q.front();
        q.pop();
        string pack = to_string(pkt[0])+"_"+to_string(pkt[1])+"_"+to_string(pkt[2]);
        st.erase(pack);
        mp[pkt[1]].erase(mp[pkt[1]].begin());

        return pkt;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<int>& arr = mp[destination];
        int lb = lowerBound(arr, startTime);
        int ub = upperBound(arr, endTime);

        return (ub - lb);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

/*
Notes & Learnings from Router Implementation:

1. Vector initialization mistake:
   - I tried: vector<int> packet; then did packet[0] = source; (WRONG)
   - Fix: initialize with size: vector<int> packet(3); so indices 0,1,2 are valid.

2. Queue iteration:
   - Can't directly iterate over queue with for-each (unlike vector).
   - Instead, process using q.front() / q.pop() or copy to another container.

3. Hash set (unordered_set):
   - Stores only unique keys.
   - I used string key = "src_dest_time" to check for duplicate packets.

4. lowerBound / upperBound:
   - Needed for efficient range queries in sorted vectors.
   - My first version returned wrong index because I didn't handle `ans` properly.
   - Correct approach: update ans when condition satisfied and keep searching.

5. Maintaining sorted order:
   - Important that mp[destination] (timestamps) stays sorted.
   - Since addPacket always inserts increasing timestamp, vector remains sorted.

6. Memory management bug:
   - While popping from queue due to memoryLimit, I mistakenly erased using wrong 'destination'.
   - Correct fix: erase timestamp from mp[tmp[1]], not current 'destination'.

7. Return type issues:
   - If q is empty in forwardPacket, must return {} (empty vector) to avoid UB.

Key Takeaway:
- Always size vectors before indexing.
- Queue doesn’t allow direct iteration.
- Maintain consistent mapping in mp while pushing/popping.
- Use lowerBound/upperBound carefully (edge cases matter).
- Debugging step-by-step helped catch logical vs syntax errors.
*/

