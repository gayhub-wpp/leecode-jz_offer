#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void selectsort(vector<int> & nums){
    int len = nums.size();
    for (int i = 0; i < len-1; i++)
    {
        int temp = i;
        for (int j = i+1; j < len; j++)
        {
            if (nums[j] < nums[temp])
            {
                temp = j;
            }
        }
        swap(nums[temp], nums[i]);        
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vec{2, 3, 1, 5, 6, 9, 8, 7, 4};
    selectsort(vec);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

