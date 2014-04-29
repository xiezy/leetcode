#include<string>
#include<iostream>
using namespace std;
string findPalin(string s, int left, int right)
{
  while (left >= 0 && right < s.length())
  {
    if (s[left] != s[right])
    {
        left++, right--;
	if (left > right) return "";
	cout << left << ',' << right << " Mismatch: returning " << s.substr(left, right - left + 1) << endl;
        return s.substr(left, right - left + 1);
    }
    left--, right++;
  }
  left++, right--;
  if (left > right) return "";
  cout << left << ',' << right << " EOS: returning " << s.substr(left, right - left + 1) << endl;
  return s.substr(left, right - left + 1); 
}
string longestPalindrome(string s) {
  string ret;
  for (int i = 0; i < s.length(); ++i)
  {
    string str = findPalin(s,i,i);
    if (str.length() > ret.length())
	ret = str;
    str = findPalin(s,i,i+1);
    if (str.length() > ret.length())
	ret = str;
  }
  return ret;
}
int main()
{
  cout << longestPalindrome("abb") << endl;
}
