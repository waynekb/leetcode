#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;


class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int asize=a.size();
        int bsize=b.size();
        int maxlen=asize>bsize?asize:bsize;
        int ford=0;
        for(int i=1;i<=maxlen;i++)
        {
            ford+=((i<=asize)?a[asize-i]-'0':0);
            ford+=((i<=bsize)?b[bsize-i]-'0':0);
            int temp=ford%2;
            ford=ford/2;
            // ret.insert(ret.begin(),temp+'0'); //数组首部插入字符
            ret=static_cast<char>(temp+'0')+ret; //利用string的 + 运算符
        }
        if(ford==1)ret=static_cast<char>(ford+'0')+ret;
        return ret;
    }
};

int main()
{
    Solution sol;
    string a;
    string b;
    string res;
    cin>>a;
    cin>>b;
    res=sol.addBinary(a,b);
    cout<<res<<endl;
}