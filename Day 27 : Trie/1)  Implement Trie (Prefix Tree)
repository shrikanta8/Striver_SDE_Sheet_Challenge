struct Node{
    // public:
    bool flag= false;
    vector<Node*> child;
    
    Node(){
        child.resize(26);
    }
    bool isPresent(char ch){
        return child[ch-'a'] != NULL;
    }
    
    void addValue(char ch, Node* val){
        child[ch-'a'] = val;
    }
    bool isWordEnd(){
        return flag ;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int len = word.length();
        Node* temp = root;
        
        for(int i=0;i<len;i++){
            if(temp->isPresent(word[i]) == false){
                temp->addValue(word[i],new Node());
            }
            temp = temp->child[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        int len = word.length();
        Node* temp = root;
        
        for(int i=0;i<len;i++){
            if( temp->isPresent(word[i]) == false )
                return false;
            temp = temp->child[word[i] - 'a'];
        }
        return temp->isWordEnd();
    }
    
    bool startsWith(string prefix) {
        int len = prefix.length();
        Node* temp = root;
        
        for(int i=0;i<len;i++){
            if( temp -> isPresent(prefix[i]) == false )
                return false;
            temp = temp->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
