#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/*
 *自己写的 
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n);
        if(n==0)return ret;
        direction dir=right;
        for(int i=0;i<n;i++){
            ret[i].resize(n);
        }
        int x=0,y=0;
        ret[0][0]=1;
        for(int i=2;i<=n*n;i++)
        {
            switch(dir){
                    case right:
                        if(y+1<n && ret[x][y+1] ==0){
                            ret[x][++y]=i;
                        }
                        else
                        {
                            ret[++x][y]=i;
                            dir=down;
                        }
                    break;
                    case down:
                        if(x+1<n && ret[x+1][y] ==0){
                            ret[++x][y]=i;
                        }
                        else
                        {
                            ret[x][--y]=i;
                            dir=left;
                        }
                    break;
                    case left:
                        if(y-1>-1 && ret[x][y-1] ==0 ){
                            ret[x][--y]=i;
                        }
                        else
                        {
                            ret[--x][y]=i;
                            dir=up;
                        }
                    break;
                    case up:
                        if(x-1>-1 && ret[x-1][y] ==0 ){
                            ret[--x][y]=i;
                        }
                        else
                        {
                            ret[x][++y]=i;
                            dir=right;
                        }
                    break;
                    
            }
        }
        return ret;
    }
private:
    enum direction{left,right,up,down};
    
};


/*
* 较优解
*/


// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> res(n, vector<int>(n, 0));
//         int i = 0, k = 1;
//         while (k <= n * n) {
//             int j = i;
//             while (j < n - i)
//                 res[i][j++] = k++;
//             j = i + 1;
//             while (j < n - i) {
//                 res[j++][n - 1 - i] = k++;
//             }
//             j = n - 2 - i;
//             while (j > i) {
//                 res[n - 1 - i][j--] = k++;
//             }
//             j = n - 1 - i;
//             while (j > i) {
//                 res[j--][i] = k++;
//             }
//             ++i;
//         }
//         return res;
//     }
// };


int main(){
    int a;
    cin >> a;
    Solution sol;
    auto res=sol.generateMatrix(a);
    for(auto &w:res){
        for(auto &s:w){
            cout << s <<"\t";
        }
        cout << endl;
    }
    return 1;
}