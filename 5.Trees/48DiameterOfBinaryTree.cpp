// Recursive optimized C program to find the diameter of a
// Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct node {
    int data;
    struct node *left, *right;
};

// function to create a new node of tree and returns pointer
struct node* newNode(int data);

// returns max of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// function to Compute height of a tree.
int height(struct node* node);


//**************Main Code***************
int maxDepth(struct node* root,int& res) {
    if (root==NULL) return 0;
    int lh = maxDepth(root->left,res);
    int rh = maxDepth(root->right,res);
    int temp = 1+max(lh,rh);
    res = max(res,1+lh+rh);
    
    //  *****These steps are in Aditya Verma's channel but I found it redundant*****
    // int ans = max(1+lh+rh,temp); 
    // res = max(res,ans);   
    return temp;
}  

// Function to return the diameter of a Binary Tree.
int diameter(struct node* root) {
    int res = INT_MIN;
    maxDepth(root,res);
    return res;
}

// UTILITY FUNCTIONS TO TEST diameter() FUNCTION

// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
int height(struct node* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;

    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(node->left), height(node->right));
}

// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// Driver Code
int main()
{

    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function Call
    cout << "Diameter of the given binary tree is " <<
        diameter(root);

    return 0;
}