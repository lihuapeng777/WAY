#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int st[N]; //状态数组

int main()
{
    scanf("%d%d", &n, &m);

    int res1 = 0;
    int res2 = 0;

    while (m--)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);

        if (op == 0) //砍树
        {
            for (int i = l; i <= r; i++)
            {
                if (st[i] == 0)//如果从未被砍过->此时被砍,当前没有树
                    st[i] = 1;
                else if (st[i] == 2)//之前被砍过,但种上了树苗->此时被砍,当前没有树
                    st[i] = 3, res2++;
            }
        }
        else if (op == 1)//植树
        {
            for (int i = l; i <= r; i++)
            {
                if (st[i] == 1)//之前被砍->此时被种植上树苗
                    st[i] = 2;
                else if (st[i] == 3)//种上树苗后被砍,当前没有树->此时被种植上树苗
                    st[i] = 2;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (st[i] == 2)
            res1++;
    }

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}
