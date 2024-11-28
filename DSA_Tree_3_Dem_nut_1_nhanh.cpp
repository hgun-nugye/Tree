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
void DisplayInt(Tree *root) ;
int CountRoot1(Tree *root);

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
    InsertTreeInt(root, newTree);
		}
    DisplayInt(root);
    
    cout<<"\nThe number just have 1 leave: "<<CountRoot1(root);
    
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

int CountRoot1(Tree *root)
{
	int dem=0;
	if(!root) return dem;
	if(root->left !=NULL && root->right==NULL)
	{
		dem++;
		CountRoot1(root->left);
	}
	if(root->left ==NULL && root->right!=NULL)
	{
		dem++;
		CountRoot1(root->right);
	}
	dem += CountRoot1(root->left);
  dem += CountRoot1(root->right);
	return dem;
	
}