/*

Question # 1160. Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


*/


//Solution main idea:

/*
 Main idea: for each word check if it's not good, then move to the next
        - Mark the existence frequency of the 128 ascii codes characters in the gvien chars
        - For each word:
            1. Check if its character is marked , if not it's not good
            2. If character is marked reduce its apparation frequency.
*/

class Solution {
public:
    int countCharacter(vector<string> &words, string chars)
    {
        int sum = 0;
        for(int i =0; i < words.size(); i++)
        {
            int exist[128] = {0};
            for(int i = 0; i < chars.length(); i++) exist[chars[i]]++;
            //Assume current word is good.
            sum += words[i].length();
            //Check if current word is not good
            for(int j = 0; j < words[i].length(); j++)
            {
                //current word is not good.
                if(exist[words[i][j]] == 0)
                {
                    sum -= words[i].length();
                    break;
                }
                //Character already used remove it.
                else exist[words[i][j]]--;
            }
        }
        return sum;

    }
}