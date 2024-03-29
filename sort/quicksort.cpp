#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}


//挖坑填数的分区方法
//基本思想是我们首先以序列的第一个元素为基准数，然后将该位置挖坑，
//下面判断 nums[hight] 是否大于基准数，如果大于则左移 hight 指针，直至找到一个小于基准数的元素，将其填入之前的坑中，
//则 high 位置会出现一个新的坑，此时移动 low 指针，找到大于基准数的元素，填入新的坑中。不断迭代直至完成分区。
int Partition1(vector<int> &nums, int l, int r)
{
    int pivot = nums[l];
    while (l < r)
    {
        while (l < r && nums[r] >= pivot)
        {
            r--;
        }
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot)
        {
            l++;
        }
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}

//对上面方法的挖坑填坑步骤进行合并，low 指针找到大于 pivot 的元素，hight 指针找到小于 pivot 的元素，
//然后两个元素交换位置，最后再将基准数归位。
int Partition2(vector<int> &nums, int l, int r)
{
    int start = l;       //交换时往后移，记录
    int pivot = nums[l]; //枢轴位置
    while (l < r)
    {
        while (l < r && nums[r] >= pivot)
        {
            r--;
        }
        while (l < r && nums[l] <= pivot)
        {
            ++l;
        }
        if (l >= r)
        {
            break;
        }
        swap(nums[l], nums[r]);
    }
    swap(nums[start], nums[l]);
    return l;
}

//递归
void quicksort1(vector<int> &nums, int l, int r)
{
    if (l < r)
    {
        int tmp = Partition1(nums, l, r);
//        int tmp = Partition2(nums, l, r);
//        int tmp = Partition3(nums, l, r);

        quicksort1(nums, l, tmp - 1);
        quicksort1(nums, tmp + 1, r);
    }
}

//非递归迭代()
void quicksort2(vector<int> &nums){
    stack<int> s;
    s.push(nums.size()-1);
    s.push(0);

    while (!s.empty())
    {
        int low = s.top();
        s.pop();
        int high = s.top();
        s.pop();
        if (low < high)
        {
            int index = Partition2(nums, low, high);
            s.push(index-1);
            s.push(low);
            s.push(high);
            s.push(index+1);
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> vec{2, 3, 6, 123, 723, 51, 1, 45};
    // quicksort1(vec, 0, vec.size() - 1);
    quicksort2(vec);

    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}