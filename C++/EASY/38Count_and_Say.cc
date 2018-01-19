#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


// class Solution {
// public:
//     string countAndSay(int n) {
//         string temp;
//         string ret{"1"};
//         if(n==1)return ret;
//         for(int i=0; i<n-1;i++)
//         {
//             int size=ret.size();
//             char at= ret[0];
//             int num=0;
//             for(int j=0 ;j <size;j++)
//             {
//                 if(ret[j]!=at)
//                 {
//                     char cnum=static_cast<char>(num+'0');
//                     // char cnum=num+48;
//                     temp.push_back(cnum);
//                     temp.push_back(at);
//                     at=ret[j];
//                     num=0;
//                 }
//                 num++;
//             }
//             char cnum=static_cast<char>(num+'0');
//             // char cnum=num+48;
//             temp.push_back(cnum);
//             temp.push_back(at);
//             cout << temp <<endl;
//             ret.swap(temp);
//             temp.clear();
//         }
//         return ret;
//     }
// };


class Solution{
public:
    string countAndSay(int n){
        if(n==1) return "1";
        string ret;
        string temp=countAndSay(n-1);
        int size=temp.size();
        int num=0;
        char at=temp[0];
        for(int i=0; i<size; i++){
            if(temp[i] != at){
                char cnum=static_cast<char>(num + '0');
                ret.push_back(cnum);
                ret.push_back(at);
                num=0;
                at=temp[i];
            }
            num++;
        }
        char cnum = static_cast<char>(num + '0');
        ret.push_back(cnum);
        ret.push_back(at);
        return ret;
    }
};

int main()
{
    int num;
    cin >> num;
    Solution sol;
    string res=sol.countAndSay(num);
    cout << res<< endl;
    return 1;
}