// Created by Khalid Hasan
// Created on: 9-jan-2024
// github: https://github.com/khalidhasananik/leetcode_solutions-/blob/main/test.cpp

// the problem is to check whether a string is palindrome or not ignoring cases and special characters
// approach: using two pointers

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            while (i < j && !isalnum(s[i]))
                i++;

            while (i < j && !isalnum(s[j]))
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};
signed main()
{
    fast_io;

    string s = "A man, a plan, a canal : Panama";

    Solution obj;

    if (obj.isPalindrome(s))
        cout << "is palindrome" << endl;
    else
        cout << "not palindrome" << endl;

    string t = "race a car";

    if (obj.isPalindrome(t))
        cout << "is palindrome" << endl;
    else
        cout << "not palindrome" << endl;

    return 0;
}