#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>

/* Problem description */

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

struct Solution
{
    // Where maxDepth is defined as the number of nodes passed through
    // on the path from the root to the farthest leaf node.
    int maxDepth(TreeNode* root)
    {
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if (left > right) return left+1;
        else return right+1; // if they are equal it doesnt matter
        // iteratively? needs queue
    }

    // Min and max method
    bool isBST(TreeNode* root)
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    bool isBSTUtil(TreeNode* root, int min, int max)
    {
        if (root == NULL) return true; // empty trees satisfy BST

        // not a BST if the node's value violates either min/max.
        // This works regardless of which side of a subtree you are
        // testing which makes it nice. See online.
        if (root->val < min || root->val > max) return false;

        // Recursively call with updated min/max according to each
        // side.
        return
        isBSTUtil(root->left, min, root->val-1)
        && isBSTUtil(root->right, root->val+1, max);
    }

    void levelOrderTraversal(TreeNode* root)
    {

    }



};


int main()
{
    /* Test case and answer generation */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(21);

    /* Invoke the solution */
    Solution s;
    std::cout << s.maxDepth(root) << std::endl;
    std::cout << "Is BST ? (1 is true): " << s.isBST(root) << std::endl;


    /* Check solution */



    return 0;
}
