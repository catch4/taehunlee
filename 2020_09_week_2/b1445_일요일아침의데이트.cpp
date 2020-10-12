#include <iostream>
#include <algorithm>
#include <queue>    
#include <cstring>

using namespace std;

// 백준 1445 일요일 아침의 데이트
// 출처: https://sejinik.tistory.com/202

int n, m,Sx,Sy,Fx,Fy;
int map[55][55];
int d[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
 
bool inner(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}
 
void changeCost(int x, int y) {
    map[x][y] = 5000;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!map[nx][ny]) map[nx][ny] = 1;
    }
}
 
int main() {
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; scanf(" %1c", &c);
            if (c == 'S') Sx = i, Sy = j;
            if (c == 'F') Fx = i, Fy = j;
            if (c == 'g') changeCost(i, j);
        }
    }
    map[Sx][Sy] = map[Fx][Fy] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ 0,{Sx,Sy} });
 
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
 
        if (d[x][y] != -1) continue;
        d[x][y] = cost;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inner(nx, ny)) continue;
            if (d[nx][ny] != -1) continue;
            int ncost = -cost - map[nx][ny];
            pq.push({ ncost,{nx,ny} });
        }
    }
    cout << d[Fx][Fy]/ 5000 << " " << d[Fx][Fy] % 5000;
}