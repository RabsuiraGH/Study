/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
 */

ListNode MergeTwoLists(ListNode list1, ListNode list2)
{
    if (list1 == null && list2 == null) return null;

    ListNode returnList = new();
    ListNode dummyHead = returnList;

    while (list1 != null || list2 != null)
    {
        if (list1 == null)
        {
            returnList.next = new(list2.val);
            list2 = list2.next;
        }
        else if (list2 == null)
        {
            returnList.next = new(list1.val);
            list1 = list1.next;
        }
        else
        if (list1.val <= list2.val)
        {
            returnList.next = new(list1.val);
            list1 = list1.next;
        }
        else
        {
            returnList.next = new(list2.val);
            list2 = list2.next;
        }

        returnList = returnList.next;
    }

    return dummyHead.next;
}

public class ListNode
{
    public int val;
    public ListNode next;

    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}