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
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            set<int> row, col;

            for (int j = 0; j < n; j++)
            {
                row.insert(matrix[i][j]);
                col.insert(matrix[j][i]);
            }

            if (row.size() != n || col.size() != n)
                return false;
        }

        return true;
    }
};

signed main()
{
    fast_io;

    std_in_out;

    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++)

            cin >> matrix[i][j];

    Solution obj;

    if (obj.checkValid(matrix))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;

    return 0;
}