/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

foreach (var item in TwoSum(new int[] { 2, 7, 11, 15 }, 9))
{
    Console.WriteLine(item);
}

int[] TwoSum(int[] nums, int target)
{
    SortedDictionary<int, int> valIndex = new();

    for (int i = 0; i < nums.Length; i++)
    {
        if (valIndex.TryGetValue(target - nums[i], out int index))
            return new int[] { i, index };

        if (!valIndex.ContainsKey(nums[i])) valIndex.Add(nums[i], i);
    }

    return new int[0];
}