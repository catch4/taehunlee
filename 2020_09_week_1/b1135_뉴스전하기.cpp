#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 백준 1135 뉴스 전하기
// https://www.acmicpc.net/problem/1135

// 문제의 지문을 이해하기 어려워 결국 검색을 통해 해답을 얻었습니다.

/* 
이해하지 못한 부분
1. 각 상사의 번호만 가진 노드들 인데 그래프 형성이 어떻게 될 수 있는지? 
	- 민식이의 간접 부하 혹은 직접 부하라고는 되어있지만, 결국 DFS 할려면 그래프화 되어 있어야 할 것 같은데.. 어떻게 트리구조가 형성 되는건지 모르겠다. -1 0 1 1 2 2 3 3 3 이라고 한다면  -1, 0 까지는 민식, 민식이의 부하(첫번째 부하라고 지칭) 라는 그래프가 형성되는데 나머지 1부터 마지막 노드 까지는 민식이의 첫번째 부하와 어떻게 그래프 간선이 형성되는지..?
	: 문제에 다른 사원의 번호는 1번부터 시작한다고 했으므로 민식이 외의 주어지는 번호는 1번부터 50번까지 차례대로 증가하는 것으로 판단
2. 해답을 보니 핵심은 각 부하가 전화하는데 가장 오래 걸리는 순으로 정렬하는 것이라고 되어 있고, 백준 질문검색의 답에도 "각 부하가 한번에 뉴스를 많은지		부하에게 전달 해줄 수 있는 것을 체크" 라는 표현이 있었는데 문제의 지문에는 각 부하는 직속 부하에게 한번에 한사람씩만 전화를 하고 전화는 정확하게데		1분이 걸리는데 어떻게 한번에 뉴스를 많이 전달 해 줄 수 있는 상황이 되는건지 이해하지 못했다.
	: 간선마다 1분씩 걸린다는 의미가 아니라 1분째, 2분째의 뉴스를 전하고 있는 상황을 생각해보면 이해하기 쉽다.
 */

int N;
vector<vector<int> > tree(51);
vector<priority_queue<pair<int, int > > > q(51);
int dfs(int cur) {
	int ret = 0;
	
	for (int next : tree[cur]) {
		q[cur].push({1 + dfs(next),next});
	}
	
	int time = 0;
	while (!q[cur].empty()) {
		pair<int, int> p = q[cur].top(); q[cur].pop();
		int cost = p.first;
		
		ret = max(ret, cost + (time++));
	}

	return ret;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) { 
		int to;
		cin >> to;
		if (to == -1) continue;
		tree[to].push_back(i);
	}

	cout << dfs(0);
}