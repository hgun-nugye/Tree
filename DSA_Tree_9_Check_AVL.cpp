#include <iostream>
using namespace std;

// khai bao cay nhi phan
struct nut 
{
  int ivalue;
  float fvalue;
  char cvalue;
  nut *left, *right;
};
typedef struct nut Tree;

//Int Tree
void InsertTreeInt(Tree *&root, Tree *newTree);
void DisplayInt(Tree *root);
int Height(Tree *root);
bool CheckAVL(Tree *root);

int main() 
{
int n;
Tree *root = NULL;
    
  //Int Tree
    cout<<"Processing in Integer Tree!\n";
    int i;
    cout<<"Number of element: ";
    cin>>n;
    for(int j=0; j<n; j++)
    {
    cin >> i;
    Tree *newTree = new Tree();
    newTree->ivalue = i;
    newTree->left = newTree->right = NULL;
    InsertTreeInt(root, newTree);}
    DisplayInt(root);
    
  Tree *node=root;
  //Check AVL Tree
    if (CheckAVL(root)) cout<<"\nThis is a AVL Tree"<<endl;
    else cout<<"\nThis is not a AVL Tree"<<endl;
  return 0;
}

//function
void InsertTreeInt(Tree *&root, Tree *newTree) 
{
  if (!root) root = newTree;
  else if (newTree->ivalue < root->ivalue) 
	return InsertTreeInt(root->left, newTree);
  else return InsertTreeInt(root->right, newTree);
}

void DisplayInt(Tree *root) 
{
  if (!root) return;
  DisplayInt(root->left);
  cout << root->ivalue << "\t";
  DisplayInt(root->right); 
}

int Height(Tree *root)
{
  if (!root) return 0;
  int leftHeight = Height(root->left);
  int rightHeight = Height(root->right);
  return max(leftHeight, rightHeight) + 1;
}

bool CheckAVL(Tree *root) 
{
  if (!root) return true;
  int leftHeight = Height(root->left);
  int rightHeight = Height(root->right);
  if (abs(leftHeight - rightHeight) <= 1 
		&& CheckAVL(root->left) 
		&& CheckAVL(root->right)) 
  	  return true;
  return false;
}
