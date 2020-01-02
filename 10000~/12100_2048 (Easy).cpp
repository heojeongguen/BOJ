#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, D;
int mmax = 0;
vector<vector<int> > up(vector<vector<int> >  vec);
vector<vector<int> > down(vector<vector<int> >  vec);
vector<vector<int> > left(vector<vector<int> >  vec);
vector<vector<int> > right(vector<vector<int> >  vec);

void fuc(vector<vector<int> > vec, int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mmax = max(vec[i][j], mmax);
			}
		}
	}
	else {
		fuc(up(vec), cnt + 1);
		fuc(down(vec), cnt + 1);
		fuc(right(vec), cnt + 1);
		fuc(left(vec), cnt + 1);
	}
}

vector<vector<int> > up(vector<vector<int> >  vec) {
	for (int i = 0; i < N; i++) {
		pair<int, int> v1 = { 0,0 };
		pair<int, int> v2 = { 0,0 };
		for (int j = 0; j < N; j++) {
			if (vec[j][i] != 0) {
				if (v1.first == 0) {
					v1.first = vec[j][i];
					v1.second = j;
				}
				else if (v1.first != 0) {
					v2.first = vec[j][i];
					v2.second = j;
					if (v1.first == v2.first) {
						vec[v1.second][i] = v1.first + v2.first;
						vec[v2.second][i] = 0;
						v1.first = 0;
						v1.second = 0;
						v2.first = 0;
						v2.second = 0;
					}
					else {
						v1.first = v2.first;
						v1.second = v2.second;
						v2.first = 0;
						v2.second = 0;
					}
				}
			}
		}
		for (int j = 0; j < N; j++) {
			if (vec[j][i] != 0) {
				for (int z = j - 1; z >= 0; z--) {
					if (vec[z][i] != 0) break;
					else {
						vec[z][i] = vec[z+1][i];
						vec[z+1][i] = 0;
					}
				}
			}
		}
	}
	return vec;
}

vector<vector<int> > down(vector<vector<int> >  vec) {
	for (int i = 0; i < N; i++) {
		pair<int, int> v1 = { 0,0 };
		pair<int, int> v2 = { 0,0 };
		for (int j = N - 1; j >= 0; j--) {
			if (vec[j][i] != 0) {
				if (v1.first == 0) {
					v1.first = vec[j][i];
					v1.second = j;
				}
				else if (v1.first != 0) {
					v2.first = vec[j][i];
					v2.second = j;
					if (v1.first == v2.first) {
						vec[v1.second][i] = v1.first + v2.first;
						vec[v2.second][i] = 0;
						v1.first = 0;
						v1.second = 0;
						v2.first = 0;
						v2.second = 0;
					}
					else {
						v1.first = v2.first;
						v1.second = v2.second;
						v2.first = 0;
						v2.second = 0;
					}
				}
			}
		}
		for (int j = N-1; j >= 0; j--) {
			if (vec[j][i] != 0) {
				for (int z = j + 1 ; z < N; z++) {
					if (vec[z][i] != 0) break;
					else {
						vec[z][i] = vec[z - 1][i];
						vec[z - 1][i] = 0;
					}
				}
			}
		}
	}
	return vec;
}

vector<vector<int> > left(vector<vector<int> >  vec) {
	for (int i = 0; i < N; i++) {
		pair<int, int> v1 = { 0,0 };
		pair<int, int> v2 = { 0,0 };
		for (int j = 0; j < N; j++) {
			if (vec[i][j] != 0) {
				if (v1.first == 0) {
					v1.first = vec[i][j];
					v1.second = j;
				}
				else if (v1.first != 0) {
					v2.first = vec[i][j];
					v2.second = j;
					if (v1.first == v2.first) {
						vec[i][v1.second] = v1.first + v2.first;
						vec[i][v2.second] = 0;
						v1.first = 0;
						v1.second = 0;
						v2.first = 0;
						v2.second = 0;
					}
					else {
						v1.first = v2.first;
						v1.second = v2.second;
						v2.first = 0;
						v2.second = 0;
					}
				}
			}
		}
		for (int j = 0; j < N; j++) {
			if (vec[i][j] != 0) {
				for (int z = j - 1; z >= 0; z--) {
					if (vec[i][z] != 0) break;
					else {
						vec[i][z] = vec[i][z + 1];
						vec[i][z + 1] = 0;
					}
				}
			}
		}
	}
	return vec;

}

vector<vector<int> > right(vector<vector<int> > vec) {
	for (int i = 0; i < N; i++) {
		pair<int, int> v1 = { 0,0 };
		pair<int, int> v2 = { 0,0 };
		for (int j = N-1; j >= 0; j--) {
			if (vec[i][j] != 0) {
				if (v1.first == 0) {
					v1.first = vec[i][j];
					v1.second = j;
				}
				else if (v1.first != 0) {
					v2.first = vec[i][j];
					v2.second = j;
					if (v1.first == v2.first) {
						vec[i][v1.second] = v1.first + v2.first;
						vec[i][v2.second] = 0;
						v1.first = 0;
						v1.second = 0;
						v2.first = 0;
						v2.second = 0;
					}
					else {
						v1.first = v2.first;
						v1.second = v2.second;
						v2.first = 0;
						v2.second = 0;
					}
				}
			}
		}
		for (int j = N - 1; j >= 0; j--) {
			if (vec[i][j] != 0) {
				for (int z = j +1 ; z < N; z++) {
					if (vec[i][z] != 0) break;
					else {
						vec[i][z] = vec[i][z - 1];
						vec[i][z - 1] = 0;
					}
				}
			}
		}
	}
	return vec;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	vector<vector<int> > vec(N, vector<int>(N, 0));
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			cin >> vec[i][j];
		}
	}

	fuc(vec, 0);
	cout << mmax << endl;
}