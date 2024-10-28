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
int CountNoEven(Tree *root);

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
    
  //Coun all node is even number  
    cout<<"\nThe number of even number is: "<<CountNoEven(root);
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

int CountNoEven(Tree *root)
{
	int count=0;
	if(!root) return count;
	if(root->ivalue%2==0 && root->ivalue!=0 ) count ++;
	//check left subtree
	CountNoEven(root->left);
	
	//check right subtree
	CountNoEven(root->right);
	count+=CountNoEven(root->left);;
	count+=CountNoEven(root->right);
	return count;	
}