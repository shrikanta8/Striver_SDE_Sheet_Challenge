/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root)
            return ans;
        
        //doing level order
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            
            auto f = q.front();
            q.pop();
            if(f==NULL)
                ans.append("#,");   //appends characters in the end of string, # is NULL node here
            else
                ans.append(to_string(f->val) + ",");
            
            if(f){
                q.push(f->left);
                q.push(f->right);
            }
        }
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0)    //no tree
            return NULL;
        
        stringstream s(data);  
        //stringstream associates a string object with a stream allowing you to read from the string as if it were a stream 
        
        string str;
        getline(s,str,',');
        //it will iterate over s string and give us values one by one 
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto f = q.front();
            q.pop();
            
            //for left side
            getline(s,str,',');
            
            if(str=="#"){   //it's NULL node
                f->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                f->left = leftNode;
                q.push(leftNode);
            }
            
            //for right side
            getline(s,str,',');
            if(str=="#"){
                f->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                f->right = rightNode;
                q.push(rightNode);
            }
        }
    
        
        return root;
    }
};
