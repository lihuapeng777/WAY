#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5 + 10;

int n;
int h[N];
stack<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int last = 0;                           //储存上一个高度
        while (!s.empty() && h[s.top()] < h[i]) //判断栈不为空且栈顶元素小于等于当前元素时
        {
            //在删掉一个较矮的障碍物前，先计算它与前一障碍物的储水量
            //两障碍物间雨水容量 = 两障碍物高度差 * 两障碍物距离
            res += (h[s.top()] - last) * (i - s.top() - 1);
            last = h[s.top()];
            s.pop();
        }

        if (!s.empty())
            res += (h[i] - last) * (i - s.top() - 1);
        s.push(i); //当前障碍物入栈
    }

    cout << res << endl;

    return 0;
}