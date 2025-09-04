class LRUCache {
public:
    int capacity;
    struct ListNode{
        int val;
        int key;
        ListNode* prev;
        ListNode* next;
        ListNode() : val(0), key(0), prev(nullptr), next(nullptr){};
        ListNode(int k,int v) : val(v), key(k), prev(nullptr), next(nullptr){};
    };
    
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    void insertAfterHead(ListNode* node){
        ListNode* first = head->next;
        node->next = first;
        node->prev = head;
        first->prev = node;
        head->next = node;
    }
    void deleteNode(ListNode* node){
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        mp.erase(node->key);
        delete node;
    }
    void moveInFront(ListNode* node){
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        insertAfterHead(node);        
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            ListNode* node = mp[key];
            moveInFront(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            ListNode* node = mp[key];
            node->val = value;
            moveInFront(node);
        }
        else{
            if(mp.size() == capacity){
                deleteNode(tail->prev);
            }
                ListNode* node = new ListNode(key, value);
                insertAfterHead(node);
                mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
