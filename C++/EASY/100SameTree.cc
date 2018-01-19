#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 构造堆
*/
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> pcont;
//         vector<TreeNode*> qcont;
//         pcont.push_back(p);
//         qcont.push_back(q);
//         int ppos=0;
//         int qpos=0;
//         while(ppos<pcont.size() && qpos<qcont.size()) 
//         {
//             if(pcont[ppos]!=nullptr && qcont[qpos]!=nullptr)
//             {
//                 if(pcont[ppos]->val != qcont[qpos]->val)return false;
//                 pcont.push_back(pcont[ppos]->left==NULL?nullptr:pcont[ppos]->left);
//                 pcont.push_back(pcont[ppos]->right==NULL?nullptr:pcont[ppos]->right);
//                 qcont.push_back(qcont[qpos]->left==NULL?nullptr:qcont[qpos]->left);
//                 qcont.push_back(qcont[qpos]->right==NULL?nullptr:qcont[qpos]->right);
//                 ppos++;
//                 qpos++;
//             }
//             else if(pcont[ppos] == nullptr && qcont[qpos] == nullptr)
//             {
//                 ppos++;
//                 qpos++;
//             }
//             else 
//             {
//                 return false;
//             }
            
//         }
//         if(ppos==pcont.size()  && qpos==qcont.size() ){
//             return true;}
//         else {
//             return false;
//             }
//     }
// };

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q)return true;
        else if((p &&!q) ||(q &&!p))return false;
        return(isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && q->val==p->val); 
    }
};


int main(){
    TreeNode *p1=new TreeNode(1);
    TreeNode *p2=new TreeNode(2);
    TreeNode *p3=new TreeNode(3);
    p1->left=p2;
    p1->right=p3;
    TreeNode *q1=new TreeNode(1);
    TreeNode *q2=new TreeNode(2);
    TreeNode *q3=new TreeNode(3);
    q1->left=q2;
    q1->right=q3;
    Solution sol;
    bool res=sol.isSameTree(p1,q1);
    if(res == true)cout << "true" <<endl;
    else cout<<"false"<<endl;
    return 1;
}