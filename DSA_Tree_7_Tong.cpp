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
//Float Tree
void InsertTreeFloat(Tree *&root, Tree *newTree);
void DisplayFloat(Tree *root);
float Sum(Tree *root, int x);

int main()
{
	int n;
  Tree *root = NULL;
  cout<<"Processing in Float Tree!\n";
  float f;
  //Insert nodes into the tree
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
    
  float x;
  cout<<"\n\nEnter the value (limit to count sum): ";
  cin>>x;
  //Count Sum fir all the value is little than x
  	cout<<"The sum need to count = "<<Sum(root,x)<<endl;
  return 0;
}

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
float Sum(Tree *root, int x)
{
	float s=0;
	if(!root) return s;
	if(x>root->fvalue) s+=root->fvalue;
	if(x<root->fvalue)
	{
		Sum(root->left, x);
	}
	else Sum(root->right,x);
	s+=Sum(root->left, x);
	s+=Sum(root->right, x);
	return s;	
}