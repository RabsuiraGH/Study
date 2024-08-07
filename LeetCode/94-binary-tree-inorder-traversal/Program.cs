/*
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively? // no bruh
 */

IList<int> InorderTraversal(TreeNode root)
{
    var returnList = new List<int>();

    Rec(root);
    void Rec(TreeNode node)
    {
        if (node == null) return;
        Rec(node.left);
        returnList.Add(node.val);
        Rec(node.right);
    }
    return returnList;
}

internal class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}