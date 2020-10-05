#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string doc, word;
    getline(cin, doc);
    getline(cin, word);

    int ret = 0;
    if(doc.size() < word.size()) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < doc.size();) {
        bool check = true;

        for(int j = 0; j < word.size(); j++) {
            if(doc[i + j] != word[j]) {
                check = false;
                break;
            }
        }

        if(check) {
            ret++;
            i += word.size();
        } else {
            i++;
        }
    }

    cout << ret << "\n";

    return 0;
}