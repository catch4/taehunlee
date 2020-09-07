#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 프로그래머스 60062 외벽 점검
// https://programmers.co.kr/learn/courses/30/lessons/60062


/**
 * 
 * 몇시간동안 삽질 끝에 결국 해결되지 않아서 다음 비디오를 보고 해답만 겨우 이해했다.
 * 결국 풀지 못했다.
 * https://www.youtube.com/watch?v=4O-ckCvYx0s 
 * 
**/

 
// weak가 [1, 3, 4, 9, 10] 이렇게 주어 질 때
// 각 시작점과 끝점의 차이를 쉽게 계산하기 위해 외벽의 정북 방향 지점(0) 부터의 절대값으로 각 점의 위치를 변경해준다.
// 0을 시작점으로 보고 기준으로 봤을 때 2바퀴 째에선 1(13), 3(15), 4(16)... 로 볼 수 있다.
// 10에서 다음 1까지의 거리를 체크하기 위해선 1을 13으로 만들어놓는 것이 편하기 때문이다.
vector<int> swapEndPoint(vector<int> origin, int start, int n) {
    if(start == 0) return origin;

    vector<int> temp;
    int endPoint = origin[0] + n;

    for(int i = start; i < origin.size(); i++) {
        temp.push_back(origin[i]);
    }

    for(int i = 0; i < start; i++) {
        temp.push_back(origin[i] + n);
    }

    return temp;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;

    sort(dist.begin(), dist.end());

    do {
        // 1, 3, 4, 9, 10 weak
        // [3, 5, 7], [3, 7, 5], [5, 3, 7], [5, 7, 3], [7, 3, 5], [7, 5, 3] dist의 순열
        for(int i = 0; i < weak.size(); i++) {
            vector<int> temp = swapEndPoint(weak, i, n);
            int idx = 0;

            // 현재 점검에 투입된 친구가 첫번째 취약지점에서 본인의 최대치까지 이동 할 수 있는 지점
            int curPoint = temp[0] + dist[idx];
            bool flag = 0;

            for(int j = 1; j < temp.size(); j++) {
                // 다음 취약 지점이, 현재 친구의 최대치까지 이동 할 수 있는 지점보다 멀다면
                if(temp[j] > curPoint) {
                    // 모든 친구를 투입 했는데도 모든 취약지점을 점검하지 못하는 상황 일 때
                    if(idx + 1 == dist.size()) {
                        flag = 1;
                        break;
                    }

                    // 현재 친구가 다음 취약지점 포인트까지 갈 수 없으니, 다음 친구를 투입해본다.
                    curPoint = temp[j] + dist[++idx];
                }
            }

            // "모든 친구를 투입 했는데도 모든 취약지점을 점검하지 못하는 상황 일 때" <- (flag = true)를 제외하고 
            // 투입했던 친구를 세본다.
            if(!flag) answer = min(answer, idx + 1);
        }
        // 친구를 투입한 순서에 따라 최소 투입인원수 결과가 달라질 수 있기 때문에
        // 순열을 이용해 모든 경우의 수를 대입해본다.
    } while (next_permutation(dist.begin(), dist.end()));

    if(answer == 9) return -1;

    return answer;
}

int main() {
    int n = 12;
    vector<int> weak = {1, 5, 6, 10};
    vector<int> dist = {1, 2, 3, 4};

    int result = solution(n, weak, dist);

    cout << result << endl;

    return 0;
}