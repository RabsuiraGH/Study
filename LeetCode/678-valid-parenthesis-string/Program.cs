﻿/*
Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single
left parenthesis '(' or an empty string "".

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

 */

bool CheckValidString(string s)
{
    int minOpen = 0;

    int maxOpen = 0;

    foreach (char c in s)
    {
        if (c == '(')
        {
            minOpen++;
            maxOpen++;
        }
        else if (c == ')')
        {
            minOpen = Math.Max(minOpen - 1, 0);
            maxOpen--;
            if (maxOpen < 0)
                return false;
        }
        else
        {
            minOpen = Math.Max(minOpen - 1, 0);
            maxOpen++;
        }
    }

    return minOpen == 0;
}