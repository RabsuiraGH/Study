/*
Given a list of dominoes,
dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d]
if and only if either(a == c and b == d), or(a == d and b == c) - that is,
one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:

Input: dominoes = [[1, 2], [2, 1], [3, 4], [5, 6]]
Output: 1
Example 2:

Input: dominoes = [[1, 2], [1, 2], [1, 1], [1, 2], [2, 2]]
Output: 3
    */

internal class Program
{
    private static void Main(string[] args)
    {
        int[][] array = new int[][]
{
    new int[] {1, 2},
    new int[] {1, 2},
    new int[] {1, 1},
    new int[] {1, 2},
    new int[] {2, 2}
};
        int res = new Solution().NumEquivDominoPairs(array);
        Console.WriteLine(res);
    }

    public class Solution
    {
        public int NumEquivDominoPairs(int[][] dominoes)
        {
            int[] dominoesCountHash = new int[100];

            foreach (int[] domino in dominoes)
            {
                int x = Math.Min(domino[0], domino[1]);
                int y = Math.Max(domino[0], domino[1]);
                dominoesCountHash[x * 10 + y]++;
            }

            int res = 0;

            for (int i = 0; i < 100; i++)
            {
                if (dominoesCountHash[i] > 0)
                {
                    res += ((dominoesCountHash[i] * (dominoesCountHash[i] - 1)) / 2);
                }
            }

            return res;
        }
    }
}