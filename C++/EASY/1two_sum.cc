#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto elem1=nums.begin();
        auto elem2=nums.begin();
        int size=nums.size();
        vector<int> res;
        
        for(int i=0;i<size;i++)
        {
            elem2=elem1;
            elem2++;
            for(int j=i+1;j<size;j++)
            {
                if((*elem1+*elem2)==target)
                {
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
                elem2++;
            }
            elem1++;
        }
        return res;
    }
};



int main(void)
{
    Solution num;
    vector<int> init{1,2,3,4,5};
    vector<int> a=num.twoSum(init, 5);
    cout << a[0] <<" "<<a[1]<< endl;
    return 1;
}