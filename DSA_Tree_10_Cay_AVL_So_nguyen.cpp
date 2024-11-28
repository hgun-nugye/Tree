#include <iostream>
using namespace std;

struct Node 
{
  int key;
  Node* left;
  Node* right;
  int height;

  Node(int value) 
	{
    key = value;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

int getHeight(Node* node) 
{
	if (!node) return 0;
	return node->height;
}

int getBalance(Node* node) 
{
  if (!node) return 0;
  return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* z) 
{
  Node* y = z->left;
  Node* T3 = y->right;
	
	y->right = z;
  z->left = T3;

  z->height = 1 + max(getHeight(z->left), getHeight(z->right));
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));

  return y;
}

Node* leftRotate(Node* z) 
{
  Node* y = z->right;
  Node* T2 = y->left;

  y->left = z;
  z->right = T2;

  z->height = 1 + max(getHeight(z->left), getHeight(z->right));
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));

  return y;
}

Node* insert(Node* root, int key) 
{
  if (!root) return new Node(key);
  if (key < root->key) root->left = insert(root->left, key);
	else root->right = insert(root->right, key);
  
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int balance = getBalance(root);

    // Balancing the tree
  if (balance > 1 && key < root->left->key) return rightRotate(root);
  if (balance < -1 && key > root->right->key) return leftRotate(root);
  if (balance > 1 && key > root->left->key) 
	{
		root->left = leftRotate(root->left);
 		return rightRotate(root);
	}
  if (balance < -1 && key < root->right->key) 
	{
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preOrder(Node* root) 
{
	if (!root) return;
  cout << root->key << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main() 
{
  Node* root = nullptr;
  int number;

  cout << "Enter numbers to insert into the AVL tree (enter -1 to stop):" << endl;
  while (true) 
	{
    cin >> number;
    if (number == -1) break; // Stop input when -1 is entered
    root = insert(root, number);
  }

  cout << "AVL tree in PreOrder traversal: ";
  preOrder(root);
  cout << endl;

  return 0;
}