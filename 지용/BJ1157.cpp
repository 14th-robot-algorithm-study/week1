#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string a;
	cin >> a;

	int bucket[26] = { 0 };
	vector<char> maxElements;

	for (int i = 0; i < a.length(); i++) {
		if ('a' <= a[i] && a[i] <= 'z') {
			a[i] -= 32;
		}
		bucket[a[i] - 'A']++;
	}

	// 최빈값 찾기
	int maxN = *max_element(bucket, bucket+26);

	for (int i = 0; i < 26; i++) {
		if (bucket[i] == maxN) {
			maxElements.push_back((char)(i + 'A'));
		}
	}

	if (maxElements.size() == 1) {
		cout << maxElements.back();
	}
	else {
		cout << "?";
	}

	return 0;
}
