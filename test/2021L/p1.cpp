#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> boxes) {    
    map<int, int> numOfProduct;
    for(int i = 0; i < boxes.size(); i++) {
        numOfProduct[boxes[i][0]]++;
        numOfProduct[boxes[i][1]]++;
    }
    
    int ret = boxes.size();
    map<int, int>::iterator it;
    for(it = numOfProduct.begin(); it != numOfProduct.end(); it++) {
        if(it->second >= 2) ret--;
    }
    
    return ret;
}