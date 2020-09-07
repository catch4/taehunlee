#include <iostream>
#include <map>

using namespace std;

// 백준 4358 생태학
// https://www.acmicpc.net/problem/4358

/* 
TRIE 알고리즘으로 풀 수 있다라는 힌트를 얻고 시작하긴 했으나,
익숙하지 않아서인지.. 시도해보진 못하고
다른 솔루션을 생각하다가
map으로 카운팅만 해도 충분히 풀릴 문제 같아서 시도해보았는데
해결되었다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    map<string, int> map;
    string tree;
    int count = 0;

    while(getline(cin, tree)) {
        map[tree]++;
        count++;
    }

    cout.setf(ios::fixed);
    cout.precision(4);
    for (auto const& entry: map){
        double p = (double) entry.second / (double) count * 100;
        cout << entry.first << " " << p << endl;
    }

    return 0;
}

