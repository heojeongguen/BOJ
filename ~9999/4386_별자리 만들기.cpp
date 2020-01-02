#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

class Info {
public:
	int x;
	double cost;
	Info(int x, double cost) {
		this->x = x;
		this->cost = cost;
	}
	bool operator < (const Info & b) const {
		return this->cost < b.cost;
	}
	bool operator > (const Info & b) const {
		return this->cost > b.cost;
	}
};

bool visit[101];
int N;
vector<pair<double, double>> vec;

double getDist(pair<double, double> a, pair<double, double> b) {
	return sqrt( (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double mst(){
	double ret = 0;
	priority_queue<Info, vector<Info>, greater<> > pq;
	pq.push(Info(0,0));
	while (!pq.empty()) {
		int x = pq.top().x;
		double cost = pq.top().cost; 
		pq.pop();
		if (visit[x]) continue;
		ret += cost;
		visit[x] = true;
		for (int i = 0; i < N; i++) {
			if (i == x) continue;
			int y = i;
			double ycost = getDist(vec[x], vec[y]);
			if (visit[y]) continue;
			pq.push(Info(y, ycost));
		}
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	 cin >> N;
	for(int i = 0 ; i < N; i++){
		double x, y; cin >> x >> y;
		vec.push_back({ x,y });
	}
	cout << mst() << endl;
}