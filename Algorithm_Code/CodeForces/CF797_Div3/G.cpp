// https://zhuanlan.zhihu.com/p/525876150

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int l;
    mutable int v;
    bool operator<(const node &o) const { return l < o.l; }
};
set<node> st;
void add(int id, int x)
{
    st.insert({id, x});
    auto it = st.find({id, x});
    it->v = x; //修改数值
               //如果前面的一段的数，小于当前的数，那么当前的数就不需要保留，和前面合成为一段即可
    if (it != st.begin() && prev(it)->v <= x)
    {
        st.erase(it);
        return;
    }
    // 否则，我们就遍历set，删除后面所有大于x的段
    while (next(it) != st.end() && x <= next(it)->v)
    {
        st.erase(next(it));
    }
}
const int MAXN = 1e5 + 10;
int n, m, a[MAXN], d, k;
void slove()
{
    st.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], add(i, a[i]);
    vector<int> ans;
    while (m--)
    {
        cin >> k >> d;
        a[k] -= d;
        add(k, a[k]);
        ans.push_back(st.size());
    }
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        slove();
    return 0;
}