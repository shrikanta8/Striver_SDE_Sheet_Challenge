vector <int> bottomView(Node *root)
{
    vector <int> v;
    if(!root)
        return v ;
    
    queue<pair<Node* , int>> q;
    
    map<int,int>mp;
    q.push({root,0});
    Node* temp=NULL;
    
    while(q.size()){
        temp=q.front().first;
        int num = q.front().second;
        q.pop();
        mp[num] = temp->data;
        if(temp->left)
            q.push({temp->left,num-1});
        if(temp->right)
            q.push({temp->right,num+1});
    }
    for(auto i : mp)
        v.push_back(i.second);
    return v;
}
