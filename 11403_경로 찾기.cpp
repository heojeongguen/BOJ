#include <iostream>

using namespace std;
int input[101][101];
bool visited[101][101];
int n;

void fuc(int from, int to)
{
	input[from][to] = 1;
	visited[from][to] = true;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[from][i] && input[to][i])
			fuc(from, i);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		cin >> input[i][j];

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!visited[i][i] && input[i][j])
				fuc(i,  j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << input[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
