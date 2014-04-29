#include<iostream>
using namespace std;

bool isnumber(char a)
{
	if((a) >= '0' && (a) <= '9')
		return true;
	return false;
}

int append(int oldnum, int newdigit, bool nagated, int &state)
{
    if(nagated)
	{
		if(((INT_MIN + newdigit) / 10) > oldnum)
		{
			state = 3;
			return INT_MIN;
		}
		else 
			return (oldnum*10 - newdigit);
	}
	else 
	{
		if(((INT_MAX- newdigit) / 10) < oldnum)
		{
			state = 3;
			return INT_MAX;
		}
		else 
			return (oldnum*10 + newdigit);
	}
}

    int atoi(const char *str) {
        int state = 0; //0: in intial white space; 1: + or 1 after inital white space; 2: in first sequence of integer; 
                       //3: has finished, or has failed to get the integer
        const char *cur = str;
        int num = 0;
        bool isNeg = false;
        bool nagated = false;
	
	while((state != 3) && (*cur)!='\0')
	{
		switch (state)
		{
			case 0:
				if((*cur) == '+')
					state = 1;
				else if((*cur) == '-')
				{
					state = 1;
					isNeg = true;
				}
				else if(isnumber(*cur))
				{
					state = 2;
					num = (*cur) - '0';
				}
				else if((*cur) == ' ')
					break;
				else 
					state = 3; //failed to find the number
				break;
			case 1:
				if(isnumber(*cur))
				{
					state = 2;
					num = (*cur) - '0';
				}
				else 
					state = 3;
				break;
			case 2:
				if(isNeg) 
				{
					num = -num;
					nagated = true;
					isNeg = false;
				}
				
				if(isnumber(*cur))
					num = append(num, ((*cur) - '0'), nagated, state);
				else 
					state = 3;
				break;
			default:
				break;
		}
		cur++;
	}
        return num;
    }
int main()
{
  cout << atoi("-1") << endl;
}
