#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
// using std::erase;
// using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp;
        auto beg=nums.begin();
        auto end=nums.end();
        temp = *beg;
        beg++;
        while(beg != nums.end())
        {
            if(*beg == temp)
            {
                beg=nums.erase(beg);
            }  

            else
                temp=*beg++;
            
        }
        return nums.size();
    }
};

int main()
{
    vector<int> a={1,1,4};
    Solution sol;
    int res=sol.removeDuplicates(a);
    for(auto &w:a)
    {
        cout << w <<",";
    }
    cout << "\n"<< res<<endl;
}