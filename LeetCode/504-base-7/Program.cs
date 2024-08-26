/*
Given an integer num, return a string of its base 7 representation.

Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"

Constraints:

-107 <= num <= 107
 */

using System.Text;

string ConvertToBase7(int num)
{
    if (num is > -7 and < 7) return num.ToString();

    StringBuilder output = new();
    int reminder = num;

    if (reminder < 0)
    {
        reminder = Math.Abs(reminder);
    }

    while (reminder != 0)
    {
        output.Insert(0, reminder % 7);
        reminder = reminder / 7;
    }
    if (num < 0)
        output.Insert(0, '-');
    return output.ToString();
}