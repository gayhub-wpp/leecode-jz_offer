#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b){
    a ^= b;
    b ^= a;
    a ^= b;
}

void bubble(vector<int>& nums){
    int len = nums.size();
    for (int  i = 1; i < len; i++)
    {   
        bool swapped = false;
        for (int j = 1; j < len - i + 1; j++)
        {
            if (nums[j] < nums[j-1])
            {
                swap(nums[j], nums[j-1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
                
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> vec{2, 3, 1, 5, 6, 9, 8, 7, 4};
    bubble(vec);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
