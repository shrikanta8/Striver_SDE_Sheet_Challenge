/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class maxNode{
    public:
    
    int minVal;     //min Value 
    int maxVal;     //Max Value
    int maxSum;     //Max Sum
    
    maxNode(int minVal,int maxVal, int maxSum){
         this->minVal= minVal;
         this->maxVal= maxVal;
         this->maxSum= maxSum;
    }
};
class Solution {
    int ans=0;
    
    maxNode maxNodeFunction(TreeNode* root ){
        if(!root)
            return maxNode(INT_MAX,INT_MIN,0);
        //if NULL then Max value is -INFINITY, this is max value from left subtree ans less than root value 
        //min value from Right subtree is INFINITY that will always be greater than root->value 
        
        auto left = maxNodeFunction(root->left );
        auto right = maxNodeFunction(root->right );
        
        
        if(left.maxVal < root->val &&  root->val < right.minVal){
            //max value from left sub tree should be less than root value AND min value from right sub tree should be greater than root value
            
            ans= max(ans,left.maxSum+right.maxSum+root->val);
            
            return maxNode(min(left.minVal,root->val), max(right.maxVal, root->val), left.maxSum+right.maxSum+root->val );
            //min value from left can be INFINITY when it is NULL node and same for right node
        }
        
        //if any of the left or right sub tree is not BST then top of that node can't be BST!!!!
        //because we have to take subtree (only top nodes and right nodes excluding left nodes can't form a  subtree(BST))       
        //above comments are from my own logic
        
        return maxNode( INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
        
    }
    public:
    int maxSumBST(TreeNode* root) {
        
        maxNodeFunction(root).maxSum;
        return ans;
    }
};
