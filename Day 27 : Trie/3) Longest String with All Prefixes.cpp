struct Node 
{ 
    struct Node *child[26]; 
    bool isEnd;
}; 
struct Node *newNode(void) 
{ 
    struct Node *newNode = new Node; 
    newNode->isEnd = false;
    for (int i = 0; i<26; i++) 
        newNode->child[i] = NULL; 
    return newNode; 
} 

bool chkPrefix(struct Node *root, string word) {
    struct Node *temp = root; 
    for (char c: word) {
      int i = c - 'a';
      temp = temp -> child[i];
      if(!temp || temp->isEnd == false){
        return false;
      }
    }
    return true;
}
void addWord(struct Node *root, string str) 
{ 
    int len = str.length(); 
    struct Node *temp = root; 
  
    for (int i = 0; i<len; i++) 
    { 
        int index = str[i]-'a'; 
        if (!temp->child[index]) 
            temp->child[index] = newNode(); 
        temp = temp->child[index]; 
    } 
    temp ->isEnd = true;
}



string completeString(int n, vector<string> &a) {

    string ans = "";

    struct Node *root = newNode();

    for (string word: a)
      addWord(root, word);

    for (string word: a) {
      if (!chkPrefix(root, word))
        continue;
      if (ans.size() < word.size()) {
        ans = word;
      }
      else if (ans.size() == word.size() && word < ans) {
        ans = word;
      }
    }

    if (ans.size() == 0) {
      ans = "None";
    }

    return ans;
  }

