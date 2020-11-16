#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
priority_queue<pair<int, int> > pq;
vector<int> graph[320001];
int indegree[32001];
vector<int> answer;

void topology_sort() {
    priority_queue<int> pq;
    // 위상정렬 시작 1번 문제부터 N번 문제까지
    for (int i = 1; i <= N; i++) {
        // 진입 차수가 0인 문제 문제번호 큐에 삽입
        if(!indegree[i]) pq.push(-i);
    }

    while(!pq.empty()) {
        int p = -pq.top();
        pq.pop();
        // 진입차수가 0이 됐다라는 것은 우선 풀어야 하는 문제라는 것을 뜻함
        // 답 벡터에 추가
        answer.push_back(p);

        // 큐에서 꺼낸 정점에 연결된 모든 간선을 제거하고 진입 차수가 0이 되었다면 다시 큐에 삽입
        for (int i = 0; i < graph[p].size(); i++) {
            int node = graph[p][i];
            indegree[node]--;

            if(!indegree[node]) pq.push(-node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // 4(v) 2(v) 일 경우
        // 4번이 2번보다 먼저 푸는 것이 좋으므로 4 -> 2로 가는 간선을 뜻함
        // 그러므로 정점 2의 진입 차수를 하나 증가
        indegree[v]++;
    }

    topology_sort();

    int size = answer.size();

    for(int i = 0; i < size; i++) {
        cout << answer[i];
        if(i < size - 1) cout << ' ';
    }
    
    return 0;
}