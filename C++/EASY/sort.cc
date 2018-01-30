#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::swap;
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
// class Solution
// {
// public:
//     void sort(vector<int> &nums)
//     {
//         cout << " 希尔排序 " << endl;
//         int size = nums.size();
//         int interval = size;
//         int mult = 2;
//         while (1)
//         { //loop times
//             interval = size / mult;
//             for (int i = 0; i < interval; i++)
//             {
//                 for (int j = i + interval; j < size; j += interval)
//                 {
//                     for (int k = j; k >= interval; k -= interval)
//                     {
//                         if (nums[k - interval] > nums[k])
//                         {
//                             int temp = nums[k];
//                             nums[k] = nums[k - interval];
//                             nums[k - interval] = temp;
//                         }
//                         else{
//                             break;
//                         }
//                     }
//                 }
//             }
//             mult *= 2;
//             if (interval == 1)
//                 return;
//         }
//     }
// };

/**
 * 希尔排序
*/

// class Solution
// {
//     public:
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


/**
 * 快速排序
 * 基准数字的位置与先从右边开始找还从左边开始找是有联系的。
 * 若基准数字在左边，则应该先从右边开始找，这样找到的最后位置肯定是
 * 数值比基准数字小。
 * 若从左边开始找，则找到的最后位置肯定是数值比基准数字大。
*/
// class Solution
// {
//   public:
//     void sort(vector<int> &nums)
//     {
            // cout << " 快速排序 " << endl;
//         quick_sort(nums,0,nums.size()-1);
//     }
//   private:
//     void quick_sort(vector<int> &nums, int cl, int cr)
//     {
//         int l = cl;
//         int r = cr;
//         int mark = l;
//         if (l < r)
//         {
//             while (l < r)
//             {
//                 while (nums[r] >= nums[mark] && l < r)
//                     r--;
//                 while (nums[l] <= nums[mark] && l < r)
//                     l++;
//                 swap(nums[l], nums[r]);
//             }
//             swap(nums[r], nums[mark]);
//             quick_sort(nums, cl, l);
//             quick_sort(nums, l + 1, cr);
//         }
//     }
// };




/**
 * 堆排序
*/
// class Solution
// {
//   public:
//     void sort(vector<int> &nums)
//     {
//         cout << " 堆排序 " << endl;
//         int n=nums.size();
//         for(int i = n/2-1; i>=0 ;i--)//n是以数组中的数字第几位计算
//         {
//             max_heapify(nums, i, n-1);
//         }
//         for(int i=n-1; i>0;i--){
//             swap(nums[0],nums[i]);
//             max_heapify(nums,0,i-1);
//         }
//     }

//   private:
//     void max_heapify(vector<int> &nums, int beg, int end)//beg和end是以数组下标计算
//     {
//         int parent=beg;
//         int child=parent*2+1;
//         while(child<=end){
//             if(child+1<=end && nums[child+1] > nums[child])
//                 child++;
//             if(nums[child] > nums[parent]){
//                 swap(nums[child],nums[parent]);
//                 parent=child;
//                 child=parent*2+1;
//             }
//             else break;
//         }
//     }
// };


/**
 * 归并排序
*/
class Solution
{
  public:
    void sort(vector<int> &nums)
    {
        cout << " 归并排序 " << endl;
        int size=nums.size();
        int i=1;
        do{
            i*=2;
            int beg=0;
            int end=i-1>size-1?size-1:i-1;
            while(beg<=size){
                merge_sort(nums,beg,end);
                beg+=i;
                end=end+i>size-1?size-1:end+i;
            }
        }while(i < size);
    }
    private:
    void merge_sort(vector<int> &nums,int beg,int end){
        for(int i=beg+1;i<=end;i++){
            for(int j=i;j>beg;j--){
                if(nums[j-1]>nums[j]){
                    swap(nums[j],nums[j-1]);
                }
                else break;
            }
        }
    }
};

int main()
{
    Solution sol;
    // vector<int> a {25, 34, -4, 0, 4, 9, 6, -1, 7, 2, 7, 25, 19, 20,-23,-11,43,29,1,0,0};
    vector<int> a {45, 34, 0, -4, 8,5,8};
    sol.sort(a);
    for (auto &w : a)
    {
        cout << w << " ";
    }
    cout << endl;
}