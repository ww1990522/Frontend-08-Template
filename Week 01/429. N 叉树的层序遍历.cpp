/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int layer_count = 0;
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vvr;
        int cur_layer=0,max_layer=0;
        count_layer(root,cur_layer,max_layer);
        for(int i=0;i<max_layer;i++) {
            vector<int> vr;
            vvr.push_back(vr);
        }
        cur_layer=0;
        levelOrder(root,vvr,cur_layer);
        return vvr;

    }
    void count_layer(Node* root,int& cur_layer,int& max_layer)
    {
        if(root!=nullptr){
            cur_layer++;
            max_layer = cur_layer > max_layer ? cur_layer : max_layer;        
            for(auto a:root->children){
                count_layer(a,cur_layer,max_layer);
            }
        }
        cur_layer--;
    }
    void levelOrder(Node* root,vector<vector<int>>& vvr,int& cur_layer) {
        cur_layer++;
        if(root!=nullptr){
            vvr[cur_layer-1].push_back(root->val);
            for(auto a:root->children){
                levelOrder(a,vvr,cur_layer);
            }
            cur_layer--;
        }
    }
};