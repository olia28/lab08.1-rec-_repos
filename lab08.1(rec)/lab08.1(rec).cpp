#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 2)
        return 0;

    else if (str[i + 1] != 0)
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') || (str[i] == 'b' && str[i + 1] == 'b') || (str[i] == 'c' && str[i + 1] == 'c'))
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }

    else return 0;
}

char* Change(char* dest, const char* str, char* t, int i = 0)
{
    if (str[i + 1] != 0)
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') || (str[i] == 'b' && str[i + 1] == 'b') || (str[i] == 'c' && str[i + 1] == 'c'))
        {
            strcat(t, "***");
            return Change(dest, str, t + 3, i + 2);
        }

        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }

    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:"; cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of 'aa'\\'bb'\\'cc'" << endl;

    char* dest = new char[151]; dest[0] = '\0';
    char* param = Change(dest, str, dest);

    cout << "Modified string (param) : " << param << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}