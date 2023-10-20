#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Position
{
	int X;
	int Y;
	int Z;
} Position;

const int DIRECTION[6][3] = { { -1, 0, 0 }, { 1, 0, 0 }, { 0, -1, 0 }, { 0, 1, 0 }, { 0, 0, -1 }, { 0, 0, 1 } };

int Box[100][100][100];
queue<Position> Que;

int main()
{
	int M, N, H;
	int answer = -1;
	cin >> M >> N >> H;

	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				cin >> Box[x][y][z];
				if (Box[x][y][z] == 1)
				{
					Que.push({ x, y, z });
				}
			}
		}
	}

	while (!Que.empty())
	{
		answer++;
		int size = Que.size();
		for (int i = 0; i < size; i++)
		{
			Position current = Que.front();
			Que.pop();

			for (int direction = 0; direction < 6; direction++)
			{
				Position pos = { current.X + DIRECTION[direction][0], current.Y + DIRECTION[direction][1], current.Z + DIRECTION[direction][2] };
				if (pos.X >= 0 && pos.X < M && pos.Y >= 0 && pos.Y < N && pos.Z >= 0 && pos.Z < H && Box[pos.X][pos.Y][pos.Z] == 0)
				{
					Que.push(pos);
					Box[pos.X][pos.Y][pos.Z] = 1;
				}
			}
		}
	}

	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (Box[x][y][z] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer;

	return 0;
}