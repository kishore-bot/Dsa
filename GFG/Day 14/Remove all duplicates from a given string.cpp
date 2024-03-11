// Easy
// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

class Solution
{
public:
    string removeDuplicates(string str)
    {
        int lower[26] = {0};
        int upper[26] = {0};
        string ans = "";
        for (int i = 0; i < str.size(); i++)
        {
            char currentChar = str[i];
            if (currentChar >= 'a' && currentChar <= 'z')
            {
                int index = currentChar - 'a';
                if (lower[index] == 0)
                {
                    ans += currentChar;
                    lower[index] = 1;
                }
            }
            else if (currentChar >= 'A' && currentChar <= 'Z')
            {
                int index = currentChar - 'A';
                if (upper[index] == 0)
                {
                    ans += currentChar;
                    upper[index] = 1;
                }
            }
            else
            {
                // If the character is neither lowercase nor uppercase, simply add it to the answer
                ans += currentChar;
            }
        }
        return ans;
    }
};