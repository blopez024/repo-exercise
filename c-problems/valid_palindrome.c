/*
 LeetCode Problem:  125 Valid Palindrome
 Description:       A phrase is a palindrome if, after converting all
                    uppercase letters into lowercase letters and removing
                    all non-alphanumeric characters, it reads the same
                    forward and backward. Alphanumeric characters include
                    letters and numbers.
 Link:              https://leetcode.com/problems/valid-palindrome/description/
*/

int str_length(char *c)
{
    int i = 0;

    while (c[i] != '\0')
    {
        i++;
    }

    return i;
}

int is_alphanum(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int to_lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

bool isPalindrome(char *s)
{

    int i = 0;
    int j = str_length(s);

    while (i < j)
    {
        if (!is_alphanum(s[i]))
        {
            i++;
            continue;
        }
        else if (!is_alphanum(s[j]))
        {
            j--;
            continue;
        }
        else
        {
            int si = to_lower(s[i]);
            int sj = to_lower(s[j]);

            if (si != sj)
            {
                return false;
            }

            i++;
            j--;
        }
    }

    return true;
}

int isAlphanum(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}