#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

struct Microbe {
	pair<int, int> yx;
	int size;
	int dir; // 상(1) 하(2) 좌(3) 우(4)
};

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m, k;
		cin >> n >> m >> k;

		vector<Microbe> microbes(k);

		for (int i = 0; i < k; i++) {
			int y, x, size, dirN;
			cin >> y >> x >> size >> dirN;

			microbes[i].yx = make_pair(y, x);
			microbes[i].size = size;
			microbes[i].dir = dirN;
		}

		// 상 하 좌 우 이동
		int dy[4] = { -1, 1, 0, 0 };
		int dx[4] = { 0, 0, -1, 1 };

		while (m > 0) {
			m--;

			vector<pair<int, int>> curYxList;

			for (int i = 0; i < k; i++) {
				// 1. 다음 이동 좌표가 빨간 영역이면, floor(size/2) && dir 정반대
				int ny = microbes[i].yx.first;
				int nx = microbes[i].yx.second;

				if (microbes[i].dir == 1) {
					ny += dy[0];
					nx += dx[0];
				}
				else if (microbes[i].dir == 2) {
					ny += dy[1];
					nx += dx[1];
				}
				else if (microbes[i].dir == 3) {
					ny += dy[2];
					nx += dx[2];
				}
				else if (microbes[i].dir == 4) {
					ny += dy[3];
					nx += dx[3];
				}

				if (0 == ny || 0 == nx || (n - 1) == ny || (n - 1) == nx) {
					microbes[i].size = floor(microbes[i].size / 2);

					if (microbes[i].dir == 1) microbes[i].dir = 2;
					else if (microbes[i].dir == 2) microbes[i].dir = 1;
					else if (microbes[i].dir == 3) microbes[i].dir = 4;
					else if (microbes[i].dir == 4) microbes[i].dir = 3;
				}

				microbes[i].yx = { ny, nx };
			}

			// 여기 구현 GPT 봤음
			// 2. 만약 미생물들의 위치 좌표가 겹치게 되면, 가장 size가 큰 미생물 군집이 다른 군집들 흡수
			map<pair<int, int>, vector<int>> positions;

			for (int i = 0; i < microbes.size(); i++) {
				Microbe m = microbes[i];

				// 같은 좌표에 몇 번째 microbe들이 있는지 저장
				positions[m.yx].push_back(i);
			}

			for (auto& entry : positions) {
				if (entry.second.size() > 1) { // entry.second - pair의 두번쨰 값(key= value 중 value)
					int maxSize = 0, sumSize = 0, maxIdx = -1;
					for (int idx : entry.second) {
						sumSize += microbes[idx].size;

						if (microbes[idx].size > maxSize) {
							maxSize = microbes[idx].size;
							maxIdx = idx;
						}
					}

					// maxIdx에 합치고 나머지는 제거 or 0 처리
					microbes[maxIdx].size = sumSize;
					for (int idx : entry.second) {
						if (idx != maxIdx) microbes[idx].size = 0;
					}
				}
			}
			 
			// size가 0인 미생물 제거
			microbes.erase(
				remove_if(microbes.begin(), microbes.end(), [](const Microbe& m) {
					return m.size == 0;
					}),
				microbes.end()
			);
		}

		int totalSize = 0;
		for (auto& m : microbes) {
			totalSize += m.size;
		}

		cout << "#" << test_case << " " << totalSize << endl;
	}

	return 0;
}
