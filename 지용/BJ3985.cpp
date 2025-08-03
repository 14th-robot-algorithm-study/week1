#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Audience
{
	int audN;
	int lowerV;
	int upperV;
	int expect;
};

int main() {
	// 입력
	int l, n;
	cin >> l >> n;

	// 1 - based
	vector<int> rollCake(l + 1, 0); // 여기엔 auNum 저장
	vector<Audience> auVect(n);
	
	int maxExpectedValue = -1, maxExpectedIdx = -1;
	for (int i = 0; i < n; i++) {
		int p, k, expect;
		cin >> p >> k;
		expect = k - p + 1;
		auVect[i] = {i + 1, p, k, expect};

		// 예상 최대치 계산
		if (expect > maxExpectedValue) {
			maxExpectedValue = expect;
			maxExpectedIdx = i + 1;
		}
	}

	// 실제 배분
	vector<int> actual(n + 1, 0);
	for (auto& au : auVect) {
		for (int i = au.lowerV; i <= au.upperV; i++) {
			if (rollCake[i] == 0) {
				rollCake[i] = au.audN;
				actual[au.audN]++;
			}
		}
	}

	// 실제 최대 배분 계산
	int maxActualValue = -1, maxActuaIdx = -1;
	for (int i = 1; i <= n; i++) {
		if (actual[i] > maxActualValue) {
			maxActualValue = actual[i];
			maxActuaIdx = i;
		}
	}

	// 출력
	cout << maxExpectedIdx << '\n';
	cout << maxActuaIdx;

	return 0;
}
