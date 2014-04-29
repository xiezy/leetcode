#include<iostream>
#include<vector>
using namespace std;

    int minimumTotal(vector<vector<int> > &triangle) {
        int ret = INT_MAX;
        if (triangle.size() == 0) return 0;
        else if (triangle.size() == 1) return triangle[0][0];
        vector<int> prev(triangle.size(), 0);
        vector<int> cur(prev);
        prev[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i)
        {
            cur[0] = prev[0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size() - 1; ++j)
            {
                cur[j] = triangle[i][j] + prev[j] < prev[j-1] ? prev[j] : prev[j-1];
            }
            cur[i] = prev[i-1] + triangle[i][i];
            cur.swap(prev);
            for (int j = 0; j < prev.size(); ++j)
                cout << prev[j] << ',' ;
            cout << endl;
        }
        for (int i = 0; i < prev.size(); ++i)
        {
            if (ret > prev[i])
                ret = prev[i];
        }
        return ret;
    }
int main()
{
    vector<int> row(3,0);
    vector<vector<int> > vec(3,row);
    vec[0][0] = -1;
    vec[1][0] = 2, vec[1][1] = 3;
    vec[2][0] = 1, vec[2][1] = -1, vec[2][2] = -1;
    cout << minimumTotal(vec);
}
