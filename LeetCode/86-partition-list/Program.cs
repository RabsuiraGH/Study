/*
Given the head of a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

 */

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

public class Solution
{
    public ListNode Partition(ListNode head, int x)
    {
        ListNode temp = head;
        ListNode blankNode = new ListNode(-1);
        ListNode newHead = blankNode;

        while (temp != null)
        {
            if (temp.val < x)
            {
                blankNode.next = new ListNode(temp.val);
                blankNode = blankNode.next;
            }
            temp = temp.next;
        }

        temp = head;
        while (temp != null)
        {
            if (temp.val >= x)
            {
                blankNode.next = new ListNode(temp.val);
                blankNode = blankNode.next;
            }
            temp = temp.next;
        }
        return newHead.next;
    }
}