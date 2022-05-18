#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 110;
int st[N];
bool flag;
int n, d_max;
PII points[N];

//判断007跳到第i个鳄鱼上时，再跳一步能否到达岸上 
bool last_to_jump(int i) 
{
	if ((points[i].x + d_max >= 50) || (points[i].x - d_max <= -50) 
		|| (points[i].y + d_max >= 50) || (points[i].y - d_max <= -50))
	{
		return true;
	}
	return false;
}


//判断007能否从一个鳄鱼头上跳到另外一个鳄鱼头上
bool to_jump(int a, int b) 
{
	int x1 = pow(points[a].x - points[b].x, 2);
	int x2 = pow(points[a].y - points[b].y, 2);
	if (x1 + x2 <= d_max * d_max)
		return true;
	return false;
}

//判断007第一步能否跳到第一只鳄鱼上 
bool first_to_jump(int u) 
{
	int x1 = pow(points[u].x, 2);
	int x2 = pow(points[u].y, 2);

	if (x1 + x2 <= ((d_max + 7.5) * (d_max + 7.5))) return true;
	return false;
}


int dfs(int u) 
{
	st[u] = 1;
	if (last_to_jump(u)) {
		return flag = true;
	}

	for (int i = 0; i < n; i++) 
	{
		if (!st[i] && to_jump(u, i)) 
		{
			flag = dfs(i);
		}
	}
	return flag;
}

int main()
{
	scanf("%d%d", &n, &d_max);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &points[i].x, &points[i].y);
	if (d_max >= 42.5) puts("Yes");
	else 
	{
		for (int i = 0; i < n; i++)
		{
			if (!st[i] && first_to_jump(i)) 
			{
				dfs(i);
			}
		}
		if (flag)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
