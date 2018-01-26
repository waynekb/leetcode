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


/*
*较优解
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL) return minDepth(root->right)+1;
        if(root->right==NULL) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;
        int mldep=minDepth(root->left);
        int mrdep=minDepth(root->right);
        if(!mldep && mrdep)return mrdep+1;
        if(mldep && !mrdep)return mldep+1;
        return (mldep<mrdep?mldep:mrdep)+1;
    }
};