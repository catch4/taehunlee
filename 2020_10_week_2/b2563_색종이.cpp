#include <iostream>
#include <string>

using namespace std;

const int MAX = 101;

int wp[MAX][MAX];

int main() {
    int p;
    int cnt = 0;
    cin >> p;
    while(p--) {
        int x, y;
        cin >> x >> y;
        for(int i = y + 10; i > y; i--) {
            for(int j = x; j < (x + 10); j++) {
                if(wp[i][j] == 0) {
                    wp[i][j] = 1;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << "\n";
    
    return 0;
}