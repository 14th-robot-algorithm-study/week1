#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int origin = n; // 처음 입력 저장

	int nArr[2] = {0}, cycleLen = 0;
	do {
		if (n < 10) {
			nArr[0] = 0;
			nArr[1] = n;
		}
		else {
			nArr[0] = (n / 10);
			nArr[1] = (n % 10);
		}
		int plusDigits = nArr[0] + nArr[1];

		nArr[0] = nArr[1];
		nArr[1] = plusDigits % 10;
		cycleLen++;
		n = (nArr[0] * 10 + nArr[1]);
	} while (n != origin);

	cout << cycleLen;

	return 0;
}
