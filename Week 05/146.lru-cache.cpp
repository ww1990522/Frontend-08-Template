
struct CacheNode
{
public:
    int _key, _value;
    CacheNode *_pre, *_next;
    CacheNode(int key = 0, int value = 0):
    _key(key), _value(value), _pre(nullptr), _next(_pre){};       
};
class LRUCache {
public:

    LRUCache(int capacity) {
        _capacity = capacity;
        _head = nullptr;
        _tail = nullptr;
    }
    
    int get(int key) {
        if(_map_nodes.count(key) == 0)
            return -1;
        Move2Head(key);
        return _map_nodes[key]->_value;
    }
    
    void put(int key, int value) {
        if(_map_nodes.count(key) > 0){
            _map_nodes[key]->_value = value;
            Move2Head(key);
        }
        else {
            if(_map_nodes.size()==_capacity){        
                _map_nodes.erase(_tail->_key);
                if(_tail->_pre) _tail->_pre->_next = nullptr;
                if(_tail == _head)  
                    _head = _tail = nullptr;
                else
                    _tail = _tail->_pre;
            }
            InsertHead(key, value);
        }
    }
private:
    void Move2Head(int key){
        if(key == _head->_key)
            return;
        if(key == _tail->_key)
            _tail = _tail->_pre;
        
        CacheNode *tmp_node = _map_nodes[key];
        tmp_node->_pre->_next = tmp_node->_next;
        if(tmp_node->_next) tmp_node->_next->_pre = tmp_node->_pre;
        tmp_node->_next = _head;
        _head->_pre = tmp_node;
        _head = tmp_node;
    }
    void InsertHead(int key, int value){
        CacheNode *new_node = new CacheNode(key, value);
        if(!_head){
            _head = new_node;
            _tail = new_node;
        }
        else{
            new_node->_next = _head;
            _head->_pre = new_node;
            _head = new_node;
        }
        _map_nodes[key] = new_node;
    }

    int _capacity;
    unordered_map<int, CacheNode*> _map_nodes;
    CacheNode *_head, *_tail;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */