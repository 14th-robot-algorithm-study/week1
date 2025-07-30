#include<iostream>
#include<vector>

using namespace std;

struct Point {
	int y;
	int x;
};

// 미완성
// -> 풀이들 찾아보니까 이렇게 개노가다로 하는거 아님

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	// 상 하 좌 우
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<vector<int>> field;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int input;
				cin >> input;
				field[i].push_back(input);
			}
		}

		Point sp = { 0, 0 };
		int score = 0;

		for (int i = 0; i < field.size(); i++) {
			for (int j = 0; j < field[0].size(); j++) {
				// 시작점이 웜홀이거나 블랙홀이면 다음 좌표로
				if ((6 <= field[sp.y][sp.x] && field[sp.y][sp.x] <= 10) || field[sp.y][sp.x] == -1) {
					continue;
				}

				int ny;
				int nx;

				// 이동 로직
				for (int k = 0; k < 4; k++) {
					ny = sp.y + dy[k];
					nx = sp.x + dx[k];

					// 다음 이동 좌표가 블랙홀이면
					if (field[ny][nx] == -1) {
						cout << "#" << test_case << " " << score << endl;
						return 0;
					}

					// 다음 이동 좌표가 웜홀이면
					if (6 <= field[ny][nx] && field[ny][nx] <= 10) {
						for (int l = 0; l < field.size(); l++) {
							for (int m = 0; m < field[0].size(); m++) {
								if (field[ny][nx] == field[l][m]) {
									ny = l;
									nx = m;
								}
							}
						}
					}

					// 다음 이동 좌표가 빈공간이면
					if (field[ny][nx] == 0) {
						ny += dy[k];
						nx += dx[k];
					}

					// 다음 이동 좌표가 5번 블록이면
					if (field[ny][nx] == 5) {
						if (k == 0) {
							ny = sp.y + dy[1];
							nx = sp.x + dx[1];
							score++;
						}
						else if (k == 1) {
							ny = sp.y + dy[0];
							nx = sp.x + dx[0];
							score++;
						}
						else if (k == 2) {
							ny = sp.y + dy[3];
							nx = sp.x + dx[3];
							score++;
						}
						else {
							ny = sp.y + dy[2];
							nx = sp.x + dx[2];
							score++;
						}
					} // 다음 이동 좌표가 1 ~ 4번 블록이면
					else if (field[ny][nx] == 4) {
						if (k == 3) {
							k = 0;
						}
						else if (k == 1) {
							k = 3;
						}
						else if (k == 2) k = 3;
						else k = 1;

						ny = sp.y + dy[k];
						nx = sp.x + dx[k];
						score++;
					}
					else if (field[ny][nx] == 3) {
						if (k == 2) k = 3;
						else if (k == 1) k = 1;
						else if (k == 3) {
							k = 0;
						}
						else {
							k = 2;
						}

						ny = sp.y + dy[k];
						nx = sp.x + dx[k];
						score++;
					}
					else if (field[ny][nx] == 2) {
						if (k == 2) k = 1;
						else if (k == 0) k = 2;
						else if (k == 3) k = 2;
						else k = 0;

						ny = sp.y + dy[k];
						nx = sp.x + dx[k];
						score++;
					}
					else if (field[ny][nx] == 1) {
						if (k == 0) k == 1;
						else if (k == 3) k == 2;
						else if (k == 2) k = 1;
						else k = 2;

						ny = sp.y + dy[k];
						nx = sp.x + dx[k];
						score++;
					}

					// 벽을 만나면
					if (0 > ny || 0 > nx || ny >= n || nx >= n) {
						if (k == 0) k = 1;
						else if (k == 1) k = 0;
						else if (k == 2) k = 3;
						else k = 2;

						ny = sp.y + dy[k];
						nx = sp.x + dx[k];
						score++;
					}


				}


			}
		}
	}

	return 0;
}
