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

//Float Tree
void InsertTreeFloat(Tree *&root, Tree *newTree);
void DisplayFloat(Tree *root);

//Char Tree
void InsertTreeChar(Tree *&root, Tree *newTree);
void DisplayChar(Tree *root);

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
    cout<<"\n"<<CountRoot1(root);
    
    //Float Tree
		root = NULL;
		cout<<"\n\nProcessing in Float Tree!\n";
    float f;
    cout<<"Number of element: ";
    cin>>n;
    for(int j=0; j<n; j++)
    {
    cin >> f;
    Tree *newTree = new Tree();
    newTree->fvalue = f;
    newTree->left = newTree->right = NULL;
    InsertTreeFloat(root, newTree);
		}
    DisplayFloat(root);
    
    //Char Tree
    root = NULL;
    cout<<"\n\nProcessing in Char Tree!\n";
    char c;
    cout<<"Number of element: ";
    cin>>n;
    for(int j=0; j<n; j++)
    {
    cin >> c;
    Tree *newTree = new Tree();
    newTree->cvalue = c;
    newTree->left = newTree->right = NULL;
    InsertTreeChar(root, newTree);
		}
    DisplayChar(root);

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

//Float Tree
void InsertTreeFloat(Tree *&root, Tree *newTree) 
{
	if (!root) root = newTree;
  else if (newTree->fvalue < root->fvalue) 
		return InsertTreeFloat(root->left, newTree);
  else return InsertTreeFloat(root->right, newTree);
}

void DisplayFloat(Tree *root) 
{
  if (!root) return;
  DisplayFloat(root->left);
  cout << root->fvalue << "\t";
  DisplayFloat(root->right); 
}

//Char Tree
void InsertTreeChar(Tree *&root, Tree *newTree) 
{
	if (!root) root = newTree;
  else if (newTree->cvalue < root->cvalue) 
		return InsertTreeChar(root->left, newTree);
  else return InsertTreeChar(root->right, newTree);
}

void DisplayChar(Tree *root) 
{
  if (!root) return;
  DisplayChar(root->left);
  cout << root->cvalue << "\t";
  DisplayChar(root->right); 
}

//coun the node has just 1 brach
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

