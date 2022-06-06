#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
int n;
char s[N];

int work() //如果右括号比左括号多 2
{
    int cnt = 0, r = 0; // cnt:表示左括号数量-右括号数量
    for (int i = 0; i < n; i++)
        if (s[i] == '(') //遇到左括号：说明可改变的位置++
            cnt++;
        else //遇到右括号
        {
            cnt--;
            r++;
            if (cnt < 0) //右括号比左括号的多的情况：
            {
                cnt += 2;
                for (int j = i + 1; j < n; j++) //枚举后面的值：判断是否有矛盾
                    if (s[j] == '(')
                        cnt++;
                    else
                    {
                        cnt--;
                        if (cnt < 0) //表示不合法
                            return 0;
                    }
                return r; //表示合法：此时可改变的位置为 ： 此前右括号的数量
            }
        }

    return 0;
}

int main()
{
    scanf("%d%s", &n, s);

    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            l++;
        else
            r++;
    }

    if (r == l + 2) //如果右括号比左括号多 2
        printf("%d\n", work());
    else if (l == r + 2)
    {
        reverse(s, s + n); //转换为 上一种情况：因此 括号需要变化
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') //左括号变为 右括号
                s[i] = ')';
            else //右括号变为 左括号
                s[i] = '(';
        }
        printf("%d\n", work());
    }
    else
        puts("0");

    return 0;
}