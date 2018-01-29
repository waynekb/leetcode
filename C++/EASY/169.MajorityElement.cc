#include <map>
#include <vector>

using std::vector;
using std::map;

/**
 * 解法一：Hash table
这种解法是使用一个hash表，键用来存放数组的元素，键对应的值存放元素出现的次数。
遍历整个数组，查找它在hash表中是否出现，如果出现将出现次数加1，如果没有出现，
将它插入hash表中，并设置它的出现次数为1。每次遍历到一个元素，判断它的出现次数
是否超过了数组长度的一半，要是超过了就返回该元素。时间复杂度是O(n)，空间复杂度是O(n)。。 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> tables;
        int size=nums.size();
        if(size==1)return nums[0];
        for(int i=0;i<size;i++){
            if(tables.count(nums[i])){
                tables[nums[i]]+=1;
                if(tables[nums[i]] >size/2)
                    return nums[i];
            }
            else{
                tables[nums[i]]=1;
            }    
        }
    }
};


/**
 * 解法二：Sorting
这种解法其实应该一开始就想到的，因为这种解法可以说是最简单的。
对数组进行排序，那么出现次数超过一半的元素必定是数组中的中间
元素，返回这个元素即可。时间复杂度是O(nlogn)，空间复杂度是O(1)。 
 * 
*/

