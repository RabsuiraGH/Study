/*
 
 Write a function that takes the binary representation of 
a positive integer and returns the number of set bits
it has (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

Constraints:

1 <= n <= 231 - 1
 */


int HammingWeight(int n)
{
    return
        Convert.ToString(n, 2)
        .Select(x => int.Parse(x.ToString()))
        .Sum();
}

 int HammingWeight_2(int n)
{
    int result = 0;
    int reminder;
    while (n != 0)
    {
        reminder = n % 2;
        if (reminder == 1)
        {
            result++;
        }
        n /= 2;

    }
    return result;
}