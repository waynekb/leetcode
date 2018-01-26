#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            vector<int> ret{1};
            return ret;
        }
        vector<int> ret{1, 1};
        if (rowIndex == 1)
        {
            return ret;
        }
        vector<int> temp;
        for (auto &w : ret)
        {
            cout << w << '\t';
        }
        cout << endl;
        for (int i = 2; i <= rowIndex; i++)
        {
            temp.push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                temp.push_back(ret[j] + ret[j + 1]);
            }
            temp.push_back(1);
            for (auto &w : temp)
            {
                cout<<w<<'\t';
            }
            cout<<endl;
            temp.swap(ret);
            temp.clear();
        }
        return ret;
    }
};

int main()
{
    int a;
    cin>>a;
    Solution sol;
    vector<int> ret=sol.getRow(a);
}