#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 프로그래머스 17684 압축
// https://programmers.co.kr/learn/courses/30/lessons/17684

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;

    int dictCount = 26;

    for(int i = 0; i < dictCount; i++) {
        char w = 'A' + i;
        dict[string(1, w)] = i + 1;
    }


    int i = 0;
    string word = "";
    string prev = "";

    while(i < msg.size()) {
        word += msg[i];
        if(!dict.count(word)) {
            dict[word] = ++dictCount;
            answer.push_back(dict[prev]);
            word = "", word += msg[i];
        }
        i++;
        prev = word;
    }
    answer.push_back(dict[prev]);

    return answer;
}

int main() {
    solution("KAKAO");

    return 0;
}