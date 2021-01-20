#include <string>
#include <vector>

using namespace std;

vector<int> temp;

int multi() {
    int ret = 1;
    int zeroCnt = 0;
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] == 0) {
            zeroCnt++;
            continue;
        }
        ret *= temp[i];
    }

    if(zeroCnt == temp.size()) ret = 0;

    return ret;
}

void convert(int num, int k) {
    int remainder = num % k;
    num /= k;

    if(num > 0) convert(num, k);

    temp.push_back(remainder);
}

vector<int> solution(int N) {
    vector<int> answer;
    int notation;
    int maxValue = 0;

    for(int i = 2; i < 10; i++) {
        temp.clear();
        convert(N, i);

        int val = multi();

        if(val >= maxValue) {
            maxValue = multi();
            notation = i;
        }
    }

    answer.push_back(notation);
    answer.push_back(maxValue);

    return answer;
}