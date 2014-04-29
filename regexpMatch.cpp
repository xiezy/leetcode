#include<iostream>
using namespace std;

    bool isMatch(const char *s, const char *p) {
        if (p == NULL) return s == NULL;
        if (*p == '\0') return *s == '\0';
        if (*(p+1) == '*') 
        {
            while (*s!= '0' && (*s == *p || *p == '.'))
            {
                if (isMatch(s,p+2))
                    return true;
                s++;
            }
            return isMatch(s,p+2);
        }
        else
        {
            if (*p == '.' || *s == *p)
                return isMatch(s+1, p+1);
            else return false;
        }
}
int main()
{
    cout << isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*") << endl;
}
