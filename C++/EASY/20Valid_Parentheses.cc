#include <stack>
#include <string>
#include <iostream>

using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        if(s.empty())
            return false;
        auto beg=s.begin();
        auto end=s.end();
        while(beg != end)
        {
            if(*beg == '(' || *beg == '[' || *beg == '{')
            {
                char_stack.push(*beg);
            }
            else
            {
                switch(*beg)
                {
                    case ')':
                        if(char_stack.size()==0)return false; 
                        if(char_stack.top() == '(')
                        {
                            char_stack.pop();
                        }
                        else 
                        {
                            return false;
                        }
                    break;
                    case ']':
                        if(char_stack.size()==0)return false; 
                        if(char_stack.top() == '[')
                        {
                            char_stack.pop();
                        }
                        else 
                        {
                            return false;
                        }
                    break;
                    case '}':
                        if(char_stack.size()==0)return false; 
                        if(char_stack.top() == '{')
                        {
                            char_stack.pop();
                        }
                        else 
                        {
                            return false;
                        }
                    break;                          
                }
            }
            beg++;
        }
        if(char_stack.size() == 0)return true;
        else return false;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    bool ret = sol.isValid(s);
    if(ret){
        cout << "s is valid !"<<endl;
    }
    else cout << "s is not valid ! "<<endl;
}