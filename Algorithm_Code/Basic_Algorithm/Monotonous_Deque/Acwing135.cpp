#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>

using namespace std;

const int N = 3e5 + 10;

typedef long long ll;

int n, m;
deque<int> q;

ll s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    ll res = INT_MIN;
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && i - q.front() > m)
        {
            q.pop_front();
        }
        //特殊样例12/14:第一个数就是答案
        res = max(res, s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] >= s[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << res << endl;
    return 0;
}