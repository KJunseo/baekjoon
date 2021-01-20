#include <string>
#include <vector>

using namespace std;

vector<string> divide(string num, int i) {
    vector<string> ret;
    
    ret.push_back(num.substr(0, i));
    ret.push_back(num.substr(i, num.length()-i));
    
    return ret;
}

vector<int> calc(int n, int count) {
    vector<int> ret;
    string num = to_string(n);

    int minSum = 987654321;
    for(int i = 0; i < num.length()-1; i++) {
        vector<string> v = divide(num, i+1);
        
        if(v[0][0] == '0' || v[1][0] == '0') continue;
        
        int sum = stoi(v[0]) + stoi(v[1]);
        if(minSum > sum) minSum = sum;
    }
    
    if(minSum < 10) {
        ret.push_back(count);
        ret.push_back(minSum);
    } else {
        ret = calc(minSum, count+1);
    }

    return ret;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    if(n < 10) {
        answer.push_back(0);
        answer.push_back(n);
        return answer;
    }
    
    answer = calc(n, 1);

    return answer;
}