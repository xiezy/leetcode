#include<string>
#include<iostream>
using namespace std;
    int singleNumber(int A[], int n) {
        int arr[32];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; ++i)
        {
            int val = A[i];
            for (int pos = 0; pos < 32; ++pos)
            {
                arr[pos] += val&1;
                val >>= 1;
            }
        }
        int ret = 0;
        for (int i = 31; i >=0; --i)
        {
cout << arr[i];
            ret*=2;
            ret+=arr[i]%3;
        }
cout << endl;
        return ret;
    }
int main()
{
  int A[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	cout << singleNumber(A, 10) << endl;
}
