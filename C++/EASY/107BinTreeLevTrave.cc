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


// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         int level=0;
//         int dep=0;
//         dep = recrod(root,level);
//         vector<vector<int>> ret(dep);
//         for(int i=0; i<dep ; i++){
//             vector<int> abs;
//             auto range=temp.equal_range(dep-i);
//             // auto range=temp.equal_range("++level");
//             for(auto pos=range.first;pos!=range.second;pos++){
//                 abs.push_back(pos->second);
//             }
//             ret[i]=abs;
//         }
//         return ret;
//     }
// private:
//     multimap<int,int> temp;
//     int recrod(TreeNode* root,int level){
//         temp.insert(make_pair(++level,root->val));
//         // temp.insert(make_pair("++level",root->val));
//         int ldep=0;
//         int rdep=0;
//         if(root->left!= NULL){   
//             ldep=recrod(root->left,level);
//         } 
//         if(root->right != NULL){   
//             rdep=recrod(root->right,level);
//         }
//         return (ldep>=rdep?ldep:rdep)+1;
//     }
// };


/**
 * 较优解
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> list={};
        dfs(list,root,1);     
        // reverse(list.begin(),list.end());
        return list;
    }
    
    void dfs(vector<vector<int>> &list, TreeNode * root, int depth){
        if(root==NULL)
            return;
        if(list.size()<depth)
            list.resize(depth);      
        list[depth-1].push_back(root->val);
        
        dfs(list,root->left,depth+1);
        dfs(list,root->right,depth+1);
    }
};




int main(){
    TreeNode *p1=new TreeNode(3);
    TreeNode *p2=new TreeNode(9);
    TreeNode *p3=new TreeNode(20);
    p1->left=p2;
    p1->right=p3;
    TreeNode *q1=new TreeNode(15);
    TreeNode *q2=new TreeNode(7);
    p3->left=q1;
    p3->right=q2;
    Solution sol;
    vector<vector<int>> res=sol.levelOrderBottom(p1);
    for(int i=0; i<res.size();i++){
        for(auto &w:res[i])
        cout<<w<<'\t';
        cout<<endl;
    }
    return 1;
}

// int main(){
//     multimap<string,int> temp;
//     temp.insert(make_pair("wayne",50));
//     temp.insert(make_pair("wayne",40));
//     temp.insert(make_pair("wayne",30));
//     auto beg=temp.equal_range("wayne").first;
//     auto end=temp.equal_range("wayne").second;
//     while(beg!=end){
//         cout<<beg->first<<"\t"<<beg->second<<endl;
//         beg++;
//     }
//     return 1;
// }


// using namespace std;
  
// int main()
// {
//     multimap<string,int> m_map;
//     string s("中国"),s1("美国");
//     m_map.insert(make_pair(s,50));
//     m_map.insert(make_pair(s,55));
//     m_map.insert(make_pair(s,60));
//     m_map.insert(make_pair(s1,30));
//     m_map.insert(make_pair(s1,20));
//     m_map.insert(make_pair(s1,10));
    // //方式1
    // int k;
    // multimap<string,int>::iterator m;
    // m = m_map.find(s);
    // for(k = 0;k != m_map.count(s);k++,m++)
    //     cout<<m->first<<"--"<<m->second<<endl;
    // //方式2
    // multimap<string,int>::iterator beg,end;
    // beg = m_map.lower_bound(s1);
    // end = m_map.upper_bound(s1);
    // for(m = beg;m != end;m++)
    //     cout<<m->first<<"--"<<m->second<<endl;
    // //方式3
    // beg = m_map.equal_range(s).first;
    // end = m_map.equal_range(s).second;
    // for(m = beg;m != end;m++)
    //     cout<<m->first<<"--"<<m->second<<endl;
//     return 0;
// }