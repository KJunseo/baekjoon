#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int cnt;
vector<pair<int, int> > v;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void fill() {
	vector<pair<int, int> > temp = v;
	sort(temp.begin(), temp.end(), compare);
	
	int base = temp[0].second;
	for(int i = 1; i < temp.size(); i++) {	
		int start, end;
		if(base > temp[i].second) {
			start = temp[i].second + 1;
			end = base;
		} else {
			start = base + 1;
			end = temp[i].second;
		}
		
		for(int j = start; j < end; j++) {
			int numOfCement = temp[i].first - v[j].first;
			if(v[j].first < temp[i].first) {
				v[j].first += numOfCement;
				cnt += numOfCement;
			}
		}
		
		base = temp[i].second;
	}
}

void solution(int day, int width, int **blocks) {
	v.resize(width);
	
  for(int i = 0; i < day; i++) {
		for(int j = 0; j < width; j++) {
			 v[j].first += blocks[i][j];
			 v[j].second = j;
		}
		
		fill();
	}

	printf("%d\n", cnt);
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}
