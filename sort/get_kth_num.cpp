#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

int partition(vector<int> &nums, int l, int r){
    int pivot = nums[l];
    while (l<r)
    {
        while (l < r && nums[r] >= pivot)
        {
            r--;
        }
        nums[l] = nums[r];
        while (l<r && nums[l] <= pivot)
        {
            l++;
        }
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}

int find_kth_num()