#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")return true;
        string::iterator beg=s.begin();
        string::iterator end=s.end();
        while(beg!=end){
            if((*beg) == ' ')
            beg++;
            else break;
        }
        if (beg==end)return true;

        beg=s.begin();
        end=s.end();
        end--;
        while(beg <= end){
            while((*beg) <'A' || ((*beg) >'Z' && (*beg)<'a') || (*beg)>'z')
                beg++;

            while((*end)<'A' || ((*end) >'Z'&&(*end)<'a') || (*end)>'z')
                end--;
            if(!twocharequal((*beg),(*end)))return false;
            beg++;
            end--;
        }
        return true;
    }
private:
    bool twocharequal(char a , char b)
    {
        if('Z' >= a && a >= 'A'){
           a=a-'A'+'a';
        }
        if('Z' >= b && b >= 'A'){
           b=b-'A'+'a';
        }
        if(a==b)return true;
        else return false;
    }
};

int main(){
    string a=" ";
    // cin >> a;
    Solution sol;
    if(sol.isPalindrome(a))
        cout << "string "<< a<< " is palindrome" <<endl;
    else 
        cout << "string "<< a<< " is not palindrome" <<endl;
    return 0;
}