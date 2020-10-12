#include <iostream>
#include <queue>
 
using namespace std;
 
const int MAX = 100001;
 
int N, K;
bool v[MAX];
 
int bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, N });
    v[N] = true;
    while (!q.empty()) {
        int time = q.top().first;
        int x = q.top().second;
        q.pop();
 
        if (x == K) return time;
 
        if (x * 2 < MAX && !v[x * 2]) {
            q.push({ time, x * 2 });
            v[x * 2] = true;
        }
 
        if (x + 1 < MAX && !v[x + 1]) {
            q.push({ time + 1, x + 1 });
            v[x + 1] = true;
        }
 
        if (x - 1 >= 0 && !v[x - 1]) {
            q.push({ time + 1 , x - 1 });
            v[x - 1] = true;
        }
    }
}
 
int main() {
    cin >> N >> K;
    cout << bfs() << "\n";
    return 0;
}