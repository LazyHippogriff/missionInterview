#include <iostream>

struct tree {
  int data;
  tree* left;
  tree* right;

  tree(int fa_data):data(fa_data) {
    left = nullptr;
    right = nullptr;
  }
};

void inorder(tree* root) {

  if(root == nullptr) {
    return;
  }

  //Traverse left subtree.
  if(root->left) {
    inorder(root->left);
  }

  //Traverse root.
  std::cout<<"\n"<<root->data;

  //Traverse right subtree.
  if(root->right) {
    inorder(root->right);
  }
}

int main() {
  tree* root = new tree(10);

  root->left = new tree(20);
  root->right = new tree(30);

/*
  root->left->left = new tree(10);
  root->left->right = new tree(20);
*/

  root->right->left = new tree(40);
  root->right->right = new tree(50);

/*
  root->left->left->left = new tree(99);

  root->left->right->right = new tree(111);

  root->right->left->right = new tree(49);

  root->right->right->left = new tree(82);
*/

  std::cout<<"\n";

  inorder(root);

  std::cout<<"\n";
}
