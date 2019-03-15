#include <iostream>

using namespace std;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main()
{
	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++)
	{
		int N;
		cin >> N;
		int **arr = new int*[N];
		for (int j = 0; j < N; j++) arr[j] = new int[N];

		int y = 0, x = -1;
		int dir_index = 0;

		for (int j = 0; j < N*N; j++) arr[j / N][j%N] = 0;

		for (int j = 1; j <= N * N; j++)
		{
			y += dir[dir_index][0];
			x += dir[dir_index][1];

			arr[y][x] = j;
			if (y + dir[dir_index][0] < 0 || y + dir[dir_index][0] >= N || x + dir[dir_index][1] < 0 || x + dir[dir_index][1] >= N || arr[y + dir[dir_index][0]][x + dir[dir_index][1]])
				dir_index = (dir_index + 1) % 4;
		}

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				cout << arr[j][k] << " ";
			cout << endl;
		}

		for (int j = 0; j < N; j++) delete[] arr[j];
		delete[] arr;
	}
	return 0;
} 