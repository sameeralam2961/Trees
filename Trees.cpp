#include <bits/stdc++.h>

using namespace std;

struct Tree {
	int data;
	Tree *left, *right;
	
	Tree(int x){
		data = x;
		left = right = NULL;
	}
	
	Tree* insertNode(int x, Tree *root){
		if(root == NULL){
			return new Tree(x);
		}
		if(x < root -> data){
			root -> left = insertNode(x, root -> left);
		}
		else{
			root -> right = insertNode(x, root -> right);
		}
		return root;
	}
	
	void inorder(Tree* root){
		if(!root){
			return;
		}
		inorder(root -> left);
		cout << root -> data << " ";
		inorder(root -> right);
	}
	
	Tree* heightBalanced(int a[], int low, int high, Tree *root){
		if(low > high){
			return NULL;
		}
		int mid = (low + high) / 2;
		root = new Tree(a[mid]);
		root -> left = heightBalanced(a, low, mid-1, root -> left);
		root -> right = heightBalanced(a, mid+1, high, root -> right);
		return root;
	}
	
};

Tree *root = NULL;

void solve(void){
	int a[] = {1, 2, 3, 4, 5};
	root = root -> insertNode(10, root);
	root -> insertNode(11, root);
	root -> insertNode(6, root);
	root -> insertNode(4, root);
	root = root -> heightBalanced(a, 0, sizeof(a) / 4 - 1, root);
}

signed main() {
int t = 1;
	while(t--)
    solve();

    return 0;
}
