/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

ListNode AddTwoNumbers_1(ListNode l1, ListNode l2)
{
    ListNode result = new();
    ListNode head = result;
    int res;
    int rem = 0;

    int d1;
    int d2;
    while (l1 != null || l2 != null)
    {
        d1 = l1 != null ? l1.val : 0;
        d2 = l2 != null ? l2.val : 0;

        res = d1 + d2 + rem;

        rem = res / 10;

        l1 = l1?.next;
        l2 = l2?.next;

        result.next = new(res % 10);

        result = result.next;
    }
    if (rem > 0)
        result.next = new(1);

    return head.next;
}

ListNode AddTwoNumbers_2(ListNode l1, ListNode l2)
{
    ListNode num1 = l1;
    ListNode num2 = l2;
    ListNode result = new ListNode();
    ListNode head = result;
    int res = 0;
    int rem = 0;
    bool haveNum1 = true;
    bool haveNum2 = true;
    int d1 = 0;
    int d2 = 0;
    while (true)
    {
        if (haveNum1)
            d1 = num1.val;
        if (haveNum2)
            d2 = num2.val;

        res = d1 + d2 + rem;

        if (res >= 10)
        {
            rem = res / 10;
            res = res % 10;
        }
        else
        {
            rem = 0;
        }

        if (num1.next == null)
        {
            haveNum1 = false;
            d1 = 0;
        }
        else { num1 = num1.next; }

        if (num2.next == null)
        {
            haveNum2 = false;
            d2 = 0;
        }
        else { num2 = num2.next; }
        result.val = res;
        if (!haveNum1 && !haveNum2) { if (rem != 0) { result.next = new(rem); }; break; }

        result.next = new();
        result = result.next;
    }

    return head;
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