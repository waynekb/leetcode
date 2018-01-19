#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::cin;
class Solution {
public:
    int reverse(int x){
        bool is_pos=x>0;        
        x=abs(x);
        if(x>1000000000 && x%10>2)
        {
            cout <<"111"<<endl;
            return 0;
        }

        unsigned int num=0;
        while(x>0)
        {
            num=num*10+x%10;
            x=x/10;
        }
        if(is_pos>0)
        {
            if(num<2147483648)
                return(int)num;
            else{
                cout <<"222"<<endl;
                return 0;
            }
        }
        else 
        {
            if(num<2147483648)
                return (int)-num;
            else{
                cout <<"333"<<endl;
                return 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    int a;
    cin >> a;
    int b=sol.reverse(a);
    cout << b <<endl;
    cin >>a;
}