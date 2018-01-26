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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root ==NULL)return true;
        int ldep;
        int rdep;
        bool lbal=isBalance(root->left,ldep);
        bool rbal=isBalance(root->right,rdep);
        if(lbal && rbal){
            int diff=ldep-rdep;
            if(diff>1 ||diff <-1)return false;
            else return true;
        }
        else return false;
    }
private:
    bool isBalance(TreeNode* root,int& depth){
        if(root == NULL){
            depth=0;
            return true;
        }
        int ldep;
        int rdep;
        bool lbal=isBalance(root->left,ldep);
        bool rbal=isBalance(root->right,rdep);
        depth=(ldep>=rdep?ldep:rdep)+1;
        if(lbal && rbal){
            int diff=ldep-rdep;
            if(diff>1 ||diff <-1)return false;
            else return true;
        }
        else return false;
    }
};

/**
 * 较优解
 * 
*/
class Solution {
public:
    
    int isBalancedRec(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int left = isBalancedRec(root->left);
        int right = isBalancedRec(root->right);
        if (abs(left-right) >1) return -50;
        else return 1+ max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if (isBalancedRec(root) >=0) return true;
        return false;
    }
};