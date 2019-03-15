#include <iostream>

using namespace std;
#define N 4
struct Point { int y, x; };

char value[10000000] = { 0, };
int arr[4][4] = { 0, };
Point dir[4] = { {0, 1},{1, 0}, {0, -1}, {-1, 0} };

void DFS(Point start, unsigned int num, int check) {
	if (check > 5) {
		value[num] = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = start.y + dir[i].y;
		int nx = start.x + dir[i].x;

		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			DFS({ ny,nx }, num * 10 + arr[ny][nx], check + 1);		
	}
}

int main()
{
	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++)
	{
		for (int j = 0; j < 10000000; j++) value[j] = 0;
		for (int j = 0; j < 16; j++) cin >> arr[j / N][j % N];
		for (int j = 0; j < 16; j++)
		{
			DFS({ j / N, j % N }, arr[j / N][j%N], 0);
		}
		
		int answer = 0;
		for (int j = 0; j < 10000000; j++)
			if (value[j]) {
	//			cout << j << endl;
				answer++;
			}
		cout << "#" << i << " " << answer << endl;
	}
	return 0;
}