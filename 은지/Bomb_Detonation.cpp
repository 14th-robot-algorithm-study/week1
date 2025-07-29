#include <iostream>
#include <vector>

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;

	bool up    = true;
	bool down  = true;
	bool right = true;
	bool left  = true;

	std::vector<std::vector<char>> arr(N, std::vector<char>(M));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> arr[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '@') {
				arr[i][j] = '%';
				for (int k = 0; k < K+1; k++) {
					if (j + k < M && down && arr[i][j + k] != '@') {
						if (arr[i][j + k] != '#') {
							arr[i][j + k] = '%';
						}
						else {
							down = false;
						}
					}
					
					if (j - k >= 0 && up && arr[i][j - k] != '@') {
						if (arr[i][j - k] != '#') {
							arr[i][j - k] = '%';
						}
						else {
							up = false;
						}
					}
					
					if (i + k < N  && right && arr[i + k][j] != '@') {
						if (arr[i + k][j] != '#') {
							arr[i + k][j] = '%';
						}
						else {
							right = false;
						}
					}
	
					if (i - k >= 0 && left && arr[i - k][j] != '@') {
						if (arr[i - k][j] != '#') {
							arr[i - k][j] = '%';
						}
						else {
							left = false;
						}
					}
				}
			}

			up    = true;
			down  = true;
			right = true;
			left  = true;
		}
	}


	for (int i = 0; i < N; i++) {
		for (char x : arr[i]) {
			std::cout << x;
		}
		std::cout << std::endl;
	}

	return 0;
}
