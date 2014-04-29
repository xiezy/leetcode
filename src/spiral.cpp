#include<iostream>
#include<vector>
using namespace std;
    vector<int> getDir(int dir);

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ret;
        ret.reserve(matrix.size() * matrix[0].size());
        int hori = matrix[0].size(), vert = matrix.size() - 1;
        int dir = 0;
        int x = 0, y = -1;
        int ind = 0;
        while (hori > 0 && vert > 0)
        {
            vector<int> curDir = getDir(dir++);
            for (int i = 0; i < hori; ++i)
            {
                x += curDir[0]; y += curDir[1];
                ret.push_back(matrix[x][y]);
            }
            curDir = getDir(dir++);
            for (int i = 0; i < vert; ++i)
            {
                x += curDir[0]; y += curDir[1];
                ret.push_back(matrix[x][y]);
            }
            hori--;
            vert--;
        }
        if (hori > 0)
        {
            vector<int> curDir = getDir(dir++);
            for (int i = 0; i < hori; ++i)
            {
                x += curDir[0]; y += curDir[1];
                ret.push_back(matrix[x][y]);
            }
        }
        return ret;
    }
    vector<int> getDir(int dir)
    {
        dir = dir % 4;
        vector<int> ret(2,0);
        switch (dir)
        {
            case 0: ret[1] = 1; break;
            case 1: ret[0] = 1; break;
            case 2: ret[1] = -1; break;
            case 3: ret[0] = -1;break;
            default: return ret;
        }
        return ret;
    }
  
int main()
{
  vector<int>row(1,1);
  vector<vector<int> > mat(1, row);
  vector<int> ret = spiralOrder(mat);
  for (int i = 0; i < ret.size(); ++i)
    cout << ret[i] << ',';
  cout << endl; 
}
