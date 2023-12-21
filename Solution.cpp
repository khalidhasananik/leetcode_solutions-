// leetcode submissions

#include <bits/stdc++.h>
using namespace std;

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