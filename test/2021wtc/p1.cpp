#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> grade = {{"A+", 10}, {"A0", 9}, {"B+", 8}, {"B0", 7},
                          {"C+", 6}, {"C0", 5}, {"D+", 4}, {"D0", 3}, {"F", 0}};

int solution(vector<string> grades, vector<int> weights, int threshold) {
    int answer = grade[grades[0]] * weights[0];
    for(int i = 1; i < grades.size(); i++) {
        int score = grade[grades[i]] * weights[i];
        answer += score;
    }
    
    answer -= threshold;
    
    return answer;
}