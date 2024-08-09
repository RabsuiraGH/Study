/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
 */

using System.Text;

string AddBinary(string a, string b)
{
    var result = new StringBuilder();

    int i = a.Length - 1, j = b.Length - 1;

    int temp = 0;

    for (; i >= 0 || j >= 0; i--, j--)
    {
        temp += (i >= 0 ? a[i] - '0' : 0);
        temp += (j >= 0 ? b[j] - '0' : 0);

        result.Insert(0, temp % 2);

        temp /= 2;
    }

    if (temp > 0)
        result.Insert(0, temp);

    return result.ToString();
}