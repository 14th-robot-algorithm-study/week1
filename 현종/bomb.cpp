#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



void boom(char arr[][10], int N, int M, int K) {
	//����
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };

	//���� ũ�� ��ŭ �ݺ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '@') {
				for (int k = 0; k < 4; k++)
				{
					//���� ������ ���� ó��
					for (int l = 1; l < K + 1; l++)
					{
						//���� ��ġ�� ���� ���� �ִٸ�
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