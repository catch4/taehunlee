#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int N;
unordered_map<int, int> mapX;
unordered_map<int, int> mapY;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int count = 0;

    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if(!mapX[x] && !mapY[y]) {
            mapX[x] = 1;
            mapY[y] = 1;
            count++;
            if(count > 3) {
                break;
            }
        }
    }

    cout << (count > 3 ? 0 : 1);
    
    return 0;
}