/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* func(Node* node, unordered_map<int,Node*>& visit){
        Node* new_node = new Node(node->val);
        visit[node->val] = new_node;
        
        for(Node* nei : node -> neighbors){
            if(visit.find(nei->val) == visit.end()){    //not visited
                Node* c = func(nei,visit);
                new_node->neighbors.push_back(c);
            }
            else{
                new_node->neighbors.push_back(visit[nei->val]);
            }
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<int,Node*> visit;
        return func(node,visit);
    }
};
