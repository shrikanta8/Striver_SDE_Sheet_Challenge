class LRUCache {
public:
    class Node{
        public:
        Node* next,*prev;
        int key, val;
        Node(int _key,int _value){
            key=_key;
            val=_value;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node){
        //delete location of node?
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertNode(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node=mp[key];
            int ans=node->val;
            // mp.erase(key); // extra
            deleteNode(node);
            insertNode(node);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existingNode=mp[key];
             mp.erase(key);  //we are removing it bcose in below in mp.size() we will be getting the wrong result as one is getting duplicated
            deleteNode(existingNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode= new Node(key,value);
        insertNode(newNode);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



---------------------------------------------------------------------------------------

class LRUCache {
public:
    list<pair<int,int>> l;
    int size;
    unordered_map<int,list<pair<int,int>>::iterator> mp;    //in map ...list<pair<int,int>>::iterator keeps the address of the  list l
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            l.splice(l.begin(),l,mp[key]);      //bringing key's address to the first position 
            return mp[key]->second;     // mp[key] =  address of list l
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            l.splice(l.begin(),l,mp[key]);  //bringing key's address to the first position 
            mp[key]->second = value;        //updating the new value
            return;
        }
        if(l.size()== size){
            auto deleteKey = l.back().first;    //keeping in a variable bcose we have to delete it from map 
            l.pop_back();       //poping from list
            mp.erase(deleteKey);    //deleting from map
        }
        l.push_front({key,value});  //recent value on front
        mp[key]=l.begin();  //address is the value in map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
