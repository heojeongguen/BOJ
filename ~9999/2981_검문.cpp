#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
vector<int> vec;
vector<int> ans;
vector<int> sub;
int GCD(int a, int b) {
	if (b < 0) return -1;

	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int main() {
     clock_t start, end; double result; start = clock(); // 수행 시간 측정 시작 



	int gcd;
	int lcm;
	int N;
	int data;
	int Min = 1;
	cin >> N;
	while (N--) {
		cin >> data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size()-1; i++) {
		sub.push_back(vec.at(i + 1) - vec.at(i));
	}
	sort(sub.begin(), sub.end());
	if (sub.size() <= 1) {
		gcd = sub.front();
	}
	else {
		gcd = GCD(sub.at(1), sub.at(0));
		for (int i = 2; i < sub.size(); i++) {
			gcd = GCD(sub.at(i), gcd);
		}
	}

     //cout << " GCD : " << gcd << endl;
		for (int i = 2; i <= gcd / 2; i++) {
			if (gcd % i == 0) {
				ans.push_back(i);
			}
		}
		ans.push_back(gcd);
	
	for (const auto &x : ans) {
		cout << x << " ";
	}
     end = clock(); //시간 측정 끝 
     result = (double)(end - start); // 결과 출력
     cout << "result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl; 
     //printf("%f", result / CLOCKS_PER_SEC); // 또는 
     cout << "result : " << result << " microseconds" << endl; // 또는 printf("%f", result); return 0;



}