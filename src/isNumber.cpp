#include<cctype>
#include<iostream>
using namespace std;
    bool isNumber(const char *s) {
        int plus = 0, minus = 0;;
        while (*s == ' ')
            s++;
        while (*s == '+')
        {
            plus++;
            s++;
        }
        while (*s == '-')
        {
            minus++;
            s++;
        }
        if (plus+minus > 1 ) return false;
        int dots = 0, nume = 0, nums = 0;
        while (*s != '\0')
        {
            // break to check trailing spaces
            if (*s == ' ')
                break;
            if (isalpha(*s) && (*s != 'e') && (*s != 'E'))
                return false;
            if (*s == '+' || *s == '-')
            {
                if (*(s-1) != 'e' && *(s-1) != 'E')
                {
cout << "exit" <<endl;    return false;
								}
            }
            else if (*s == '.')
            {
                if (nume > 0) return false;
                if (!isdigit(*(s+1)) && (nums == 0 ))
                    return false;
                dots++;
            }
/*            else if (*s == 'e' || *s == 'E')
            {
                if (!isdigit(*(s+1)) && nums == 0)
                {
									cout << "e" << endl;    
								return false;}
                nume++;
            }
*/
            else if (*s == 'e' || *s == 'E')
            {
                if ( nums == 0)
                    return false;
                if (*(s+1) == '+' || *(s+1) == '-')
                {
                    if (!isdigit(*(s+2)))
                        return false;
                }
                else if (!isdigit(*(s+1)))
                    return false;
                nume++;
            }

            else if (isdigit(*s))
                nums++;
            else return false;
            s++;
        }
        if (dots > 1 || nume > 1)
            return false;
        if (*s == ' ')
        {
            while (*s != '\0')
            {
                if (*s != ' ')
                    return false;
                s++;
            }
            return true;
        }
        if (nums <= 0) return false;
        return true;
    }
int main()
{
	cout << isNumber(" 005047e+6")<< endl;
	cout << isNumber("e9")<< endl;
	cout << isNumber("2e0");
}
