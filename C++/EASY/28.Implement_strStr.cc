#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()==0 && needle.size() == 0)return 0;
        else if(haystack.size()==0 && needle.size() >0)return -1;
        int pos =haystack.find(needle);
        return pos;
    }
};

int main()
{
    string haystack;
    string needle;
    cin >> haystack;
    cin >> needle;
    Solution sol;
    int res=sol.strStr(haystack, needle);
    cout << res << endl;
}