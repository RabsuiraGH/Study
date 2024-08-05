/*
 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

bool IsValid(string s)
{
    if (s == null || s.Length == 0)
        return true;
    if (s.Length == 1)
        return false;

    Dictionary<char, char> dic = new Dictionary<char, char>()
    {
        ['('] = ')',
        ['['] = ']',
        ['{'] = '}'
    };

    Stack<char> stack = new Stack<char>();

    foreach (char c in s)
    {
        if (dic.ContainsKey(c))
        {
            stack.Push(c);
            continue;
        }

        if (stack.Count == 0) return false;

        if (dic[stack.Peek()] == c)
        {
            stack.Pop();
            continue;
        }
        else return false;
    }

    return stack.Count <= 0;
}