/*
	미완료
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int numOfOrder, string *orderArr) {
  for(int i = 0; i < numOfOrder; i++) {
		string order = orderArr[i];
		
		vector<char> v;
		string ans = "";
		for(int j = 0; j < order.length(); j++) {
			if(order[j] == ')') {
				string temp = "";
				while(v.back() != '(') {
					temp += v.back();
					v.pop_back();
				}
				
				reverse(temp.begin(), temp.end());
				v.pop_back();
				
				if(isdigit(v.back())) {
					int num = v.back() - '0';
					for(int k = 0; k < num - 1; k++) {
						temp += temp;
					}

					v.pop_back();

					for(int k = 0; k < temp.length(); k++) {
						v.push_back(temp[k]);
					}
				} else {
					char c = v.back();
					v.pop_back();
					
					string s = "";
					for(int k = 0; k < temp.length(); k++) {
						s += c;
						s += temp[k];
					}
					
					temp = s;
				}
			}
			
			v.push_back(order[j]);
		}
		
		for(int j = 0; j < v.size(); j++) {
			ans += v[j];
		}
		
		cout << ans << "\n";
	}
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}