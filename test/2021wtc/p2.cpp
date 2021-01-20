#include <string>
#include <vector>

using namespace std;

vector<long long> solution(string s, string op) {
    vector<long long> answer;
    
    int length;
    for(int length = 1; length < s.length(); length++) {
        int left = stoi(s.substr(0, length));
        int right = stoi(s.substr(length));
        
        int num = 0;
        if(op == "+") 
            num = left + right;
        else if(op == "-")
            num = left - right;
        else if(op == "*")
            num = left * right;
        
        answer.push_back(num);
    }
    
    return answer;
}