/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.



Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

*/

#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    static vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> returnVector = { {}, {} };

        

        for (int i = 0; i < nums1.size(); i++)
        {
            auto result = find(nums2.begin(), nums2.end(), nums1[i]);
            if (result == nums2.end() && find(returnVector[0].begin(), returnVector[0].end(), nums1[i]) == end(returnVector[0]))
            {
                returnVector[0].push_back(nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            auto result = find(nums1.begin(), nums1.end(), nums2[i]);
            if (result == nums1.end() && find(returnVector[1].begin(), returnVector[1].end(), nums2[i]) ==end( returnVector[1]))
            {
                returnVector[1].push_back(nums2[i]);
            }
        }


        return returnVector;
    }
};

void main()
{
    vector<int> vector1 = { 1,2,3,3 };
    vector<int> vector2 = { 1,1,2,2 };

    for (vector<int> vect : Solution::findDifference(vector1, vector2))
    {
        for (int n : vect)
        {
            cout << n << endl;
        }
        cout << endl;
    }


}