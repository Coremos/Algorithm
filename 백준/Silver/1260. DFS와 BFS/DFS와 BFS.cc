#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;
int V;

vector<int> vertices[1001];
bool visited[10001];

void DFS(int number)
{
	visited[number] = true;
	cout << number << ' ';
	for (auto i : vertices[number])
	{
		if (visited[i]) continue;
		DFS(i);
	}
}

void BFS(int number)
{
	queue<int> vertexQueue;
	vertexQueue.push(number);
	visited[number] = true;

	while (!vertexQueue.empty())
	{
		number = vertexQueue.front();
		vertexQueue.pop();
		cout << number << ' ';

		for (auto i : vertices[number])
		{
			if (visited[i]) continue;
			visited[i] = true;
			vertexQueue.push(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		vertices[a].push_back(b);
		vertices[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(vertices[i].begin(), vertices[i].end());
	}

	DFS(V);
	cout << '\n';
	for (int i = 1; i <= N; i++)
	{
		visited[i] = false;
	}
	BFS(V);

	return 0;
}