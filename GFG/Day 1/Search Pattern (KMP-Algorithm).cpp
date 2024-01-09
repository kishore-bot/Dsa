// String
// Medium
// https://www.geeksforgeeks.org/problems/search-pattern0205/1




#include<bits/stdc++.h>
using namespace std;


// Used Linear search and substring
class Solution {
public:
    std::vector<int> search(std::string pat, std::string txt) {
        std::vector<int> ans;
        for (int i = 0; i <= txt.size() - pat.size(); ++i) {
            if (txt[i] == pat[0]) {
                std::string compare = txt.substr(i, pat.size());
                if (compare == pat) {
                    ans.push_back(i + 1);
                }
            }
        }
        return ans.size() == 0 ? std::vector<int>{-1} : ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
