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
Tree *SearchNode(Tree *root, int x);
Tree *Rebuild(Tree *&root, int x) ;

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

    // Search for the node and Delete this node in the Tree
    cout << "\nInsert the value of node to delete: ";
    cin >> x;
    Tree *node = SearchNode(root, x);
    if (node)
		{
			cout<<"\nFound the node!\n";
			Rebuild(root, x);
			DisplayInt(root);
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

Tree *Rebuild(Tree *&root, int x) 
{
  if (!root) return root;
		
	//check left subtree
    if (x < root->ivalue) root->left = Rebuild(root->left, x);
		
	//check right subtree
		else if (x > root->ivalue) root->right = Rebuild(root->right, x);
		
	//node is found is root
		else 
		{
      //left root is NULL
				if (!root->left) 
			{
      	Tree *temp = root->right;
          delete root;
          return temp;
      } 
      //right root is NULL
				else if (!root->right) 
			{
        Tree *temp = root->left;
        delete root;
        return temp;
    	}

      //check the Tree has left subtree and right subtree
				Tree *minNode = root->right;
        while (minNode && minNode->left) 
				{
          minNode = minNode->left; //find the min node in right subtree
        }
        root->ivalue = minNode->ivalue; //copy that min value
        root->right = Rebuild(root->right, minNode->ivalue); //rebuild the right subtree.
    }
  return root;
}
