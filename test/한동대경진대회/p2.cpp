#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	map<int, int> products;
	for(int i = 0; i < n; i++) {
		int product;
		scanf("%d", &product);
		products[product]++;
	}

	int answer = 0;
	map<int, int>::iterator it;
	while(true) {
		int cnt = 0;
		for(it = products.begin(); it != products.end(); it++) {
			if(it->second == 0)
				continue;
			products[it->first]--;
			cnt++;
		}
		if(cnt > 1) 
			answer += (cnt - 1);
		if(cnt <= 1)
			break;
	}

	printf("%d\n", answer);
	
	return 0;
}
