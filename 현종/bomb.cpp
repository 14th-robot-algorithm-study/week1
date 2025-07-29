#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



void boom(char arr[][10], int N, int M, int K) {
	//방향
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };

	//맵의 크기 만큼 반복
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '@') {
				for (int k = 0; k < 4; k++)
				{
					//폭발 범위에 따른 처리
					for (int l = 1; l < K + 1; l++)
					{
						//다음 위치가 범위 내에 있다면
						if ((0 <= i + dy[k]) && (i + dy[k] < N) && (0 <= j + dx[k]) && (j + dx[k] < M)) {
							if (arr[i + l * dy[k]][j + l * dx[k]] == '_') {
								arr[i + l * dy[k]][j + l * dx[k]] = '%';
							}
							else if (arr[i + l * dy[k]][j + l * dx[k]] == '#')
								break;
						}
					}

				}
				arr[i][j] = '%';
			}
		}
	}
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	char arr[20][10];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	boom(arr, N, M, K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

}