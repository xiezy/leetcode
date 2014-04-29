#include <iostream>
using namespace std;
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*(s+len) != '\0') len++;
        int ind = 0;
        while ((ind < len) && !isalpha(*(s+len-ind)))
            ind++;
        len -= ind;
        int ret = 0;
        while (ret < len && isalpha(*(s+len-ret)))
            ret++;
        return ret;
    }
int main()
{
  cout << lengthOfLastWord("") << endl;
}
