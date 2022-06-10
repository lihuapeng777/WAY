#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int find_rotation(string str)
{
    ll ans = 1;
    string temp = str.back() + str.substr(0, str.size() - 1);
    while (temp != str)
    {
        temp = temp.back() + temp.substr(0, temp.size() - 1);
        ans++;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    vector<bool> used(n, false);
    int ans = 1;
    int i = 0;

    while (i < n)
    {
        string ss = "";
        while (used[i])
        {
            ss += s[i];
            used[i] = true;
            i = p[i];
        }
        i += 1;
        if (ss.size() == 0)
            continue;
        int In = find_rotation(ss);
        ans = (ans * In) / gcd(ans, In);
    }
    cout << ans << endl;
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}