#include <iostream>


using std::cout;
using std::cin;
using std::endl;


class Solution {
public:
        int mySqrt(int x) {
        if (x <= 0) return 0;
        int left = 0, right = x, mid = left + (right - left) / 2;
        while (left <= right) {
            if (mid == x / mid) return mid;
            else {
                if (mid > x / mid) right = mid;
                else left = mid ;
                mid = left + (right - left) / 2;
            }
        }
        return right;
    }
    
};


int main()
{
    int res;
    int x;
    cin >>x;
    Solution sol;
    res=sol.mySqrt(x);
    cout << res<<endl;
    return 1;
}