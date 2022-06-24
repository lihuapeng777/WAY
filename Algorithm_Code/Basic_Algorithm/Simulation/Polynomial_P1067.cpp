#include <bits/stdc++.h>
using namespace std;
string res;
int n;
void first(int s)
{
    if (s == 1)
    {
        string t = to_string(n);
        res += 'x';
        res += '^';
        res += t;
    }
    else if (s == -1)
    {

        res += "-1";
        res += 'x';
        res += '^';
        string t = to_string(n);
        res += t;
    }
    else if (s == 0)
    {
        return;
    }
    else
    {
        string t = to_string(s);
        res += t;
        res += 'x';
        res += '^';
        t = to_string(n);
        res += t;
    }
}

void other(int s, int cnt)
{
    if (s == 1)
    {
        res += '+';
        res += 'x';
        string t = to_string(cnt);
        if (t == "1")
            return;
        res += '^';
        res += t;
    }
    else if (s == -1)
    {
        res += '-';
        res += 'x';
        string t = to_string(cnt);
        if (t == "1")
            return;
        res += '^';

        res += t;
    }
    else if (s > 1)
    {
        res += '+';
        string t = to_string(s);
        res += t;
        t = to_string(cnt);
        res += 'x';
        if (t == "1")
            return;
        res += '^';
        res += t;
    }
    else if (s < -1)
    {
        string t = to_string(s);
        res += t;
        res += 'x';
        t = to_string(cnt);
        if (t == "1")
            return;
        res += '^';
        res += t;
    }
}

void last(int s)
{
    if (s <= 0)
    {
        string t = to_string(s);
        res += t;
    }
    else if (s > 0)
    {
        res += '+';
        string t = to_string(s);
        res += t;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n + 1; i++)
    {
        int s;
        cin >> s;

        if (i == 1)
            first(s);
        else if (i > 1 and i <= n)
            other(s, n - i + 1);
        else if (i == n + 1)
            last(s);
    }

    cout << res << '\n';

    return 0;
}