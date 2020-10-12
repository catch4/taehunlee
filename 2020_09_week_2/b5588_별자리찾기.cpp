#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int m, n;

vector<pair<int, int>> t;
vector<pair<int, int>> s;
unordered_map<string, int> pos;


bool cmp(const pair<int, int>&p1, const pair<int, int>&p2){
    return p1.first < p2.first;
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> m;
    t.resize(m);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        t[i] = {x, y};
    }

    sort(t.begin(), t.end(), cmp);

    cin >> n;
    s.resize(n);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s[i] = {x, y};
        pos[to_string(x) + "," + to_string(y)] = 1;
    }

    for(int i = 0; i < n; i++) {
        int x = s[i].first;
        int y = s[i].second;

        bool check = true;
        int prevX = t[0].first;
        int prevY = t[0].second;

        for(int j = 1; j < m; j++) {

            int diffX = t[j].first - prevX;
            int diffY = t[j].second - prevY;

            if(!pos[to_string(x + diffX) + "," + to_string(y + diffY)]) {
                check = false;
                break;
            }
        }

        if(check) {
            int diffX = -(t[0].first - s[i].first);
            int diffY = -(t[0].second - s[i].second);
            cout << diffX << " " << diffY;
            break;
        }
    }

    
    return 0;
}