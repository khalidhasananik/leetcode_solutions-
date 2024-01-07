#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_in_out freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define std_in freopen("word.txt", "r", stdin);

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }

private:
    void generate(int n, int open, int close, string str, vector<string> &result)
    {
        cout << "generate(" << n << ", " << open << ", " << close << ", \"" << str << "\")" << endl;

        if (open == n && close == n)
        {
            result.push_back(str);
            cout << "Base case reached. Adding \"" << str << "\" to result." << endl;
            return;
        }

        if (open < n)
        {
            cout << "Calling generate with an added open parenthesis." << endl;
            generate(n, open + 1, close, str + '(', result);
        }

        if (open > close)
        {
            cout << "Calling generate with an added closed parenthesis." << endl;
            generate(n, open, close + 1, str + ')', result);
        }
    }
};
signed main()
{
    fast_io;

    std_in_out;

    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    cout << "Final result:" << endl;
    for (const string &s : result)
    {
        cout << s << endl;
    }

    return 0;
}