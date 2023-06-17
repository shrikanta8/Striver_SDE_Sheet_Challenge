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
