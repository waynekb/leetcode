#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL)
        return false;
    else if (root->left == NULL && root->right == NULL && root->val == sum)
        return true;
    else {
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum - root->val);
    }
}