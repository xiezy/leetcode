#include<iostream>
#include<vector>
#include<string>
using namespace std;

    string processReturn(vector<string>& vec);
    string convert(string s, int nRows) {
        vector<string> down;
        int ind = 0;
        while (ind + nRows + nRows - 2 <= s.length())
        {
            string str = s.substr(ind, nRows);
            down.push_back(str);
            for (int i = nRows - 2, j = 0; i >= 1; --i, ++j)
            {
                string front(i,' ');
                string back(nRows - 1 - i, ' ');
                str = front + s[ind+nRows+j] + back;
                down.push_back(str);
            }
            ind += nRows + nRows - 2;
        }
        if (ind + nRows <= s.length())
        {
            string str = s.substr(ind, nRows);
            down.push_back(str);
            ind += nRows;
        }
        else
        {
            string str = s.substr(ind, s.length() - ind);
            string back(nRows - str.length(), ' ');
            down.push_back(str+back);
            return processReturn(down);
        }
        for (int i = nRows - 2, j = 0; i >= 1 && ind < s.length(); --i, ++j)
        {
            string front(i,' ');
            string back(nRows - 1 - i, ' ');
            string str = front + s[ind] + back;
            down.push_back(str);
            ind++;
        }
        return processReturn(down);
    }
    string processReturn(vector<string>& vec)
    {
        string ret;
        for (int j = 0; j < vec[0].length(); ++j)
        for (int i = 0; i < vec.size(); ++i)
            {
                if (vec[i][j] != ' ')
                ret.append(1, vec[i][j]);
            }
        return ret;
    }
int main()
{
  cout <<  convert("PAYPALISHIRING", 9);
}
