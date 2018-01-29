#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

/**
 * 冒泡排序
*/
// class Solution{
// public:
//     void sort(vector<int> &nums){
//         int mark=1;
//         int size=nums.size();
//         while(mark !=0 ){
//             mark=0;
//             for(int i=0;i<size-1;i++){
//                 if(nums[i]>nums[i+1]){
//                     int temp=nums[i];
//                     nums[i]=nums[i+1];
//                     nums[i+1]=temp;
//                     mark++;
//                 }
//             }
//         }
//     }
// };






/**
 * 选择排序
*/
// class Solution{
// public:
//     void sort(vector<int> &nums){
//         int size=nums.size();
//         for(int i=0;i<size-1;i++){
//             int temp=i;
//             for(int j=i+1;j<size;j++){
//                 if(nums[temp] > nums[j])
//                     temp=j;
//             }
//             int a=nums[temp];
//             nums[temp]=nums[i];
//             nums[i]=a;
//         }
//     }
// };





/**
 * 普通插入排序
*/

// class Solution{
// public:
//     void sort(vector<int> &nums){
//         cout << " 普通法插入 " <<endl;
//         int size=nums.size();
//         for(int i=1;i<size;i++){
//             for(int j=i;j>0;j--){
//                 if(nums[j-1]>nums[j]){
//                     int temp=nums[j];
//                     nums[j]=nums[j-1];
//                     nums[j-1]=temp;
//                 }
//             }
//         }
//     }
// private:
// };






/**
 * 二分法插入排序
 * 
 * 考虑边界
*/
// class Solution{
// public:
//     void sort(vector<int> &nums){
//         cout << " 二分法插入 " <<endl;
//         int size=nums.size();
//         vector<int> ret;
//         ret.push_back(nums[0]);
//         for(int i=1;i<size;i++){
//             sortinsert(ret,nums[i]);
//         }
//         nums.swap(ret);
//     }
// private:
//     void sortinsert(vector<int> &nums,int a){
//         int size=nums.size();
//         if(!(a<nums[size-1])){
//             nums.push_back(a);
//             return;
//         }
//         else if(!(a>nums[0])){
//             nums.insert(nums.begin(),a);
//             return;
//         }
//         int l=0;
//         int r=size-1;
//         int mid=0;
//         while(l<r){
//             mid=l+(r-l)/2;
//             if( nums[mid] < a){
//                 if(a< nums[mid+1]){
//                     mid=mid+1;
//                     break;
//                     }
//                 else{
//                     l=mid+1;
//                 }
//             }
//             else if(a < nums[mid]){
//                 if(nums[mid-1] < a){
//                     // mid = mid-1; 
//                     break;
//                 }
//                 else{
//                     r=mid-1;
//                 }
//             }
//             else{
//                 break;
//             }
//         }
//         auto beg=nums.begin();
//         beg+=mid;
//         nums.insert(beg,a);
//         return;
//     }
// };


/**
 * 希尔排序
*/
class Solution
{
  public:
    void sort(vector<int> &nums)
    {
        cout << " 希尔排序 " << endl;
        int size = nums.size();
        int interval = size;
        int mult = 2;
        while (1)
        { //loop times
            interval = size / mult;
            for (int i = 0; i < interval; i++)
            {
                for (int j = i + interval; j < size; j += interval)
                {
                    for (int k = j; k > 0; k -= interval)
                    {
                        if (nums[k - interval] > nums[k])
                        {
                            int temp = nums[k];
                            nums[k] = nums[k - interval];
                            nums[k - interval] = temp;
                        }
                    }
                }
            }
            mult *= 2;
            if (interval == 1)
                return;
        }
    }
};

    // class Solution
    // {
    //   public:
    //     void sort(vector<int> &nums)
    //     {
    //         for (int gap = nums.size() >> 1; gap > 0; gap >>= 1)
    //         { // times
    //             for (int i = gap; i < nums.size(); i++)
    //             { // position
    //                 int temp = nums[i];

    //                 int j = i - gap;
    //                 for (; j >= 0 && nums[j] > temp; j -= gap)
    //                 {
    //                     nums[j + gap] = nums[j];
    //                 }

    //                 nums[j + gap] = temp;
    //             }
    //         }
    //     }
    // };

    int main()
    {
        Solution sol;
        vector<int> a = {-1, 25, 34, -4, 0, 4, 9, 6, -1, 7, 2, 7, 25, 19, 20};
        sol.sort(a);
        for (auto &w : a)
        {
            cout << w << " ";
        }
        cout << endl;
    }