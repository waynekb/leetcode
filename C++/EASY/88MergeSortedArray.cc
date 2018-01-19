#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t=m+n;
        while(n>0)
        {
            if(m>0 && nums1[m-1]>=nums2[n-1])
            {
                nums1[t-1]=nums1[m-1];
                m--;
            }
            else
            {
                nums1[t-1]=nums2[n-1];
                n--;
            }
            t--;
        }
    }
};

/**
 * 最优解
*/

class Solution{
public:
    void merge(vector<int> &nums1,int m, vector<int> &nums2, int n){
        while(n>0){
            nums1[m+n-1]=( m==0 || nums2[n-1] >= nums1[m-1])?nums2[--n]:nums1[--m];
        }
    }
}