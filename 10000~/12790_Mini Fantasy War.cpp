#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int HP, MP, atk, def, HHP , MMP, aatk , ddef;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> HP >> MP >> atk >> def >>  HHP >> MMP >> aatk >> ddef;
		HP = max(1, HP + HHP);
		MP = max(1, MP + MMP);
		atk = max(0, atk + aatk);
		def = def + ddef;
		cout << HP + 5 * MP + atk * 2 + 2 * def << endl;
	}
}