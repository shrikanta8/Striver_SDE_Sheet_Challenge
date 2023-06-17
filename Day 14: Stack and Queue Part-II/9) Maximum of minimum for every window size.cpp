#include <stack>
vector<int> previousSmall(vector<int> &arr, int n) 
{
    vector<int> prev(n);
    stack<int> s;

    for (int i = 0; i < n; i++) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        if (s.empty()) 
        {
            prev[i] = -1;
        } 
        else 
        {
            prev[i] = s.top();
        }
        s.push(i);
    }
    return prev;
}
vector<int> smallerNext(vector<int> &arr, int n) 
{
    stack<int> s;
    vector<int> next(n);

    for (int i = n - 1; i >= 0; i--) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            next[i] = n;
        } 
        else 
        {
            next[i] = s.top();
        }
    
        s.push(i);
    }
    
    return next;
}

vector<int> maxMinWindow(vector<int> &arr, int n) 
{
    vector<int> ans(n, INT_MIN),next = smallerNext(arr, n), prev = previousSmall(arr, n);

    for (int i = 0; i < n; i++) 
    {
        int sz = next[i] - prev[i] - 1;

        ans[sz - 1] = max(ans[sz - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--) 
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}

