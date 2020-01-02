#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned long long pow(int n, int e) {
	unsigned long long ret = 1;
	unsigned long long tmp = n;
	while (e > 0) {
		if (e % 2 == 1) {
			ret = ret * tmp % 125;
		}
		tmp = tmp * tmp % 125;
		e /= 2;
	}
	return ret % 125;
}

int main() {
	//for (int i = 0; i < 2018; i++) {
	//	cout << 17 << "^" << i << " : " << pow(17, i) << endl;
	//}


	cout << 13 << "^" << 17 << " : " << pow(13, 17) << endl;

	/*for (int i = 0; i 
	
	<= 9; i++) {
		cout << i << "^" << 2008 << " % 10 : " << pow(i, 2008) << endl;

	}*/

}