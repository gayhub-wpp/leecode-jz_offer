#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        if (matrix.empty())
        {
            return ret;
        }
        int lx = 0, ly = 0;
        int rx = matrix[0].size()-1,ry = matrix.size()-1;
        while (lx<=rx && ly<=ry)
        {
            for (int i = lx; i <= rx; i++)
            {
                ret.push_back(matrix[ly][i]);
            }
            for (int i = ly+1; i <= ry; i++)
            {
                ret.push_back(matrix[i][rx]);
            }
            if(lx < rx && ly < ry){
                for (int i = rx-1; i > lx; i--)
                {
                    ret.push_back(matrix[ry][i]);
                }
                for (int i = ry; i > ly; i--)
                {
                    ret.push_back(matrix[i][lx]);
                }
            }
            lx++,ly++,rx--,ry--;

        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v1 = {1};
    vector<int> v2 = {5};
    vector<int> v3 = {9};
    // vector<int> v4 = {13,14,15,16};
    vector<vector<int>> mat = {v1,v2,v3};
    for (int  i = 0; i < mat.size(); i++)
    {
        for (int  j = 0; j < v1.size(); j++)
        {
            cout << mat[i][j] << " " ;
        }
    }
    cout << endl;
    Solution solu;
    vector<int> ret;
    ret = solu.printMatrix(mat);
    for (int  i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " " ;
    }
    cout << endl;
    return 0;
}
