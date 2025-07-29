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
	int dir; // ��(1) ��(2) ��(3) ��(4)
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

		// �� �� �� �� �̵�
		int dy[4] = { -1, 1, 0, 0 };
		int dx[4] = { 0, 0, -1, 1 };

		while (m > 0) {
			m--;

			vector<pair<int, int>> curYxList;

			for (int i = 0; i < k; i++) {
				// 1. ���� �̵� ��ǥ�� ���� �����̸�, floor(size/2) && dir ���ݴ�
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

			// ���� ���� GPT ����
			// 2. ���� �̻������� ��ġ ��ǥ�� ��ġ�� �Ǹ�, ���� size�� ū �̻��� ������ �ٸ� ������ ���
			map<pair<int, int>, vector<int>> positions;

			for (int i = 0; i < microbes.size(); i++) {
				Microbe m = microbes[i];

				// ���� ��ǥ�� �� ��° microbe���� �ִ��� ����
				positions[m.yx].push_back(i);
			}

			for (auto& entry : positions) {
				if (entry.second.size() > 1) { // entry.second - pair�� �ι��� ��(key= value �� value)
					int maxSize = 0, sumSize = 0, maxIdx = -1;
					for (int idx : entry.second) {
						sumSize += microbes[idx].size;

						if (microbes[idx].size > maxSize) {
							maxSize = microbes[idx].size;
							maxIdx = idx;
						}
					}

					// maxIdx�� ��ġ�� �������� ���� or 0 ó��
					microbes[maxIdx].size = sumSize;
					for (int idx : entry.second) {
						if (idx != maxIdx) microbes[idx].size = 0;
					}
				}
			}

			// size�� 0�� �̻��� ����
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