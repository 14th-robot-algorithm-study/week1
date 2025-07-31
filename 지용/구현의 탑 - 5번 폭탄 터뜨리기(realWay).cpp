#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<char>> field(n, vector<char>(m));

	// 상 하 좌 우
	// -> 오염되어선 안된다
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	// 폭탄 위치 저장
	vector<pair<int, int>> bombs; 


	// 입력받기
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			field[i][j] = row[j];
			if (field[i][j] == '@') bombs.push_back({i, j});
		}
	}


	// 폭탄 로직
	for (auto &bomb : bombs) {
		int y = bomb.first;
		int x = bomb.second;
		field[y][x] = '%';
		for (int d = 0; d < 4; d++) {
			for (int r = 1; r <= k; r++) {
				int ny = y + dy[d] * r;
				int nx = x + dx[d] * r;

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (field[ny][nx] == '#') break;
				field[ny][nx] = '%';
			}
		}
	}

	//cout << '\n'; // 디버깅용

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << field[i][j];
		}
		cout << '\n';
	}

	return 0;
}
