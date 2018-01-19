#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int len = strs.size();
        if(len == 0)return res;
        for(int i=0; i<strs[0].size(); i++)
        {
            for(int j=1; j<len ; j++)
            {
                if(strs[0][i] != strs[j][i])
                    return res;
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};