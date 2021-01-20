#include <string>
#include <vector>

using namespace std;

int solution(int money, vector<string> expected, vector<string> actual) { 
    int bet = 100;
    for(int i = 0; i < expected.size(); i++) {
        if(money == 0)
            break;
        
        if(expected[i] == actual[i]) {
            money += bet;
            bet = 100;
        } else {
            money -= bet;
            if(bet * 2 > money)
                bet = money;
            else
                bet *= 2;
        }
    }
    
    return money;
}