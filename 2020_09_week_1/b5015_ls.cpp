#include <iostream>
#include <cstring>
#include <vector>
// #include <stack>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <algorithm>

using namespace std;

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