#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;



class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0)return 0;
        auto pos1=s.find_last_not_of(" ");
        if(pos1==-1)return 0;
        auto pos= s.rfind(" ",pos1);
        // int ret= pos-s.begin();
        return pos1-pos;
    }
};

int main()
{
    int res;
    // string str{"hello wrold"};
    string str;
    getline(cin,str);
    Solution sol;
    res=sol.lengthOfLastWord(str);
    cout<<res<<endl;
}