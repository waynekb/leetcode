#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(size==0)return 0;
        int maxprofit = 0;
        int lowestprice = prices[0];
        
        for(int i=0 ;i <size-1; i++)
        {
            if(prices[i+1]<prices[i])
            {    
                maxprofit+=(prices[i]-lowestprice);
                lowestprice=prices[i+1];
            }
        }
        maxprofit+=(prices[size-1]-lowestprice);
        return maxprofit;
    }
};