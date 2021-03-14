class MyCircularDeque {
private:
    class Node
    {
    public:
        Node* pre = nullptr;
        Node* nxt = nullptr;
        int value;
        Node(int val):value(val){};
    };
    Node* first;
    Node* last;
    int max_size=0;
    int cur_size=0;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        max_size = k;
        first = nullptr;
        last = nullptr;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        Node* new_node = new Node(value);
        if(cur_size == 0){
            first = last = new_node;
        }
        else{
            new_node->nxt = first;
            first->pre = new_node;
            first = new_node;
        }
        cur_size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        Node* new_node = new Node(value);
        if(cur_size == 0){
            first = last = new_node;
        }
        else{
            new_node->pre = last;
            last->nxt = new_node;
            last = new_node;
        }
        cur_size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        if(cur_size==1){
            last = first = nullptr;
        }
        else{
            Node* tmp_node = first->nxt;
            tmp_node->pre = nullptr;
            first = tmp_node;
        }
        cur_size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        if(cur_size==1){
            last = first = nullptr;
        }
        else{
            Node* tmp_node = last->pre;
            tmp_node->nxt = nullptr;
            last = tmp_node;
        }
        cur_size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        return first->value;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
            return -1;
        return last->value;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cur_size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cur_size>=max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */