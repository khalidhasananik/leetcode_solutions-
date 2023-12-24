// leetcode submissions

#include <bits/stdc++.h>
using namespace std;

// problem: 128. Longest Consecutive Sequence

// approach: using set

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // insert all elements in set

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for (auto it : s)
        {
            if (!s.count(it - 1))
            {
                int len = 0;

                while (s.count(it++))
                    len++;

                ans = max(ans, len);
            }
        }

        return ans;
    }
};

// problem: 271. Encode and Decode Strings

// approach: using length of string and a delimiter

class Codec
{
public:
    string encode(vector<string> &strs)
    {
        string ans = "";

        for (auto s : strs)
            ans += to_string(s.length()) + "#" + s;

        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;

        int i = 0;

        while (i < s.length())
        {
            int j = i;

            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i)); // length of string
            // stoi converts string to integer

            ans.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return ans;
    }
};

// problem: 2133. Remove All Adjacent Duplicates in String

// my approach: using set

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

// problem: 36. Valid Sudoku

// approach: using array(check row column and sub matrix(row/3,col/3))

// note: if you forget how sub matrix works see your notebook(page:4-5)

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub_boxes[9][9] = {false};

        for (int i = 0; i < 9; i++)

            for (int j = 0; j < 9; j++)

                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';

                    int sub_index = (i / 3) * 3 + (j / 3);

                    if (row[i][num] || col[j][num] || sub_boxes[sub_index][num])
                        return false;

                    row[i][num] = col[j][num] = sub_boxes[sub_index][num] = true;
                }

        return true;
    }
};

// 215. Kth Largest Element in an Array

// my approach: using vector and sort

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }
};

// 238. Product of Array Except Self

// approach: using prefix and postfix product array

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n, 1);

        int prefix = 1;

        for (int i = 0; i < n; i++)

            ans[i] = prefix, prefix *= nums[i];

        int postfix = 1;

        for (int i = n - 1; i >= 0; i--)

            ans[i] *= postfix, postfix *= nums[i];

        return ans;
    }
};

// my approach: without using division

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        long long int product = 1;

        bool zero = false;

        int zero_count = 0;

        int index;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero_count++;
                if (zero_count > 1)
                    return vector<int>(nums.size(), 0);
                zero = true;
                index = i;
                continue;
            }

            product *= nums[i];
        }

        if (zero)
        {
            vector<int> ans(nums.size(), 0);
            ans[index] = product;
            return ans;
        }

        for (int i = 0; i < nums.size(); i++)
            nums[i] = divide(product, nums[i]);
    }

private:
    int divide(int a, int b)
    {
        int sign = 1;
        if ((a > 0 && b <= 0) || (a <= 0 && b > 0))
        {
            sign = -1;
        }
        a = abs(a);
        b = abs(b);
        int quotient = 0;
        for (int i = 30; i >= 0; i--)
        {
            long long temp = (long long)b << (long long)i;
            if (temp <= a)
            {
                a -= temp;
                quotient += 1 << i;
            }
        }
        return sign * quotient;
    }
};

// problem: 347. Top K Frequent Elements

// approach: using map and bucket sort(less efficient)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)

            mp[nums[i]]++;

        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for (auto it : mp)

            bucket[it.second].push_back(it.first);

        vector<int> ans;

        for (int i = n; i >= 0; i--)
        {

            if (ans.size() >= k)
                break;

            if (!bucket[i].empty())
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
        }

        return ans;
    }
};
// my approach: using map

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)

            mp[nums[i]]++;

        // sort map in terms of value

        multimap<int, int, greater<int>> mm;

        for (auto it : mp)
            mm.insert({it.second, it.first});

        vector<int> ans;

        while (k--)
        {
            ans.push_back(mm.begin()->second);
            mm.erase(mm.begin());
        }

        return ans;
    }
};

// problem:49. Group Anagrams

// my approach: using map

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto it : mp)
            ans.push_back(it.second);

        return ans;
    }
};

// problem:1. Two Sum

// my approach: using hash map

// note: find()  function is better than count() function in terms of time complexity

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            // if (mp.find(target - nums[i]) != mp.end())
            //     return {mp[target - nums[i]], i};
            if (mp.count(target - nums[i]))
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }

        return {};
    }
};

// problem:242. Valid Anagram

// my approach three: using list[not good, more time complexity]
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        list<char> l1(s.begin(), s.end());
        list<char> l2(t.begin(), t.end());

        l1.sort();
        l2.sort();

        return l1 == l2;
    }
};

// my approach two: using sorting

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// my approach: using map

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        map<char, int> mp;

        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto it : mp)

            if (it.second != 0)
                return false;

        return true;
    }
};

// problem: 219. Contains Duplicate II

// approach: using map

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] - i) <= k)
                return true;

            // second approach

            // if (mp.count(nums[i]) && abs(mp[nums[i]] - i) <= k)
            //     return true;

            mp[nums[i]] = i;
        }

        return false;
    }
};

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
    }
};

// problem:217. Contains Duplicate

// my approach: using map

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;

            if (mp[nums[i]] > 1)
                return true;
        }

        return false;
    }
};

// cool approach: using set

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};