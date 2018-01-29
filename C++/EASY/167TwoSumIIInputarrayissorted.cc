#include <vector>

using std::vector;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int size=numbers.size();
        if(size==0)return ret;
        for(int i=1;i<size;i++){
            for(int j=i+1;j<=size;j++){
                int need=target-numbers[i-1];
                if(need==numbers[j-1]){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
                else if(need <numbers[j-1])
                    break;
            }
        }
        return ret;
    }
};



/**
 * 最优解
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi = numbers.size()-1;
        while(true) {
            if(numbers[lo] + numbers[hi] > target)
                hi -= 1;
            if(numbers[lo] + numbers[hi] < target)
                lo += 1;
            if(numbers[lo] + numbers[hi] == target)
                break;
        }
        vector<int> res;
        res.push_back(lo+1);
        res.push_back(hi+1);
        return res;
    }
};