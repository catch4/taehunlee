#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
unordered_map<string, int> map;
string out_car[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    string car;
    for(int i = 0; i < N; i++)  {
        cin >> car;
        map[car] = i;
    }

    
    for(int i = 0; i < N; i++)  {
        cin >> car;
        out_car[i] = car;
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(map[out_car[i]] > map[out_car[j]]) {
                count++;
                break;
            }
        }
    }


    cout << count;
    
    return 0;
}