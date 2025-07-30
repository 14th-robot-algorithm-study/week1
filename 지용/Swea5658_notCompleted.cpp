#include <iostream>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// 16진수 문자열 -> 10진수 변환 함수
int hexToDec(const string& hexStr) {
    int val = 0;
    for (char c : hexStr) {
        val *= 16;
        if (c >= '0' && c <= '9') val += c - '0';
        else val += c - 'A' + 10;
    }
    return val;
}

int main() {
    int T; cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int N, K; cin >> N >> K;
        string s; cin >> s;

        deque<char> dq(s.begin(), s.end());
        int len = N / 4;

        set<int> uniqueNums;

        for (int rotate = 0; rotate < len; ++rotate) {
            // 4등분된 문자열 추출
            for (int i = 0; i < 4; ++i) {
                string part = "";
                for (int j = 0; j < len; ++j) {

                    // i는 4등분한 조각 번호(0 ~ 3)
                    // len은 한 조각 길이(n / 4)
                    // j는 각 조각 내부에서 몇 번째 문자인가?
                    // n은 전체 문자열 길이
                    int idx = (i * len + j) % N; // 원형이기에 (0 ~ n - 1) 범위 안에서 반복
                    part += dq[idx];
                }
                uniqueNums.insert(hexToDec(part));
            }
            // 한 칸 회전 (오른쪽 회전)
            dq.push_front(dq.back());
            dq.pop_back();
        }

        // 내림차순 정렬
        vector<int> results(uniqueNums.begin(), uniqueNums.end());
        sort(results.begin(), results.end(), greater<int>());

        cout << "#" << test_case << " " << results[K - 1] << "\n";
    }

    return 0;
}
