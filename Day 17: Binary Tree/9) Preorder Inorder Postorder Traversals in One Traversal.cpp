//https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    stack<pair<BinaryTreeNode<int>*, int> > st;
    vector<vector<int>> ans;
    if(!root) return ans;
    vector<int> pre,post,in;
    st.push({root,1});
    
    while(st.size()){
        auto f =st.top();
        BinaryTreeNode<int> * node = f.first;
        st.pop();
        //preorder
        //pushing left side
        if(f.second == 1){
            pre.push_back(node->data);
            f.second++;        //incrementing
            st.push(f);
            if(node->left){        //in preorder after root we have to add left
                st.push({node->left,1});
            }
        }
         //inorder
        //pushing right side
        else if(f.second == 2){
            in.push_back(node->data);
            f.second++;    //incrementing
            st.push(f);
            if(node->right){         //in inorder after left root we have to add right
                st.push({node->right,1});
            }
        }
        //won't push here anything in stack
        else{
            post.push_back(node->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
    // Write your code here.
}
