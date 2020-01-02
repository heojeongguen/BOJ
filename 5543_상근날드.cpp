#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int sang, joong, ha, cola, sida;
	cin >> sang;
	cin >> joong;
	cin >> ha;
	cin >> cola;
	cin >> sida;
	int burger = min({ sang, joong ,ha });
	int beverage = min(cola, sida);
	cout << burger + beverage - 50 << endl;

}