#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int n;
int dp[MAX][MAX];
int matrix[MAX][2];

void init() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
}

int calc(int l, int r) {
	if(l == r)
		return 0;
	
	int value = 987654321;
	
	if(dp[l][r] != -1)
		return dp[l][r];
	
	for(int i = l; i < r; i++) 
		value = min(value, calc(l, i) + calc(i + 1, r) + (matrix[l][0] * matrix[i][1] * matrix[r][1]));
	
	dp[l][r] = value;
	return dp[l][r];
}

bool impossible() {
	int r = matrix[0][0];
	int c = matrix[0][1];
	for(int i = 1; i < n; i++) {
		if(matrix[i][0] == c) {
			c = matrix[i][1];
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	
	for(int tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		
		init();
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 2; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		
		if(impossible()) {
			printf("%d\n", -1);
			continue;
		}
		
		printf("%d\n", calc(0, n - 1));
	}
	return 0;
}
