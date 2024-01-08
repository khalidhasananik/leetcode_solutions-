// leetcode submissions

#include <bits/stdc++.h>
using namespace std;

// problem: 42. Trapping Rain Water

// approach: using two pointers

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        int left = 0, right = n - 1;

        int leftMax = height[left], rightMax = height[right];

        int ans = 0;

        while (left < right)
        {
            if (leftMax <= rightMax)
            {
                left++;
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
            }

            else
            {
                right--;
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
            }
        }

        return ans;
    }
};

// problem: 11. Container With Most Water

// approach: using two pointers

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;

        int i = 0, j = height.size() - 1;

        while (i < j)
        {
            int area = min(height[i], height[j]) * (j - i); // min  height is the bottleneck

            maxArea = max(maxArea, area);

            if (height[i] < height[j])
                i++;

            else
                j--;
        }

        return maxArea;
    }
};

// problem: 15. 3Sum

// approach: using set and  two pointers , optimized

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        set<vector<int>> s; // to avoid duplicates

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // adding this condition is fine, les TC
                continue;

            int j = i + 1, k = n - 1;

            while (j < k)
            {
                // adding these conditions is not worth it, more TC
                // if (j > i + 1 && nums[j] == nums[j - 1])
                // {
                //     j++;
                //     continue;
                // }

                // if (k < n - 1 && nums[k] == nums[k + 1])
                // {
                //     k--;
                //     continue;
                // }

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                else if (sum < 0)
                    j++;

                else
                    k--;
            }
        }

        for (auto it : s)
            ans.push_back(it);

        return ans;
    }
};

// approach: using set and  two pointers

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        set<vector<int>> s; // to avoid duplicates

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                else if (sum < 0)
                    j++;

                else
                    k--;
            }
        }

        for (auto it : s)
            ans.push_back(it);

        return ans;
    }
};

// problem: 167. Two Sum II - Input array is sorted

// approach: using two pointers

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;

        while (i < j)
        {
            int sum = numbers[i] + numbers[j];

            if (sum < target)
                i++;

            else if (sum > target)
                j--;

            else
                return {i + 1, j + 1};
        }

        return {};
    }
};

// problem: 125. Valid Palindrome

// approach: using two pointers

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

// my approach: using reverse string

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();

        string s1 = "";

        for (int i = 0; i < n; i++)

            if (isalnum(s[i]))

                s1 += tolower(s[i]);

        string s2 = s1;

        reverse(s1.begin(), s1.end());

        return s1 == s2;
    }
};