/*
* 1. 아이디어
* - BFS를 수행하여 그래프 탐색
* 
* 2. 시간 복잡도
* - V = N(1 ~ 1,000)
* - E = M(0 ~ 499,500)
* - O(V + E) = O(1,000 + 499,500) = O(500,500) < 2억
* 
* 3. 사용 변수
* int : 정점의 개수, 간선의 개수, 간선의 양 끝 점, 출력 값
* int[][] : 그래프의 형태를 저장하기 위한 2차원 배열
* bool[] : 방문 여부를 확인하기 위한 1차원 배열
* queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 1001

int n, m, ans = 0;
int graph[MAX][MAX];
bool visited[MAX];
queue<int> que;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		graph[u][v] = 1;
		graph[v][u] = 1;
	}
}

void BFS(int node)
{
	visited[node] = true;
	que.push(node);

	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (int i = 1; i <= n; ++i)
		{
			if (graph[v][i] && !visited[i])
			{
				visited[i] = true;
				que.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			BFS(i);
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}