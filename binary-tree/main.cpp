#include <vector>
#include <stack>
#include<queue>
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

struct Tree
{
    // Where maxDepth is defined as the number of nodes passed through
    // on the path from the root to the farthest leaf node.
    int maxDepth(TreeNode* root)
    {
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if (left > right)
            return left+1;
        else
            return right+1; // if they are equal it doesnt matter
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

    void BFT(TreeNode* root)
    {
        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* ptr = NULL;
        while (!q.empty())
        {
            ptr = q.front();
            q.pop();
            std::cout << ptr->val << " ";

            if (ptr->left != NULL)
            {
                q.push(ptr->left);
            }
            if (ptr->right != NULL)
            {
                q.push(ptr->right);
            }
        }
        std::cout << std::endl;
    }

    // Preorder
    void DFTIterativePreorder(TreeNode* root)
    {
        std::stack<TreeNode*> s;
        s.push(root);

        TreeNode* ptr = NULL;
        while(!s.empty())
        {
            ptr = s.top();
            s.pop();
            std::cout << ptr->val << " ";

            if (ptr->right != NULL)
            {
                s.push(ptr->right);
            }
            if (ptr->left != NULL)
            {
                s.push(ptr->left);
            }
        }
        std::cout << std::endl;
    }

    void DFTIterativeInorder(TreeNode* root)
    {
        std::stack<TreeNode*> s;
        TreeNode* ptr = root;

        // As long as one is true, there is more work to be done
        // Start: ptr is pointing to root, thus not NULL but stack is empty.
        //
        while (ptr != NULL || !s.empty())
        {
            // This part is what traverses down the left side of a tree and does
            // the depth first searching and pushing of the nodes onto stack.
            while (ptr != NULL)
            {
                s.push(ptr);
                ptr = ptr->left;
            }

            // ptr is NULL at this point.
            ptr = s.top();
            s.pop();
            std::cout << ptr->val << " ";
            ptr = ptr->right;
        }
    }

    void DFTIterativePostorder(TreeNode* root)
    {
        // longest and most complex of the three iteratives.

    }

    void DFTRecursive(TreeNode* root)
    {
        // Inorder
        if (root->left != NULL) DFTRecursive(root->left);
        std::cout << root->val << " ";
        if (root->right != NULL) DFTRecursive(root->right);
    }
};


int main()
{
    /* Test case and answer generation */
    // Level 1
    TreeNode* root = new TreeNode(4);
    // Level 2
    root->left = new TreeNode(2);
    root->right = new TreeNode(20);
    // Level 3
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(21);

    //        4
    //      /   \
    //     2    20
    //    /  \  /  \
    //   1   3 5   21

    /* Invoke the solution */
    Tree s;
    std::cout << "Max Depth: " << s.maxDepth(root) << std::endl;

    std::cout << "Is BST ? (1 is true): " << s.isBST(root) << std::endl;

    std::cout << "BFS: ";
    s.BFT(root);

    std::cout << "DFT (Recursive (Inorder)): ";
    s.DFTRecursive(root);
    std::cout << std::endl;

    std::cout << "DFT (Iterative (Preorder)): ";
    s.DFTIterativePreorder(root);

    std::cout << "DFT (Iterative (Inorder)): ";
    s.DFTIterativeInorder(root);
    std::cout << std::endl;

    std::cout << "DFT (Iterative (Postorder)): ";
    s.DFTIterativePostorder(root);
    std::cout << std::endl;



    /* Check solution */
    return 0;
}
