class Trie {
public:
    struct Node{
        public:
        bool exist = false;
        map<char, Node*> next;
    };
    Node * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(search(word))
            return;
        
        Node* tmp = root;
        for(auto c : word){
            if(tmp->next.count(c)==0){
                Node * t = new Node;
                tmp->next[c] = t;
            }
            tmp = tmp->next[c];
        }
        if(!tmp->exist) tmp->exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* tmp = root;
        for(auto c : word){
            if(tmp->next.count(c)==0){
                return false;
            }
            tmp = tmp->next[c];
        }
        return tmp->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(auto c : prefix){
            if(tmp->next.count(c)==0){
                return false;
            }
            tmp = tmp->next[c];
        }
        return true;
    }
};