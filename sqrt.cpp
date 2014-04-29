#include<iostream>
using namespace std;
    int sqrt(int x) {
        int left = 1, right = x;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid<x)
                left = mid;
            else right = mid-1;
        }
        return left;
    }
int main()
{
  cout << sqrt(2147395599) << endl;
}
