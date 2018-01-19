#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto beg=nums.begin();
        auto end=nums.end();
        auto pos=find(beg,end,target);
        if(pos != end)return pos-beg;
        else
        {
            int i=0;
            for(auto &w:nums)
            {
                if(w>target)
                    return i;
                i++;
            }
            return i;
        }
    }
};

int main()
{
    vector<int> a{1,3,4,5};
    Solution sol;
    int res=sol.searchInsert(a,6);
    cout << res <<endl;
}