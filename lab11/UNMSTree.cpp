#include<iostream>
#include<string>
using namespace std;

struct treeNode {
  string val;
  treeNode *left;
  treeNode *right;
};

void initialize(treeNode *t, string n) {
  t->val = n;
  t->left = t->right = 0;
}

void insert(treeNode *t, string n) {
  cout << "insert t " << t->val << " n " << n << endl;
  treeNode **child;
  if (n <= t->val) child = &(t->left);
  else child = &(t->right);
  if (0 == *child) {  // create new node and store value
    *child = new treeNode;
    initialize(*child, n);
  } else { // recurse on the correct branch
    insert(*child, n);
  }
}

void remove(treeNode *t) {
  cout << "remove t " << t->val << endl;
  if (t->left) remove(t->left);  // get rid of left subtree
  if (t->right) remove(t->right); // get rid of right subtree
  delete t;
}

int main() {
  treeNode *root = new treeNode;
  initialize(root, "Zimbabwe");
  insert(root, "USA");
  insert(root, "Spain");
  insert(root, "Pakistan");
  insert(root, "Nepal");
  insert(root, "Malaysia");
  insert(root, "Korea");
  insert(root, "Bahamas");
  insert(root, "Canada");
  insert(root, "Argentina");
  remove(root);
}
