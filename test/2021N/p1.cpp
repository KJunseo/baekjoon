#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n, vector<int> p, vector<int> c) {
    string answer = "";
    int failDay = 0;
    int cost = 100;
    double totalCost = 0;
    double day = 0;

    for(int i = 0; i < n; i++) {

        if(failDay == 3) break;

        if(p[i] >= c[i]) {
            totalCost += (c[i] * cost);

            if(i+1 < n) 
                p[i+1] += (p[i]-c[i]);

            failDay = 0;
            cost = 100;
        } else {
            failDay++;

            if(i+1 < n)
                p[i+1] += p[i];

            cost/=2;
        }

        day++;
    }

    double average = totalCost / day;

    average = (round(average * 100)) / 100.0;

    answer = to_string(average);
    answer = answer.substr(0, answer.length()-4);

    return answer;
}