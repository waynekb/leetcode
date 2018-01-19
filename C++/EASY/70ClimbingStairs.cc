#include <iostream>
using namespace std;


/**
 * 每次都要迭代 计算消耗太大
*/
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==1)return 1;
//         else if(n==2)return 2;
//         int ret=climbStairs(n-1)+climbStairs(n-2);
//         return ret;
//     }
// };


class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        else if(n==2)return 2;
        // int ret=climbStairs(n-1)+climbStairs(n-2);
        int ret=0;
        int temp[2]={1,2};
        for(int i=3;i<=n;i++){
            ret=temp[0]+temp[1];
            temp[0]=temp[1];
            temp[1]=ret;
        }
        return ret;
    }
};


int main(){
    int n;
    cin >> n;
    Solution sol;
    for(int i=1;i<=n;i++){
        int res=sol.climbStairs(i);
        cout <<i<<"\t"<< res<<endl;

    }
    return 1;
}