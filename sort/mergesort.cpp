#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
void merge(vector<int> &nums, int left, int mid, int right, vector<int> &tmp);

//递归
void mergesort(vector<int> &nums, int left, int right, vector<int> &tmp)
{   
    if(left>=right){
        return;
    }
    int mid = left + ((right-left)/2);
    mergesort(nums, left, mid, tmp);
    mergesort(nums, mid+1, right, tmp);
    merge(nums, left, mid, right, tmp);
}

//非递归
// void mergesort1(vector<int> nums, int left, int right, vector<int> & tmp){
//     if (left < right)
//     {
//         return;
//     }
//     for (int i = 1; i < nums.size(); i*=2)
//     {
//         left = 0;
//         while (left<nums.size()-i)
//         {
//             int mid = left + i -1;
//             right = mid + i;
//             if (/* condition */)
//             {
//                 /* code */
//             }
//         }
//     }
// }


void merge(vector<int> &nums, int left, int mid, int right, vector<int> &tmp){
    // vector<int> tmp{right,0};
    // vector<int> tmp;
    int tmp1 = left, tmp2 = mid+1;
    int index = left;
    while (tmp1 <= mid && tmp2 <=right)
    {
        tmp[index++] = nums[tmp1] <= nums[tmp2] ? nums[tmp1++] : nums[tmp2++];
    }
    while (tmp1 <= mid)
    {
        tmp[index++] = nums[tmp1++];
    }
    while (tmp2 <= right)
    {
        tmp[index++] = nums[tmp2++];
    }
    for (int t = left; t <= right; ++t)
    {
        nums[t] = tmp[t];
    }
}

vector<int> sortvector(vector<int> & nums){
    vector<int> tmp(nums.size(),0);
    mergesort(nums, 0, int(nums.size())-1, tmp);
    return nums;
}


int main(int argc, char const *argv[])
{
    vector<int> vec{2, 3, 1, 5, 6, 9, 8, 7, 4};
    sortvector(vec);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}