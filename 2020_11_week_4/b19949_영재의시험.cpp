#include <iostream>
#include <string>
#include <vector>

using namespace std;

int test[10];
int answers[10];
int count_ = 0;

void dfs(int depth) {
    if(depth == 10) {
        int s = 0;
        for(int i = 0; i < 10; i++) {
            s += (test[i] == answers[i]) ? 1 : 0;
            if(s >= 5) {
                count_++;
                break;
            }
        }
        return;
    }

    for(int i = 1; i <= 5; i++) {
        if(depth >= 2 && (answers[depth - 1] == i && answers[depth - 2] == i)) continue;
        answers[depth] = i;
        dfs(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 10; i++) {
        cin >> test[i];
    }

    dfs(0);
    cout << count_;
    
    return 0;
}