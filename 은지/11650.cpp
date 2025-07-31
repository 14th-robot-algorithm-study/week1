#include <iostream>
#include <algorithm>
#include <vector>

struct point {
	int x;
	int y;
};

int main() {
	int N, x, y;
	std::cin >> N;

	std::vector<std::pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;
		v.push_back({ x, y });
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		std::cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}
