#include <iostream>

using namespace std;

struct Point { int y, x; };

Point dir[4] = { {0, 1},{1, 0}, {0, -1}, {-1, 0} }; //¢¯A, ¨ú¨¡¡¤¢®, ¢¯¨­, A¡×

int index = 0;
char memory[20][20] = { 0, };
char arr[20][20] = { 0, }; //char
int R, C;
int single_memory = 0;

bool DFS(Point cur, bool* result) {

	if (memory[cur.y][cur.x] > 15) { //end cond.
		*result = false;
		return true;
	}
	memory[cur.y][cur.x] += 1;
	char v = arr[cur.y][cur.x]; //CoAc ¢¬i¡¤E¨úi
	if (v < 58 && v > 47)
	{
		single_memory = v - 48;
	}
	else
	{
		switch (v) {
		case '<':
			index = 2;
			break;
		case '>':
			index = 0;
			break;
		case '^':
			index = 3;
			break;
		case 'v':
			index = 1;
			break;
		case '_':
			index = single_memory == 0 ? 0 : 2;
			break;
		case '-':
			single_memory = (single_memory + 16 - 1) % 16;
			break;
		case '+':
			single_memory = (single_memory + 1) % 16;
			break;
		case '?':
			for (int i = 0; i < 4; i++) {
				int ny = (cur.y + R + dir[i].y) % R;
				int nx = (cur.x + C + dir[i].x) % C;
				char ch = false;
				while (!ch || !*result) {
					ch = DFS({ ny, nx }, result);
					ny = (ny + R + dir[index].y) % R;
					nx = (nx + C + dir[index].x) % C;
				}
				if (*result)	return true;
			}
			return true;
		case '|':
			index = single_memory == 0 ? 1 : 3;
			break;
		case '@':
			*result = true;
			return true;
		}
	}
	return false;
}

int main()
{
	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++)
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++) arr[i][j] = memory[i][j] = 0;
		index = 0;
		single_memory = 0;
		cin >> R >> C;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> arr[i][j];

		Point cur = { 0,0 };
		bool result, ch=false;
		while (!ch) {
			ch = DFS(cur, &result);
			cur.y = (cur.y + R + dir[index].y) % R;
			cur.x = (cur.x + C + dir[index].x) % C;
		}
		cout << "#" << t << " ";
		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}