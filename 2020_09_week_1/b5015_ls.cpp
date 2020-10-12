#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 백준 5015 ls
// https://www.acmicpc.net/problem/5015

/* 
결국 풀지 못하고 검색을 통해 해답 확인 후 제출..
답을 분석해봐도 솔직히 이해하지 못했다.

체크 해볼 경우의 수가 
i는 패턴의 문자열 인덱스, j는 검색할 문자열 인덱스 일 때
1. 패턴 문자와 검사할 문자열의 문자가 매치 일 때, 다음 문자 검사(i + 1, j + 1)
2. 패턴 문자가 와일드카드 일 때 (i, j + 1), (i + 1, j) 둘중에 하나라도 매치되면 ok

위 와 같은 방법이 어떻게 문자 앞 뒤에 존재하는 와일드카드를 커버 할 수 있는지 아직 이해하지 못했다.
 */

int dp[101][101];

string N, P, S;

// i = 패턴 index, j = 파일명 index
bool match(int i, int j) {
    int& ret = dp[i][j];
	if (ret != -1) {
		return ret;
	}
	if (i < P.size() && j < S.size() && P[i] == S[j]) {
		return ret = match(i + 1, j + 1);
	}
	if (i == P.size()) {
		return ret = j == S.size();
	}
	if (P[i] == '*') {
		if ((j < S.size() && match(i, j + 1)) || match(i + 1, j)) {
			return ret = 1;
		}
	}
	return ret = 0;
}


int main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	cin >> P;
	int N;
	cin >> N;
	while (N--) {
		memset(dp, -1, sizeof(dp));
		cin >> S;
		if (match(0, 0))
			cout << S << endl;
	}
	return 0;
}