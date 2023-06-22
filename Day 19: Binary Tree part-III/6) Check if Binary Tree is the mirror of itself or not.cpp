void mirror(Node* root) {
      if(root==NULL)
          return;

          mirror(root->left);
          mirror(root->right);

          //swapping from the last leaves
          swap(root->left, root->right);

      // code here
  }
