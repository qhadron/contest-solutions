//http://wcipeg.com/problems/desc/acmtryouts1c
#include <cstdio>

using namespace std;

int T, H, W, N;

char grid[101][101];

#ifdef _DEBUG
#define _debug(x) x
#else
#define _debug(x)
#endif

int main() {
	_debug (freopen ("input.txt", "r", stdin);)

	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d %d", &H, &W, &N);
		getchar();//newline
		for (int i = 1; i <= H; ++i) {
			for (int j = 1; j <= W; ++j) {
				grid[i][j] = getchar();
				//printf("read %c\n",grid[i][j]);
			}
			getchar();//newline
		}
		_debug (
		for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
				putchar (grid[i][j]);
			}
			putchar ('\n');
		}
		)
		int x, y, treasure;
		y = treasure = 0;
		x = 1;
		char command;
		for (int i = 0; i < N; ++i) {
			command = getchar();

			_debug (printf ("[%d][%d]:%c -> %c\n", x, y, grid[x][y], command);)
			getchar();//newline
			if (command == 'L') {
				if (x - 1 > 0)
					if (grid[y][x - 1] != 'S') {
						--x;
					}
			} else if (command == 'R') {
				if (x + 1 <= W)
					if (grid[y][x + 1] != 'S') {
						++x;
					}
			} else {
				if (y + 1 <= H)
					if (grid[y + 1][x] != 'S') {
						++y;
					}
			}
			//collect
			if (grid[y][x] == 'T') {
				treasure += 1;
				grid[y][x] = 'E';
			}
			//fall
			while (y + 1 <= H && grid[y + 1][x] == 'E') {
				++y;
			}
		}
		printf ("%d\n", treasure);
	}
}
