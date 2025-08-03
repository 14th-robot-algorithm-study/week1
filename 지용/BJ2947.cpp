#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int woods[5]) {
	for (int i = 0; i < 5; i++) {
		cout << woods[i] << " ";
	}
	cout << '\n';
}

int main() {
	int woods[5];

	for (int i = 0; i < 5; i++) {
		cin >> woods[i];
	}

	bool sorted = false;

	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 4; i++) {
			if (woods[i] > woods[i + 1]) {
				swap(woods[i], woods[i + 1]);
				printArr(woods);
				sorted = false;
			}
		}
	}

	return 0;
}
