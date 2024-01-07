// leetcode submissions

#include <bits/stdc++.h>
using namespace std;

// problem: 84. Largest Rectangle in Histogram

// approach: using stack

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // pair: [index, height]
        stack<pair<int, int>> stk;

        int ans = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;

            while (!stk.empty() && stk.top().second > heights[i])
            {
                int index = stk.top().first;

                int width = i - index;

                int height = stk.top().second;

                stk.pop();

                ans = max(ans, height * width);

                start = index;
            }

            stk.push({start, heights[i]});
        }

        while (!stk.empty())
        {
            int width = heights.size() - stk.top().first;

            int height = stk.top().second;

            stk.pop();

            ans = max(ans, height * width);
        }

        return ans;
    }
};

// my approach: using map and array

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        map<int, double> mp;

        for (int i = 0; i < n; i++)
            // the minus sign is used to sort the map in descending order
            mp[-position[i]] = (double)(target - position[i]) / speed[i];

        double maxTime = 0;

        int ans = 0;

        for (auto it : mp)

            if (it.second > maxTime)
            {
                maxTime = it.second;
                ans++;
            }

        return ans;
    }
};

// problem: 739. Daily Temperatures

// approach: using stack

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);

        stack<int> st;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

// problem: 22. Generate Parentheses

// approach: using recursion

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }

private:
    void generate(int n, int open, int close, string str, vector<string> &ans)
    {
        if (open == n and close == n)
        {
            ans.push_back(str);

            return;
        }
        if (open < n)

            generate(n, open + 1, close, str + '(', ans);

        if (open > close)

            generate(n, open, close + 1, str + ')', ans);
    }
};

// problem: 150. Evaluate Reverse Polish Notation

// approach: using stack

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if (tokens[i] == "+")
                    st.push(a + b);
                else if (tokens[i] == "-")
                    st.push(b - a);
                else if (tokens[i] == "*")
                    st.push(a * b);
                else
                    st.push(b / a);
            }
            else
                st.push(stoi(tokens[i]));
        }

        return st.top();
    }
};

// problem: 155. Min Stack

// my approach: using two stacks

class MinStack
{
public:
    stack<int> st;

    stack<int> min_st;

    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);

        if (min_st.empty() || val <= min_st.top())
            min_st.push(val);
    }

    void pop()
    {
        if (st.top() == min_st.top())
            min_st.pop();

        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};

// problem:20. Valid Parentheses

// my approach: using stack and hash map

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        map<char, char> mp;

        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            else if (st.empty() || st.top() != mp[s[i]])
                return false;

            else
                st.pop();
        }

        return st.empty();
    }
};