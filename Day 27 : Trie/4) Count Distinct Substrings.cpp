class Node
{
  public:
      Node *child[26];
};

void add(string &s, int i, Node *temp)
{
    Node *val = temp;
    int n = s.length();
    while (i < n)
    {
        char ch = s[i];
        if (val->child[ch - 'a'] == NULL){
            val->child[ch - 'a'] = new Node();
        }
        val = val->child[ch - 'a'];
        i++;
    }
}

int count(Node *root)
{
    if (root == NULL){
        return 0;
    }
    int val = 1;
    for (int i = 0; i < 26; i++){
        val += count(root->child[i]);
    }
    return val;
}

int countDistinctSubstrings(string &s)
{
    int n = s.length();
    Node *temp = new Node();
    for (int i = 0; i < n; i++){
        add(s, i, temp);
    }
    int ans = count(temp);
    return ans;
}
