// https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
// Medium
// String

//  bruttte
class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {

        for (int i = 0; i < r; i++)
        {
            string ans = "";
            for (auto c : s)
            {
                if (c == '0')
                {
                    ans += "01";
                }
                else
                {
                    ans += "10";
                }
            }
            s = ans;
        }
        return s[n];
    }
};

// Optimal

/**
 * same code
 * given constraints n <|s|
 * so we need to get only s.size() array
 * https://www.youtube.com/watch?v=2sztdnfru8s
*/
class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        int m = s.size();

        for (int i = 0; i < r; i++)
        {
            string ans = "";
            for (auto c : s)
            {
                if (c == '0')
                {
                    ans += "01";
                }
                else
                {
                    ans += "10";
                }
                if (ans.size() > m)
                    break;
            }
            s = ans;
        }
        return s[n];
    }
};