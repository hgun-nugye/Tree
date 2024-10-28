#include <iostream>
using namespace std;

// khai bao cay nhi phan
struct nut {
    int ivalue;
    float fvalue;
    char cvalue;
    nut *left, *right;
};
typedef struct nut Tree;

//prototype
void InsertTreeInt(Tree *&root, Tree *newTree);
void DisplayInt(Tree *root);
Tree* SearchNode(Tree *root, int x);
int GetLevel(Tree *root, Tree *node, int level=1);
int CountLeaves(Tree *root);

int main() {
    int n, x;
    Tree *root = NULL;

    // Int Tree
    cout << "Processing in Integer Tree!\n";
    cout << "Number of nodes: ";
    cin >> n;

    // Insert nodes into the tree
    for (int j = 0; j < n; j++) 
		{
			int i;
      cin >> i;
      Tree *newTree = new Tree();
      newTree->ivalue = i;
      newTree->left = newTree->right = NULL;
      InsertTreeInt(root, newTree);
    }
    DisplayInt(root);

    // Search for the node in the Tree
    cout << "\nInsert the value of node to find: ";
    cin >> x;
    Tree *node = SearchNode(root, x);
    if (node)
		{
			cout<<"\nFound the node!";
      int level = GetLevel(root, node);
      int leafCount = CountLeaves(node);
      cout << "\nNode level is: " << level << endl;
      cout << "Number of leaves is: " << leafCount << endl;
    } 
		else cout << "\nValue not found in tree!" << endl;
  
	return 0;
}

// Function definitions
void InsertTreeInt(Tree *&root, Tree *newTree) 
{
  if (!root) root = newTree;
  else if (newTree->ivalue < root->ivalue) 
		InsertTreeInt(root->left, newTree);
  else InsertTreeInt(root->right, newTree);
}

void DisplayInt(Tree *root) 
{
  if (!root) return;
  DisplayInt(root->left);
  cout << root->ivalue << "\t";
  DisplayInt(root->right);
}

Tree *SearchNode(Tree *root, int x) 
{
  if (!root || root->ivalue == x) return root;
  if (x < root->ivalue) 
		return SearchNode(root->left, x);
  return SearchNode(root->right, x);
}

int GetLevel(Tree *root, Tree *node, int level) 
{
	if (!root) return 0;
  if(root==node) return level;
  int DownLevel=GetLevel(root->left,node,level+1);
  if (DownLevel!=0) return DownLevel;
  return GetLevel(root->right,node,level+1);
}

int CountLeaves(Tree *root) 
{
  if (!root) return 0;
  if (!root->left && !root->right) return 0;
	else if(!root->left || !root->right) return 1;
  return CountLeaves(root->left) + CountLeaves(root->right);
}
