#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}


void vertical_sum(Node* root, int horizontal_distance, map<int,int> &m)
{
    if(root==NULL)
    return;
    else
    {
        vertical_sum(root->left,horizontal_distance-1,m);
        m[horizontal_distance]+=root->data;
        vertical_sum(root->right,horizontal_distance+1,m);
    }
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	map<int,int>m;
	int horizontal_distance=0;
	vertical_sum(root,horizontal_distance,m);

	for(auto itr:m)
	{
		cout<<itr.second<<" ";
	}


}