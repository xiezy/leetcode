#include<iostream>
#include<vector>

using namespace std;
    int singleNumber(int A[], int n) {
        vector<int> vec(32,0);
        for (int i = 0; i < n; ++i)
        {
            int val = A[i];
            int bit = 0;
int test = -5;
test >>= 1;
cout << test << endl;
            while (val != 0)
            {
                vec[bit] += val&1;
                val >>=1;
                bit++;
            }
        }
        for (int i = 0; i < 32; ++i)
        {
            vec[i] %= 3;
cout << vec[i] << ',';
        }
cout << endl;
        int ret = 0;
        for (int i = 31; i >= 0; --i)
        {
            ret <<= 1;
            ret |= vec[i];
        }
        return ret;
    }
int main()
{
  int A[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
  cout << singleNumber(A,10) << endl;
}
