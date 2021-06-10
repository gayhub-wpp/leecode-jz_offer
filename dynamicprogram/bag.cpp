#include <vector>
#include <algorithm>
using namespace std;

// 01背包
// 共N个物品和一个容量为W的背包，weights、values是每个物品的体积和价值，拿哪些物品可以使得背包装下物品的价值最大
// dp[i][j]代表前i个物品体积不超过j的最大价值
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)         dp[i-1][j]代表不取第i个     dp[i-1][j-w]+v取第i个
int knapsack(vector<int> weight, vector<int> values, int N ,int W)
{
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 1; i < N; i++)
    {
        int w = weight[i-1], v = values[i-1];
        for (int j = 1; j < W; j++)
        {
            if (j>=w)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }            
        }
    }
    return dp[N][W];   
}
// 优化空间
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
// 每行只需要上一行的数据，优化为dp[j] = max(dp[j-1], dp[j-w]+v)
// 但是dp[j-w]不能从左到右遍历，这样dp[j-w]的值再遍历到j之前就已经被更新到物品i的值了，因此需要逆序遍历
int knapsack(vector<int> weight, vector<int> values, int N ,int W)
{
    vector<int> dp(W+1, 0);
    for (int i = 1; i <= N; i++)
    {
        int w = weight[i-1], v = values[i-1];
        for (int  j = W; j >= w; --j)
        {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
        
    }
    return dp[W];
}


//无边界/完全背包
//不限制每个物品的个数
//dp[i][j] = max(dp[i-1][j], dp[i][j-w]+v)
//跟01背包问题的差别就是把状态方程的第二个i-1变成了i
int knapsack(vector<int> weight, vector<int> values, int N ,int W)
{
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 1; i < N; i++)
    {
        int w = weight[i-1], v = values[i-1];
        for (int j = 1; j < W; j++)
        {
            if (j>=w)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-w]+v);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }            
        }
    }
    return dp[N][W];   
}

//优化
//完全背包遍历每一行的时候要正向遍历，因为我们需要利用当前物品第j-w列的信息
int knapsack(vector<int> weight, vector<int> values, int N ,int W)
{
    vector<int> dp(W+1, 0);
    for (int i = 1; i <= N; i++)
    {
        int w = weight[i-1], v = values[i-1];
        for (int  j = 1; j <= w; ++j)
        {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    return dp[W];
}



int main(int argc, char const *argv[])
{
    vector<int> weights;
    vector<int> values;

    return 0;
}

