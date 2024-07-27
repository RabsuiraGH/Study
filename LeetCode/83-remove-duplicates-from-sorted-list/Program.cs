/*
 Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
 */

ListNode DeleteDuplicates(ListNode head)
{
    if (head == null) return head;
    int[] nums = new int[201];
    ListNode cur = head;
    ListNode newHead = cur;

    nums[cur.val + 100] = 1;

    while (cur.next != null)
    {
        if (nums[cur.next.val + 100] != 1)
        {
            nums[cur.next.val + 100] = 1;
            cur = cur.next;

        }
        else
        {
            cur.next = cur.next.next;

        }
    }
    return head;
}
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

