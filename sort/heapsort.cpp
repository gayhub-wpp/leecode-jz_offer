#include <iostream>
#include <vector>
using namespace std;


void swap(int &a, int &b){
    if (a != b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

void sink(vector<int> &nums, int index, int len){
    while(1)
    {
        int i = index*2;
        if (i+1 <= len && nums[i] < nums[i+1])
        {
            i++;
        }
        if (i <= len && nums[index] < nums[i] )
        {
            swap(nums[index], nums[i]);
        }
        else{
            break;
        }
        index = i;
    }
}

void heatsort(vector<int> &nums){
    int len = nums.size();
    
    nums.insert(nums.begin(), 0);
    for (int i = len/2; i >= 1; --i)
    {
        sink(nums, i, len);
    }
    for (int i = len; i > 1; )
    {
        swap(nums[i--], nums[1]);
        sink(nums, 1, i);
    }
    nums.erase(nums.begin());
}

int main(int argc, char const *argv[])
{
    vector<int> vec{2, 3, 1, 5, 6, 9, 8, 7, 4};
    
    
    heatsort(vec);
    // so.sink(vec, )
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}