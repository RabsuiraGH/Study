/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
 */
IList<int> LuckyNumbers(int[][] matrix)
{
    List<int> minRows = new();
    List<int> returnList = new List<int>();

    for (int row = 0; row < matrix.Length; row++)
    {
        int min = int.MaxValue;
        for (int column = 0; column < matrix[0].Length; column++)
        {
            if (matrix[row][column] < min)
                min = matrix[row][column];
        }
        minRows.Add(min);
    }
    for (int column = 0; column < matrix[0].Length; column++)
    {
        int max = int.MinValue;
        for (int row = 0; row < matrix.Length; row++)
        {
            if (matrix[row][column] > max)
                max = matrix[row][column];
        }
        if (minRows.Contains(max))
            returnList.Add(max);
    }

    return returnList;
}

// [1,10,4,2],[9,3,8,7],[15,16,17,12],
// [1,10,4,2],[9,3,8,7],[15,16,17,12],
// [1,10,4,2],[9,3,8,7],[15,16,17,12]