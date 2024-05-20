// leetcode submissions

#include <bits/stdc++.h>
using namespace std;

// problem: 875. Koko Eating Bananas

// my approach: using binary search

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int hours = 0;

            for (int i = 0; i < piles.size(); i++)
                hours += ceil((double)piles[i] / mid);

            if (hours <= h)
                high = mid;

            else
                low = mid + 1;
        }

        return low;
    }
};

// problem 74. Search a 2D Matrix

// approach: using binary search

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lowRow = 0, highRow = matrix.size() - 1;

        while (lowRow < highRow)
        {
            int mid = lowRow + (highRow - lowRow) / 2;

            if (matrix[mid][0] == target)

                return true;

            if (matrix[mid][0] < target && target < matrix[mid + 1][0])
            {
                lowRow = mid;

                break;
            }

            if (matrix[mid][0] < target)

                lowRow = mid + 1;

            else

                highRow = mid - 1;
        }

        int lowCol = 0, highCol = matrix[0].size() - 1;

        while (lowCol <= highCol)
        {
            int mid = lowCol + (highCol - lowCol) / 2;

            if (matrix[lowRow][mid] == target)

                return true;

            if (matrix[lowRow][mid] < target)

                lowCol = mid + 1;

            else

                highCol = mid - 1;
        }

        return false;
    }
};

// problem: 704. Binary Search

// my approach: using binary search

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                left = mid + 1;

            else
                right = mid - 1;
        }

        return -1;
    }
};
