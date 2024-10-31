// C++ program to print inorder traversal
// using stack.
/* Constructed binary tree is
			1
		  /   \
		2	   3
		/ \   /  \
	   4   5 6    7
     /  \ /\
    8    9

	*/
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};
 

void inOrder(struct Node* root)
{
	stack<Node*> s;
	Node* curr = root;

	while (curr != NULL || s.empty() == false) {
		 
		while (curr != NULL) { 
			s.push(curr);
			curr = curr->left;
		}

		// Current must be NULL at this point
		curr = s.top();
		s.pop();

		cout << curr->data << " "; 
		curr = curr->right;

	}
}
 
int main()
{
	
	 struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
   // root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
	inOrder(root);
    cout<<endl;
	return 0;
}
