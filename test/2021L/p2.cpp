#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    deque<int> dq;
    vector<int> waiting;
    vector<bool> visit(ball.size()+1, false);
    
    for(int i = 0; i < ball.size(); i++) {
        dq.push_back(ball[i]);
    }
    
    for(int i = 0; i < order.size(); i++) {
        int pop = order[i];
        
        if(pop == dq.back()) {
            dq.pop_back();
            answer.push_back(pop);
        } else if(pop == dq.front()) {
            dq.pop_front();
            answer.push_back(pop);
        } else {
            waiting.push_back(pop);
            continue;
        }
        
        while(true) {
            if(dq.empty()) break;
            
            int back = dq.back();
            int front = dq.front();
            
            for(int j = 0; j < waiting.size(); j++) {
                
                if(visit[waiting[j]]) continue;
                
                if(waiting[j] == back) {
                    visit[waiting[j]] = true;
                    dq.pop_back();
                    answer.push_back(waiting[j]);
                } else if(waiting[j] == front) {
                    visit[waiting[j]] = true;
                    dq.pop_front();
                    answer.push_back(waiting[j]);
                }
            }
            
            if(dq.back() == back && dq.front() == front) break;
        }
    }
    
    return answer;
}