#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start

void printcom(vector<int> combine)
{
    for(auto i : combine)
    {
        cout << i << " ";
    }
    cout << endl;
}

// void dfs1(vector<int>& candidates, int target, vector<int> &combine, vector<vector<int>> &ans, int depth)
// {
//     if (depth == candidates.size())
//     {
//         cout << "yuejie" << endl;
//         return;
//     }
    
//     if (target == 0)
//     {
//         cout << "got it " << endl;
//         printcom(combine);
//         ans.emplace_back(combine);
//         return;
//     }
//     dfs(candidates, target, combine, ans, depth+1);
//     if (target-candidates[depth] >= 0)
//     {
//         combine.emplace_back(candidates[depth]);
//         cout << "digui qian" << endl;
//         printcom(combine);
//         dfs(candidates, target-candidates[depth], combine, ans, depth);
//         combine.pop_back();
//         cout << "digui hou" << endl;
        
//         printcom(combine);
//     }
    
    
// }

void dfs2(vector<int>& candidates,int begin, int target, vector<int> &combine, vector<vector<int>> &ans)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        ans.emplace_back(combine);
        return;
    }
    for (int  i = begin; i < candidates.size(); i++)
    {
        combine.emplace_back(candidates[i]);
        dfs2(candidates, i, target-candidates[i], combine, ans);
        combine.pop_back();
    }
    


    
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combine;
    sort(candidates.begin(), candidates.end());
    // dfs1(candidates, target, combine, ans, 0);
    dfs2(candidates,0, target, combine, ans);

    return ans;
}




int main(int argc, char const *argv[])
{
    vector<int> vec{2,3,6,7};
    vector<vector<int>> ans;
    ans = combinationSum(vec, 7);
    for (int i = 0; i < ans.size(); i++)
    {
        printcom(ans[i]);
    }
    
    return 0;
}
