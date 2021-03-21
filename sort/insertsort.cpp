#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void sortvector(vector<int> & nums){
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j > 0 && nums[j] < nums[j-1]; --j)
        {
            cout << "j:" <<j << " nums[j]:" << nums[j] << " nums[j-1]:" << nums[j-1] << endl;
            swap(nums[j], nums[j-1]);
        }
    }
    
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