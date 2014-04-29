#include<vector>
#include<iostream>

using namespace std;
    vector<int> searchRange(int A[], int n, int target) {
        int first = -1, second = -1;
        int lo = 0, hi = n-1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo)/2;
            if (A[mid] < target)
            {
                lo = mid+1;
            }
            else
            {
                hi = mid;
            }
        }
        if (A[lo] != target)
            first = -1;
        else first = lo;
//cout << first << endl;
        lo = 0, hi = n-1;
        while (lo < hi)
        {
            int mid = lo + (hi-lo+1)/2;
            if (A[mid] > target)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid;
            }
        }
        if (A[hi] != target)
            second = -1;
        else second = hi;
//cout << second << endl;
        vector<int> ret(2,0);
        ret[0] = first, ret[1] = second;
        return ret;
    }
int main()
{
  int A[6] = {5,7,7,8,8,10};
  searchRange(A,6,8);
}
