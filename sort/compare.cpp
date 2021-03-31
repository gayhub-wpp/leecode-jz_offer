#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
void Merge(vector<int>& nums,int low,int mid,int high);
void MergeSort(vector<int>& nums,int low,int high);

vector<int> tmp;
vector<int> sortArray(vector<int>& nums) {
    //归并排序——非递归
    tmp.resize(nums.size(),0);
    MergeSort(nums,0,int(nums.size())-1);
    return nums;
}
void MergeSort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
            return;
        int mid=(low+high)/2;
        MergeSort(nums,low,mid);
        MergeSort(nums,mid+1,high);
        Merge(nums,low,mid,high);
    }
// void MergeSort(vector<int>& nums,int low,int high)
// {
//     if(low>=high)
//         return;
//     for(int len=1;len<=nums.size();len*=2)
//     {
//         low=0;
//         while(low<nums.size()-len)
//         {
//             int mid=low+len-1;
//             high=mid+len;
//             if(high>=nums.size())
//                 high=nums.size()-1;
//             Merge(nums,low,mid,high);
//             low=high+1;
//         }
//     }
// }
void Merge(vector<int>& nums,int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)
    {
        if(nums[i]<=nums[j])
            tmp[k++]=nums[i++];
        else
            tmp[k++]=nums[j++];
    }
    while(i<=mid)
        tmp[k++]=nums[i++];
    while(j<=high)
        tmp[k++]=nums[j++];
    for(int t=low;t<=high;t++)
        nums[t]=tmp[t];
}

int main(int argc, char const *argv[])
{
    vector<int> vec{2, 3, 1, 5, 6, 9, 8, 7, 4};
    sortArray(vec);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
