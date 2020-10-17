#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;

// 백준 18513 샘터
// https://www.acmicpc.net/problem/18513

int N, K;
int water[100001]; // 샘터
int houses[100001]; // 집 
unordered_map<int, bool> visited;

ll BFS() {
    queue<pair<int, int> > q;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        q.push({water[i], water[i]});
        visited[water[i]] = true;
    }

    while(!q.empty()) {
        int w = q.front().first;
        int source = q.front().second;
        q.pop();

        int next = -1;

        for(int i = 0; i < 2; i++) {
            next *= -1;
            int nextDirection = w + next;

            if(visited[nextDirection]) continue;

            visited[nextDirection] = true;
            K--;
            sum += abs(source - nextDirection);

            if(!K) {
                return sum;
            }

            q.push({nextDirection, source});
        }
    }
    return 0;
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int s;
        cin >> s;
        water[i] = s;
    }

    cout << BFS();
    
    return 0;
}