#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_HEIGHT = 1000;

int N, M, H;
int dp[51][MAX_HEIGHT + 1];
int students[51][10];

// 백준 18427 함께 블록 쌓기
// https://www.acmicpc.net/problem/18427

// 아직 못 풀었음

int main() {

    cin >> N >> M >> H;


    for(int i = 0; i <= N; i++) {
        string blocks;
        getline(cin, blocks);

        if(!blocks.size()) continue;

        int block;
        int idx = 0;
        for(istringstream numbers_iss(blocks); numbers_iss >> block;) {
            students[i][idx++] = block;
        }
    }

    for(int i = 0; i < M; i++) {
        dp[1][students[1][i]] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            int currentBlock = students[i][j];
            if(!currentBlock) break;

            for(int h = 1; h <= H; h++) {
                if(currentBlock > h) {
                    if(!dp[i][h]) {
                        dp[i][h] = dp[i - 1][h];
                    }
                } else if(currentBlock == h) {
                    if(!dp[i][h]) {
                        dp[i][h] = dp[i - 1][h] + 1;
                    } else {
                        dp[i][h] += 1;
                    }
                } else {
                    if(!dp[i][h]) {
                        dp[i][h] = dp[i-1][h] + dp[i - 1][h - currentBlock];
                    } else {
                        dp[i][h] = dp[i][h] + dp[i - 1][h - currentBlock];
                    }
                }
            }
        }
    }

    cout << dp[N][H] % 10007 << "\n";
    return 0;
}