#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<char, int> m;
vector<char> people;

bool isFast(char tagger, int numOfQuickPlayers, char *namesOfQuickPlayers) {
	for(int i = 0; i < numOfQuickPlayers; i++) {
		if(tagger == namesOfQuickPlayers[i]) 
			return true;
	}
	return false;
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	m['A'] = 1;
	for(int i = 1; i < numOfAllPlayers; i++) {
		m[i + 65] = 0;
	}
	
	people.resize(numOfAllPlayers - 1);
	for(int i = 0; i < people.size(); i++) {
		people[i] = i + 66;
	}
	
	char cur = 'A';
	int position = 0;
	for(int i = 0; i < numOfGames; i++) {
		int game = numOfMovesPerGame[i];
		
		position += game;
		
		if(position < 0) {
			while(position < 0) {
				position += (numOfAllPlayers - 1);
			}
		}
		
		if(position > numOfAllPlayers - 1) {
			position %= (numOfAllPlayers - 1);
		}
		
		char tagger = people[position];
		
		if(isFast(tagger, numOfQuickPlayers, namesOfQuickPlayers)) {
			m[cur]++;
		} else {
			people[position] = cur;
			m[tagger]++;
			cur = tagger;
		}
	}
	
	for(int i = 0; i < people.size(); i++) {
		cout << people[i] << " " << m[people[i]] << "\n";
	}
	cout << cur << " " << m[cur] << "\n";
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}