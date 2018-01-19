class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(size==0)
        {
            digits[0]+=1;
            return digits;
        }
        for(int i=size-1;i>-1;i--)
        {
            if(digits[i]<9)
            {
                digits[i]+=1;
                return digits;
            }
            else
            {
                digits[i]=0;
            }
        }
        auto beg=digits.begin();
        digits.insert(beg,1);
        return digits;
    }
};