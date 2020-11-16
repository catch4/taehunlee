#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
unordered_map<string, int> map;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    // 들어가는 순으로 map에 기록
    string car;
    for(int i = 0; i < N; i++)  {
        cin >> car;
        map[car] = i;
    }

    int count = 0;
    
    // 나가는 순이 들어가는 순보다 빠르다면 추월?
    for(int i = 0; i < N; i++)  {
        cin >> car;
        if(map[car] > i) count++;
    }

    cout << count;
    
    return 0;
}