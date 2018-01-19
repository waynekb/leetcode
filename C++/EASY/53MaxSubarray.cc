class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int ret=nums[0];
        int temp=0;
        for(auto &w:nums){
            temp+=w;
            if(temp>ret)
                ret=temp;
            if(temp <0)
                temp=0;
        }
        return ret;
    }
};