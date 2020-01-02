#include <iostream>
#include <string>
using namespace std;
// 공통 LSC 문제인데 
// 일단 그냥 풀고 넘어가자...
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	string str;
	string input;
	cin >> str;
	int size = str.size();

	for (int i = 0; i < M; i++) {
		cin >> input;

		bool find = false;
		int index = 0;

		for (int st = 0; st < input.size(); st++) {
			if (find) break;
			else index = 0;
				
			if (str[index] == input[st]) {
				index++;
				for (int j = st + 1; j < input.size(); j++) {
					if (str[index] == input[j]) {
						index++;
						if (index == size) find = true;
					}
				}
			}

		}
		if (find) cout << "true" << endl;
		else cout << "false" << endl;
	}
}