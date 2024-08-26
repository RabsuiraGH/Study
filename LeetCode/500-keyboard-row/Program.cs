/*
Given an array of strings words, return the words that can be typed using letters
of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]

Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase).
 */

string[] FindWords(string[] words)
{
    List<string> rows = new List<string> { "qwertyuiop", "asdfghjkl", "zxcvbnm" };

    List<string> output = new();

    for (int i = 0; i < words.Length; i++)
    {
        int row = -1;

        for (int j = 0; j < words[i].Length; j++)
        {
            char c = words[i].ToLower()[0];

            if (row == -1)
            {
                row = rows.IndexOf(rows.First(x => x.Contains(c)));
            }
            if (row != rows.IndexOf(rows.First(x => x.Contains(words[i].ToLower()[j]))))
            {
                row = -2;
                break;
            }
        }

        if (row != -2) output.Add(words[i]);
    }

    return output.ToArray();
}