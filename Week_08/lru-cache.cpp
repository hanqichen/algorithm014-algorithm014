struct DLinkNode {
    int key, val;
    DLinkNode* prev;
    DLinkNode* next;
    DLinkNode() : key(0), val(0), prev(nullptr), next(nullptr) {};
    DLinkNode(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    DLinkNode* head;
    DLinkNode* tail;
    unordered_map<int, DLinkNode*> cache;
    int capacity;
    int size;

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if(!cache.count(key)) {
            DLinkNode* node = new DLinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if (size > capacity) {
                size--;
                DLinkNode* removed = getTail();
                removeNode(removed);
                cache.erase(removed->key);
                delete removed;
            }
        } else {
            DLinkNode* node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }

    void removeNode(DLinkNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void addToHead(DLinkNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkNode* getTail() {
        DLinkNode* res = tail->prev;
        res->prev->next = tail;
        tail->prev = res->prev;
        return res;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */