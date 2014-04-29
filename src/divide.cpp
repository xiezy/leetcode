#include<iostream>
using namespace std;
    int divide(int dividend, int divisor) {
        long long dd = (long long) dividend, dv = (long long) divisor;
        while (dv <= dd)
        {
            dv = dv << 1;
        }
        dv = dv >> 1;
        int ret = 0;
        while (dd > 0)
        {
cout << dd << ',' << dv << ',' << ret << endl;
            if (dd >= dv)
            {
                dd -= dv;
                ret |= 1;
                ret = ret << 1;
            }
            dv = dv >> 1;
        }
        return ret;
    }
int main()
{
  int dd, dv;
  cin >> dd >> dv;
  cout << divide(dd,dv) << endl;
}
